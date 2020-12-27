#include <iostream>
using namespace std;

int dx[4]= {1,-1, 0,0};
int dy[4]= {0,0,1,-1};
int map[22][22]={10,};
struct shark{
  int x;
  int y;
  int size=2;
  int eat=0;
  int time=0;
  void eatfish(int fish_x, int fish_y){
    eat++;
    if (eat == size){
      size++;
      eat=0;
    }

    
    time+= Astar(fish_x,fish_y);
    x= fish_x;
    y=fish_y;
  }
  int caltime(int fish_x, int fish_y){//여기만 수정하면 됨 A*알고리즘 적용하면 풀림 ㅅㅂ

    int temp_time;
    temp_time= ((fish_x>x)?(fish_x-x):(x-fish_x)) + ((fish_y>y)?fish_y-y:y-fish_y);
    return temp_time;
  }
  int Astar(int fish_x, int fish_y){
    int spent=0;
    while(fish_x !=x && fish_y !=y){
      int min_index=0;
      int min_time=caltime(fish_x+dx[0], fish_y+dy[0]);
      for(int i =1; i<4; i++){
        
        if(map[fish_y+dy[i]][fish_x+dx[i]]>size)continue;
        int ttemp = caltime(fish_x+dx[i],fish_y+dy[i]);
        if(ttemp<min_time){
          min_time = ttemp;
          min_index= i;
        }

      }
      fish_x+=dx[min_index];
      fish_y+=dy[min_index];
      spent++;
    }

    return spent;
  }
};
struct fish{
  int x;
  int y;
  int size;
};

int main() {
  int N;
  int f_index=0;
  struct shark shrk;
  struct fish f[401];
  cin>>N;
  
  for(int y=1; y<=N; y++  ){
    for (int x=1; x<=N; x++){
      int temp;
      cin>>temp;
      if (temp ==9){
        shrk.x= x;
        shrk.y= y;
        map[y][x]=9;
      }
      else if (temp>0){
        f[f_index].x= x;
        f[f_index].y=y;
        f[f_index].size = temp;
        f_index++;
        map[y][x]=temp;
      }
      else if (temp==0)map[y][x]=0;
    }
  }//y가 작을수록 위임 x가 작을수록 왼쪽

  while (1){
    bool callMom = true;
    int min_dist =450;
    int min_index =450;
    for (int i=0; i<f_index; i++){
      if(f[i].size==0)continue;
      if(f[i].size<shrk.size){
        callMom=false;
        int spent= shrk.Astar(f[i].x, f[i].y);
        if(min_dist> spent){
          min_dist = spent;
          min_index = i;
        }
        else if(spent == min_dist){

          if(f[i].y<f[min_index].y){
            min_index = i;
          }
          else if(f[i].y==f[min_index].y){
            if(f[i].x<f[min_index].x){
              min_index = i;
            }
          }
        }

      }
    }
    
    if (callMom)break;
    shrk.eatfish(f[min_index].x,f[min_index].y);
    f[min_index].size =0; // 먹음
  }

  cout<<shrk.time;

}
