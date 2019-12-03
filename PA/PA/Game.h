#pragma once
#include "Stage.h"
#include "Block.h"
#include "Map.h"

class Game
{
public:
	enum { // PLUS 열거형 > 윗줄부터 0부터 1씩 더해가면서 자동할당됨.
		BLACK, /* 0 : 까망 */
		DARK_BLUE, /* 1 : 어두운 파랑 */
		DARK_GREEN, /* 2 : 어두운 초록 */
		DARK_SKY_BLUE, /* 3 : 어두운 하늘 */
		DARK_RED, /* 4 : 어두운 빨강 */
		DARK_VOILET, /* 5 : 어두운 보라 */
		DARK_YELLOW, /* 6 : 어두운 노랑 */
		GRAY, /* 7 : 회색 */
		DARK_GRAY, /* 8 : 어두운 회색 */
		BLUE, /* 9 : 파랑 */
		GREEN, /* 10 : 초록 */
		SKY_BLUE, /* 11 : 하늘 */
		RED, /* 12 : 빨강 */
		VOILET, /* 13 : 보라 */
		YELLOW, /* 14 : 노랑 */
		WHITE, /* 15 : 하양 */
	};

	int level;
	int ab_x, ab_y; //화면중 블럭이 나타나는 좌표의 절대위치
	int block_shape, block_angle, block_x, block_y;
	int next_block_shape;
	int score;
	int lines;
	char total_block[21][14]; //화면에 표시되는 블럭들
	Stage stage_data[10];
	Map map;
	Block Block;
public:
	Game();
	~Game();
	void starttetris();
	int init(); //각종변수 초기화
	int show_cur_block(int shape, int angle, int x, int y); //진행중인 블럭을 화면에 표시한다
	int erase_cur_block(int shape, int angle, int x, int y); //블럭 진행의 잔상을 지우기 위한 함수
	int show_total_block(); //쌓여져있는 블럭을 화면에 표시한다.
	int show_next_block(int shape);
	int make_new_block(); //return값으로 block의 모양번호를 알려줌
	int strike_check(int shape, int angle, int x, int y); //블럭이 화면 맨 아래에 부닥쳤는지 검사 부닥치면 1을 리턴 아니면 0리턴
	int merge_block(int shape, int angle, int x, int y); //블럭이 바닥에 닿았을때 진행중인 블럭과 쌓아진 블럭을 합침
	int block_start(int shape, int* angle, int* x, int* y); //블럭이 처음 나올때 위치와 모양을 알려줌
	int move_block(int* shape, int* angle, int* x, int* y, int* next_shape); //게임오버는 1을리턴 바닥에 블럭이 닿으면 2를 리턴
	int show_gameover();
	int show_gamestat();
	int show_logo();
	int input_data();
	int check_full_line();
};

