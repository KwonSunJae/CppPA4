#pragma once
#include "Map.h"
#include "Block.h";
class Game
{
public:

	Map game_map[10];
	Block block;
	enum { // PLUS ������ > ���ٺ��� 0���� 1�� ���ذ��鼭 �ڵ��Ҵ��.
		BLACK, /* 0 : ��� */
		DARK_BLUE, /* 1 : ��ο� �Ķ� */
		DARK_GREEN, /* 2 : ��ο� �ʷ� */
		DARK_SKY_BLUE, /* 3 : ��ο� �ϴ� */
		DARK_RED, /* 4 : ��ο� ���� */
		DARK_VOILET, /* 5 : ��ο� ���� */
		DARK_YELLOW, /* 6 : ��ο� ��� */
		GRAY, /* 7 : ȸ�� */
		DARK_GRAY, /* 8 : ��ο� ȸ�� */
		BLUE, /* 9 : �Ķ� */
		GREEN, /* 10 : �ʷ� */
		SKY_BLUE, /* 11 : �ϴ� */
		RED, /* 12 : ���� */
		VOILET, /* 13 : ���� */
		YELLOW, /* 14 : ��� */
		WHITE, /* 15 : �Ͼ� */
	};

	int level; // ���� ����
	int ab_x, ab_y; //ȭ���� ������ ��Ÿ���� ��ǥ�� ������ġ
	int block_shape, block_angle, block_x, block_y; // ���� ���, ���� ����, ���� x, y��ǥ
	int next_block_shape; //���� ����
	int score; // ����
	int lines; // ���� ���� ��
	int is_gameover = 0;

	void play_game();
	void init();
	int show_cur_block(int shape, int angle, int x, int y); //�������� ������ ȭ�鿡 ǥ���Ѵ�
	int erase_cur_block(int shape, int angle, int x, int y); //���� ������ �ܻ��� ����� ���� �Լ�
	int show_total_block(); //�׿����ִ� ������ ȭ�鿡 ǥ���Ѵ�.
	int show_next_block(int shape);
	int make_new_block(); //return������ block�� ����ȣ�� �˷���
	int strike_check(int shape, int angle, int x, int y); //������ ȭ�� �� �Ʒ��� �δ��ƴ��� �˻� �δ�ġ�� 1�� ���� �ƴϸ� 0����
	int merge_block(int shape, int angle, int x, int y); //������ �ٴڿ� ������� �������� ������ �׾��� ������ ��ħ
	int block_start(int shape, int* angle, int* x, int* y); //������ ó�� ���ö� ��ġ�� ����� �˷���
	int move_block(int* shape, int* angle, int* x, int* y, int* next_shape); //���ӿ����� 1������ �ٴڿ� ������ ������ 2�� ����
	void show_gameover();
	void show_gamestat();
	void show_logo();
	void input_data();
	void check_full_line();
};
