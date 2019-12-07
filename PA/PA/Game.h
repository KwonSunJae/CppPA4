#pragma once
#include "Map.h"
#include "Console.h"
#include "Block.h"
#include "Player.h"

class Game
{
public:

	Map game_map[8];
	Console console;
	Block block;
	bool help_skills[8] = { 0, };
	bool is_used[8] = { 0, };

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

	int level; // 현재 레벨
	int ab_x, ab_y; //화면중 블럭이 나타나는 좌표의 절대위치
	int block_shape, block_angle, block_x, block_y; // 블럭 모양, 블럭 각도, 블럭 x, y좌표
	int next_block_shape; //다음 블럭
	int score; // 점수
	int lines; // 현재 없앤 줄
	int is_gameover = 0;
	int sk2_time = 0;
	int sk5_time = 0;
	int speed_temp = 0;
	int shadow_x, shadow_y;

	Game();
	bool play_game();
	void init();
	int show_cur_block(int shape, int angle, int x, int y); //진행중인 블럭을 화면에 표시한다
	int erase_cur_block(int shape, int angle, int x, int y); //블럭 진행의 잔상을 지우기 위한 함수
	int show_total_block(); //쌓여져있는 블럭을 화면에 표시한다.
	int show_next_block(int shape);
	int make_new_block(); //return값으로 block의 모양번호를 알려줌
	int strike_check(int shape, int angle, int x, int y); //블럭이 화면 맨 아래에 부닥쳤는지 검사 부닥치면 1을 리턴 아니면 0리턴
	int shadow_strike_check(int shape, int angle, int x, int y);
	int oneblock_strike_check(int x, int y);
	int merge_block(int shape, int angle, int x, int y); //블럭이 바닥에 닿았을때 진행중인 블럭과 쌓아진 블럭을 합침
	void block_start(int shape, int* angle, int* x, int* y); //블럭이 처음 나올때 위치와 모양을 알려줌
	int move_block(int* shape, int* angle, int* x, int* y, int* next_shape); //게임오버는 1을리턴 바닥에 블럭이 닿으면 2를 리턴
	int move_shadow_block(int* shape, int* angle, int* x, int* y);
	void erase_shadow_block(int shape, int angle, int x, int y);
	void show_gameover();
	void show_gamestat();
	void show_logo();
	void input_data();
	void check_full_line();
};
