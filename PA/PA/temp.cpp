//#include "Game.h"
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <Windows.h>
//#include <conio.h>
//
//using namespace std;
//
//Game::Game() {
//	//전역변수 초기화
//	level = 0;
//	lines = 0;
//	score = 0;
//	ab_x = 5;
//	ab_y = 1;
//
//	srand((unsigned)time(NULL));
//
//
//	game_map[0].speed = 40;
//	game_map[0].stick_rate = 20;
//	game_map[0].clear_line = 1;
//	game_map[1].speed = 38;
//	game_map[1].stick_rate = 18;
//	game_map[1].clear_line = 20;
//	game_map[2].speed = 35;
//	game_map[2].stick_rate = 18;
//	game_map[2].clear_line = 20;
//	game_map[3].speed = 30;
//	game_map[3].stick_rate = 17;
//	game_map[3].clear_line = 20;
//	game_map[4].speed = 25;
//	game_map[4].stick_rate = 16;
//	game_map[4].clear_line = 20;
//	game_map[5].speed = 20;
//	game_map[5].stick_rate = 14;
//	game_map[5].clear_line = 20;
//	game_map[6].speed = 15;
//	game_map[6].stick_rate = 14;
//	game_map[6].clear_line = 20;
//	game_map[7].speed = 10;
//	game_map[7].stick_rate = 13;
//	game_map[7].clear_line = 20;
//}
//void PrintBlock(int x, int y) {
//	int tempy = y;
//	Console::gotoxy(x, tempy++);
//	cout << "v rvvvvvvvLvviBM";
//	Console::gotoxy(x, tempy++);
//	cout << "7 ''''''''''''Ml";
//	Console::gotoxy(x, tempy++);
//	cout << "7.7777777777:B@l";
//	Console::gotoxy(x, tempy++);
//	cout << "r.:ri;iri;ii.XBl";
//	Console::gotoxy(x, tempy++);
//	cout << "7.iiiiiiiii:.S@l";
//	Console::gotoxy(x, tempy++);
//	cout << "r.:i:i:i:i::.X@l";
//	Console::gotoxy(x, tempy++);
//	cout << "r .......... 2@l";
//	Console::gotoxy(x, tempy++);
//	cout << "i.0MZW08ZWZZ2@Ml";
//
//}
//void PrintErase(int x, int y) {
//	int tempy = y;
//	Console::gotoxy(x, tempy++);
//	cout << "v rvvvvvvvLvviBM";
//	Console::gotoxy(x, tempy++);
//	cout << "7             @l";
//	Console::gotoxy(x, tempy++);
//	cout << "7             @l";
//	Console::gotoxy(x, tempy++);
//	cout << "r             Bl";
//	Console::gotoxy(x, tempy++);
//	cout << "7             @l";
//	Console::gotoxy(x, tempy++);
//	cout << "r             @l";
//	Console::gotoxy(x, tempy++);
//	cout << "r             @l";
//	Console::gotoxy(x, tempy++);
//	cout << "i.0MZW08ZWZZ2@Ml";
//}
//void PrintVoid(int x, int y) {
//	int tempy = y;
//	Console::gotoxy(x, tempy++);
//	cout << "                ";
//	Console::gotoxy(x, tempy++);
//	cout << "                ";
//	Console::gotoxy(x, tempy++);
//	cout << "                ";
//	Console::gotoxy(x, tempy++);
//	cout << "                ";
//	Console::gotoxy(x, tempy++);
//	cout << "                ";
//	Console::gotoxy(x, tempy++);
//	cout << "                ";
//	Console::gotoxy(x, tempy++);
//	cout << "                ";
//	Console::gotoxy(x, tempy++);
//	cout << "                ";
//
//}
//
//bool Game::play_game()
//{
//	const char EXT_KEY = 0xffffffe0;
//	const char KEY_LEFT = 0x4b;
//	const char KEY_RIGHT = 0x4d;
//	const char KEY_UP = 0x48;
//	const char KEY_DOWN = 0x50;
//
//
//	Console::setTetrisGame();
//	string check;
//
//
//	while (1)
//	{
//		int i;
//		if (sk2_time != 0 && time(NULL) - sk2_time > 5) {
//			game_map[level].speed = speed_temp;
//			sk2_time = 0;
//		}
//		if (sk5_time != 0 && time(NULL) - sk5_time > 5) {
//			sk5_time = 0;
//		}
//		init();
//		show_total_block();// PLUS 플레이 화면에서 테두리 출력.
//		block_shape = make_new_block();
//		next_block_shape = make_new_block();
//		show_next_block(next_block_shape);
//		block_start(block_shape, &block_angle, &block_x, &block_y);
//		show_gamestat();
//		for (i = 1; 1; i++)
//		{
//			if (level == 1 || level == 7) {
//				int s = rand() % 30000;
//				if (game_map[level].skill == 0 && s < 10) {
//					game_map[level].fast();
//					game_map[level].skill = 1;
//				}
//				else if (game_map[level].skill == level && time(NULL) - game_map[level].time_now > 5) {
//					game_map[level].fast();
//					if (level == 1) game_map[level].speed = 38;
//					else game_map[level].speed = 10;
//				}
//			}
//			if (level == 2 || level == 7) {
//				int s = rand() % 10000;
//				if (s < 10) {
//					game_map[level].line_up();
//					show_total_block();
//				}
//			}
//			if (level == 3 || level == 7) {
//				int s = rand() % 30000;
//				if (game_map[level].skill == 0 && s < 10) {
//					game_map[level].skill = 3;
//				}
//			}
//			if (level == 4 || level == 7) {
//				int s = rand() % 30000;
//				if (game_map[level].skill == 0 && s < 10) {
//					game_map[level].invisible();
//					game_map[level].skill = 4;
//				}
//				else if (game_map[level].skill == level && time(NULL) - game_map[level].time_now > 5) {
//					game_map[level].invisible();
//				}
//			}
//			if (level == 5 || level == 7) {
//				int s = rand() % 30000;
//				if (game_map[level].skill == 0 && block_shape < 8 && s < 10) {
//					game_map[level].random_block();
//					block.gen_random_block();
//					game_map[level].skill = 5;
//				}
//			}
//			if (level == 6 || level == 7) {
//				int s = rand() % 30000;
//				if (s < 10) {
//					game_map[level].turn();
//					show_total_block();
//					check_full_line();
//
//				}
//			}
//			if (_kbhit())
//			{
//				int j;
//				char keytemp = _getche();
//				for (j = 49; j <= 56; j++) {
//					if (keytemp == j && help_skills[j - 49] && !is_used[j - 49]) {
//						is_used[j - 49] = true;
//						break;
//					}
//				}
//				if (j != 57) {
//					switch (j) {
//						console.Color(RED);
//						console.gotoxy(50, 50);
//						cout << j << j << j << j << endl;
//					case 49: {
//						next_block_shape = 1;
//						show_next_block(1);
//						break;
//					}
//					case 50: {
//						sk2_time = time(NULL);
//						speed_temp = game_map[level].speed;
//						game_map[level].speed = 40;
//						break;
//					}
//					case 51: {
//						game_map[level].delete_line();
//						break;
//					}
//					case 52: {
//						next_block_shape = 0;
//						show_next_block(0);
//						break;
//					}
//					case 53: {
//						sk5_time = time(NULL);
//						break;
//					}
//					}
//				}
//				if (keytemp == 122) {//z
//					lines = game_map[level].clear_line;
//				}
//				if (keytemp == 27) {
//					console.Color(RED);
//
//					if (level == 1) {
//						if (game_map[level].skill == 0) {
//							game_map[level].fast();
//							game_map[level].skill = 1;
//
//						}
//						else if (game_map[level].skill == level && time(NULL) - game_map[level].time_now > 5) {
//							game_map[level].fast();
//							if (level == 1) game_map[level].speed = 38;
//							else game_map[level].speed = 10;
//						}
//					}
//					if (level == 2) {
//						game_map[level].line_up();
//						show_total_block();
//					}
//					if (level == 3) {
//						if (game_map[level].skill == 0) {
//							game_map[level].skill = 3;
//						}
//					}
//
//					if (level == 4) {
//						if (game_map[level].skill == 0) {
//							game_map[level].invisible();
//							game_map[level].skill = 4;
//							show_total_block();
//						}
//						else if (game_map[level].skill == level && time(NULL) - game_map[level].time_now > 5) {
//							game_map[level].invisible();
//						}
//					}
//					if (level == 5) {
//						if (game_map[level].skill == 0) {
//							game_map[level].random_block();
//							block.gen_random_block();
//							game_map[level].skill = 5;
//						}
//					}
//					if (level == 6) {
//						if (game_map[level].skill == 0) {
//							game_map[level].turn();
//							show_total_block();
//							check_full_line();
//						}
//					}
//					if (level == 7 && game_map[level].skill == 0) {
//						int s = rand() % 6 + 1;
//						if (s == 1) {
//							if (game_map[level].skill == 0) {
//								game_map[level].fast();
//								game_map[level].skill = 1;
//
//							}
//							else if (game_map[level].skill == 1 && time(NULL) - game_map[level].time_now > 5) {
//								game_map[level].fast();
//								if (level == 1) game_map[level].speed = 38;
//								else game_map[level].speed = 10;
//							}
//						}
//						if (s == 2) {
//							game_map[level].line_up();
//							show_total_block();
//						}
//						if (s == 3) {
//							if (game_map[level].skill == 0) {
//								game_map[level].skill = 3;
//							}
//						}
//						if (s == 4) {
//							if (game_map[level].skill == 0) {
//								game_map[level].invisible();
//								game_map[level].skill = 4;
//								show_total_block();
//
//							}
//							else if (game_map[level].skill == 4 && time(NULL) - game_map[level].time_now > 5) {
//								game_map[level].invisible();
//							}
//						}
//						if (s == 5) {
//							if (game_map[level].skill == 0 && block_shape < 8) {
//								game_map[level].random_block();
//								block.gen_random_block();
//								game_map[level].skill = 5;
//							}
//
//						}
//						if (s == 6) {
//							if (game_map[level].skill == 0) {
//								game_map[level].turn();
//								show_total_block();
//								check_full_line();
//							}
//						}
//
//					}
//					erase_cur_block(block_shape, block_angle, block_x, block_y);
//					show_cur_block(block_shape, block_angle, block_x, block_y);
//				} // FIXED ESC 누르면 잔상 남는거 처리함.
//				if (keytemp == EXT_KEY)
//				{
//					keytemp = _getche();
//					switch (keytemp)
//					{
//					case KEY_UP: //회전하기
//
//						if (strike_check(block_shape, (block_angle + 1) % 4, block_x, block_y) == 0)
//						{
//							erase_cur_block(block_shape, block_angle, block_x, block_y);
//							block_angle = (block_angle + 1) % 4;
//							show_cur_block(block_shape, block_angle, block_x, block_y);
//						}
//						else {
//							erase_cur_block(block_shape, block_angle, block_x, block_y);
//							for (int i = 0; i < 4; i++) {
//								if (strike_check(block_shape, (block_angle + 1) % 4, block_x - i - 1, block_y) == 0) {
//									block_x = block_x - i - 1;
//									erase_cur_block(block_shape, block_angle, block_x, block_y);
//									block_angle = (block_angle + 1) % 4;
//									show_cur_block(block_shape, block_angle, block_x, block_y);
//									break;
//								}
//							}
//						}// FIXED 오른쪽에서 안돌아가는거 처리함.
//
//						break;
//					case KEY_LEFT: //왼쪽으로 이동
//						if (block_x > 1)
//						{
//							erase_cur_block(block_shape, block_angle, block_x, block_y);
//							block_x--;
//							if (strike_check(block_shape, block_angle, block_x, block_y) == 1)
//								block_x++;
//
//							show_cur_block(block_shape, block_angle, block_x, block_y);
//						}
//						break;
//					case KEY_RIGHT: //오른쪽으로 이동
//						if ((block_x < game_map[level].size_x - 3 && block_y < 0) || (block_x < game_map[level].size_x && block_y >= 0))
//						{
//							erase_cur_block(block_shape, block_angle, block_x, block_y);
//							block_x++;
//							if (strike_check(block_shape, block_angle, block_x, block_y) == 1)
//								block_x--;
//							show_cur_block(block_shape, block_angle, block_x, block_y);
//						}
//						break;
//					case KEY_DOWN: //아래로 이동
//						is_gameover = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);
//						show_cur_block(block_shape, block_angle, block_x, block_y);
//						break;
//					}
//				}
//				if (keytemp == 32) //스페이스바를 눌렀을때
//				{
//					while (is_gameover == 0) {
//						is_gameover = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);
//					}
//					show_cur_block(block_shape, block_angle, block_x, block_y);
//				}
//			}
//
//			if (i % game_map[level].speed == 0)
//			{
//				is_gameover = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);
//
//				show_cur_block(block_shape, block_angle, block_x, block_y);
//			}
//
//			if (is_gameover == 1)
//			{
//
//				is_gameover = 0; // FIXED_3 게임 오버 시 재 실행하면 계속 FAILED 뜨는거 초기화해서 잡아줌.
//				console.Color(GRAY);
//				return false;
//			}
//			is_gameover = 0;
//			if (game_map[level].clear_line <= lines) //클리어 스테이지
//			{
//
//
//
//				lines = 0;
//				show_total_block(); // FIXED 스코어, 테두리 색깔 안바뀌는거 처리함.
//				show_next_block(next_block_shape); // FIXED 스코어, 테두리 색깔 안바뀌는거 처리함.
//				show_gamestat(); // FIXED 스코어, 테두리 색깔 안바뀌는거 처리함.
//				return true;
//
//			}
//
//			console.gotoxy(77, 23);
//			Sleep(15);
//			console.gotoxy(77, 23);
//		} // PLUS 게임 하는 부분
//	}
//}
//
//void Game::init()
//{
//	sk2_time = sk5_time = 0;
//	for (int i = 0; i < 8; i++) game_map[i].skill = 0;
//	game_map[level].genMap(game_map[level].map);
//	game_map[level].skill = 0;
//	lines = 0;
//	score = 0;
//}
//
//int Game::show_cur_block(int shape, int angle, int x, int y)
//{
//	int i, j;
//
//	switch (shape)
//	{
//	case 0:
//		console.Color(RED);
//		break;
//	case 1:
//		console.Color(BLUE);
//		break;
//	case 2:
//		console.Color(SKY_BLUE);
//		break;
//	case 3:
//		console.Color(WHITE);
//		break;
//	case 4:
//		console.Color(YELLOW);
//		break;
//	case 5:
//		console.Color(VOILET);
//		break;
//	case 6:
//		console.Color(GREEN);
//		break;
//	case 7:
//		console.Color(DARK_VOILET);
//		break;
//	case 8:
//		console.Color(DARK_YELLOW);
//		break;
//	}
//	if (sk5_time != 0) {
//		shadow_x = x;
//		shadow_y = y;
//		while (!move_shadow_block(&shape, &angle, &x, &y)) {}
//		for (i = 0; i < 4; i++)
//		{
//			for (j = 0; j < 4; j++)
//			{
//				if ((j + shadow_y) < 0)
//					continue;
//
//				if (block.block[shape][angle][j][i] > 0)
//				{
//
//					PrintErase((i + shadow_x) * 16 + ab_x - 1, j + shadow_y * 8 + ab_y);
//
//				}
//			}
//		}
//	}
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if ((j + y) < 0)
//				continue;
//
//			if (block.block[shape][angle][j][i] > 0)
//			{
//
//				PrintBlock((i + x) * 16 + ab_x - 1, (j + y) * 8 + ab_y);
//			}
//		}
//	}
//
//
//	console.Color(BLACK);
//	console.gotoxy(77, 23);
//	return 0;
//}
//
//int Game::erase_cur_block(int shape, int angle, int x, int y)
//{
//	int i, j;
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if (block.block[shape][angle][j][i] == 1)
//			{
//				console.gotoxy((i + x) * 2 + ab_x - 1, j + y + ab_y);
//				PrintVoid((i + x) * 16 + ab_x - 1, (j + y) * 8 + ab_y);
//				//break;
//
//			}
//		}
//	}
//	return 0;
//}
//
//int Game::show_total_block()
//{
//	if ((level == 6 || level == 7) && game_map[level].skill == level) {
//		game_map[level].skill = 0;
//		game_map[level].turn();
//		check_full_line();
//	}
//	int i, j;
//	console.Color(DARK_GRAY);
//	for (i = 0; i < game_map[level].size_y + 1; i++)
//	{
//		for (j = 0; j < game_map[level].size_x + 2; j++)
//		{
//			if (j == 0 || j == game_map[level].size_x + 1 || i == game_map[level].size_y) //레벨에 따라 외벽 색이 변함
//			{
//				console.Color((level % 6) + 1);
//			}
//			else {
//				console.Color(DARK_GRAY);
//			}
//			console.gotoxy((j * 2) + ab_x - 1, i + ab_y);
//			if (game_map[level].map[i][j] > 0)
//			{
//				if ((level == 4 || level == 7) && game_map[level].map[i][j] == 1 && game_map[level].skill == level) PrintVoid((j * 16) + ab_x - 1, i * 8 + ab_y);
//				else PrintBlock((j * 16) + ab_x - 1, i * 8 + ab_y);
//			}
//			else {
//				PrintVoid((j * 16) + ab_x - 1, i * 8 + ab_y);
//			}
//		}
//	}
//	console.Color(BLACK);
//	console.gotoxy(77, 23);
//	return 0;
//}
//
//int Game::show_next_block(int shape)
//{
//	int i, j;
//	console.Color((level + 1) % 6 + 1);
//	for (i = 1; i < 7; i++)
//	{
//		console.gotoxy(44, i);
//		for (j = 0; j < 6; j++)
//		{
//			if (i == 1 || i == 6 || j == 0 || j == 5)
//			{
//				PrintBlock(18 * 16 + 36 + 16 * j, i * 8 - 7);
//			}
//			else {
//				PrintVoid(18 * 16 + 36 + 16 * j, i * 8 - 7);
//			}
//
//		}
//	}
//	show_cur_block(shape, 0, 21, 1);
//	return 0;
//}
//
//int Game::make_new_block()
//{
//	int shape;
//	int i;
//	int shape_value = 6;
//	i = rand() % 100;
//	if (i <= game_map[level].stick_rate) //막대기 나올확률 계산
//		return 0; //막대기 모양으로 리턴
//
//	if ((level == 5 || level == 7) && game_map[level].skill == level) {
//		shape = 8;
//		game_map[level].random_block();
//	}
//	else if ((level == 3 || level == 7) && game_map[level].skill == level) {
//		shape = 7;
//		game_map[level].f_block();
//	}
//	else shape = (rand() % shape_value) + 1; //shape에는 1~6의 값이 들어감
//	show_next_block(shape);
//	return shape;
//}
//
//int Game::strike_check(int shape, int angle, int x, int y)
//{
//	int i, j;
//	int block_dat = 0;
//
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if (y + i >= 0 && y + i <= game_map[level].size_y && x + j <= game_map[level].size_x + 1) {
//				if (((x + j) == game_map[level].size_x + 1))
//					block_dat = 1;
//				else
//					block_dat = game_map[level].map[y + i][x + j];
//
//				if (block_dat != 0 && (block.block[shape][angle][i][j] == 1 || y < -2)) //좌측벽의 좌표를 빼기위함, FIXED_6 왼쪽에 일자블록 나오자마자 집어넣으면 Game over 뜨는 오류 수정
//				{
//					return 1;
//				}
//			}
//		}
//	}
//	return 0;
//}
//
//int Game::merge_block(int shape, int angle, int x, int y)
//{
//	int i, j;
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			game_map[level].map[y + i][x + j] |= block.block[shape][angle][i][j];
//			cout << game_map[level].map[y + i][x + j];
//		}
//	}
//	check_full_line();
//	show_total_block();
//
//	return 0;
//}
//
//void Game::block_start(int shape, int* angle, int* x, int* y)
//{
//	*x = 5;
//	*y = -3;
//	*angle = 0;
//}
//
//int Game::move_block(int* shape, int* angle, int* x, int* y, int* next_shape)
//{
//	erase_cur_block(*shape, *angle, *x, *y);
//
//	(*y)++; //블럭을 한칸 아래로 내림
//	if (strike_check(*shape, *angle, *x, *y))
//	{
//		if (*y <= 0) // FIXED 게임오버 판정 y==0일 때도 게임 오버임 (위에 y++ 때문에 y=-1일때 안먹음. #BUG 6
//		{
//			(*y)--; // FIXED 표시될 때 한칸 밑으로 겹쳐서 표시됨. #BUG 7
//			return 1;
//		}
//		(*y)--;
//		merge_block(*shape, *angle, *x, *y);
//		*shape = *next_shape;
//		*next_shape = make_new_block();
//
//		block_start(*shape, angle, x, y); //angle,x,y는 포인터임
//		show_next_block(*next_shape);
//		return 2;
//	}
//	return 0;
//}
//
//int Game::move_shadow_block(int* shape, int* angle, int* x, int* y)
//{
//	(*y)++;
//	if (strike_check(*shape, *angle, *x, *y))
//	{
//		(*y)--;
//
//		return 1;
//	}
//	return 0;
//}
//int Game::move_shadow_block(int* shape, int* angle, int* x, int* y)
//{
//	erase_cur_block(*shape, *angle, *x, *y);
//
//	(*y)++; //블럭을 한칸 아래로 내림
//	if (strike_check(*shape, *angle, *x, *y))
//	{
//		(*y)--;
//		return 1;
//	}
//	return 0;
//}
//void Game::show_gameover()
//{
//	console.Color(12);	// RED = 12
//	console.gotoxy(15, 8);
//	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
//	console.gotoxy(15, 9);
//	cout << "┃**************************┃";
//	console.gotoxy(15, 10);
//	cout << "┃*        GAME OVER       *┃";
//	console.gotoxy(15, 11);
//	cout << "┃**************************┃";
//	console.gotoxy(15, 12);
//	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
//	fflush(stdin);
//	Sleep(1000);
//
//	_getche();
//	system("cls");
//
//}
//
//void Game::show_gamestat()
//{
//	/*static int printed_text = 0;
//	console.Color(GRAY);
//	if (printed_text == 0)
//	{
//		console.gotoxy(46, 7);
//		cout << "STAGE";
//
//		console.gotoxy(46, 9);
//		cout << "SCORE";
//
//		console.gotoxy(46, 12);
//		cout << "LINES";
//
//	}
//	console.gotoxy(52, 7);
//	cout << level + 1;
//	console.gotoxy(46, 10);
//	cout << score;
//	console.gotoxy(46, 13);
//	int remain = game_map[level].clear_line - lines;
//	cout << remain;*/
//}
//
//void Game::show_logo()
//{
//	int i, j;
//	console.gotoxy(13, 3);
//	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
//	Sleep(100);
//	console.gotoxy(13, 4);
//	cout << "┃◆◆◆  ◆◆◆  ◆◆◆   ◆◆     ◆   ◆  ◆┃";
//	Sleep(100);
//	console.gotoxy(13, 5);
//	cout << "┃  ◆    ◆        ◆     ◆ ◆    ◆    ◆◆ ┃";
//	Sleep(100);
//	console.gotoxy(13, 6);
//	cout << "┃  ◆    ◆◆◆    ◆     ◆◆     ◆     ◆  ┃";
//	Sleep(100);
//	console.gotoxy(13, 7);
//	cout << "┃  ◆    ◆        ◆     ◆ ◆    ◆    ◆◆ ┃";
//	Sleep(100);
//	console.gotoxy(13, 8);
//	cout << "┃  ◆    ◆◆◆    ◆     ◆  ◆   ◆   ◆  ◆┃";
//	Sleep(100);
//	console.gotoxy(13, 9);
//	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
//
//	console.gotoxy(28, 20);
//	cout << "Please Press Any Key~!";
//
//	for (i = 0; i >= 0; i++)
//	{
//		if (i % 40 == 0)
//		{
//
//			for (j = 0; j < 80; j++)
//			{
//				for (int z = 0; z < 5; z++) {
//					console.gotoxy(6 + j, 14 + z);
//					cout << "  ";
//				}
//
//			}
//			show_cur_block(rand() % 7, rand() % 4, 6, 14);
//			show_cur_block(rand() % 7, rand() % 4, 12, 14);
//			show_cur_block(rand() % 7, rand() % 4, 19, 14);
//			show_cur_block(rand() % 7, rand() % 4, 24, 14);
//		}
//		if (_kbhit())
//			break;
//		Sleep(30);
//	}
//
//	_getche();
//	system("cls");
//
//}
//
//void Game::input_data()
//{
//	int i = 0;
//	while (i < 1 || i > 10)
//	{
//		system("cls");
//		console.Color(GRAY);
//		console.gotoxy(10, 7);
//		cout << "┏━━━━━━━━━<GAME KEY>━━━━━━━━━┓";
//		Sleep(10);
//		console.gotoxy(10, 8);
//		cout << "┃ UP   : Rotate Block        ┃";
//		Sleep(10);
//		console.gotoxy(10, 9);
//		cout << "┃ DOWN : Move One-Step Down  ┃";
//		Sleep(10);
//		console.gotoxy(10, 10);
//		cout << "┃ SPACE: Move Bottom Down    ┃";
//		Sleep(10);
//		console.gotoxy(10, 11);
//		cout << "┃ LEFT : Move Left           ┃";
//		Sleep(10);
//		console.gotoxy(10, 12);
//		cout << "┃ RIGHT: Move Right          ┃";
//		Sleep(10);
//		console.gotoxy(10, 13);
//		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
//
//
//		rewind(stdin);
//		console.gotoxy(10, 3);
//		cout << "Select Start level[1-10]: ";
//		cin >> i;
//	}
//
//	// FIXED_2 원래 i 값 int 로 받던거 char 로 해서 예외 안나오게 처리함.
//	// RE_FIXED_4 큰 수 입력하면 그대로 넘어가서 rewind로 입력 버퍼 초기화시켜줌, 레벨 10까지 있어서 10으로 늘려줌.
//	// FIXED_5 일정 길이 이상 입력하면 뒤에 잔상 안지워지는거 지움.
//
//	level = i - 1;
//	system("cls");
//}
//
//void Game::check_full_line()
//{
//	int i, j, k;
//	for (i = 0; i < game_map[level].size_y; i++)
//	{
//		for (j = 1; j <= game_map[level].size_x; j++)
//		{
//			if (game_map[level].map[i][j] == 0)
//				break;
//		}
//		if (j == game_map[level].size_x + 1) //한줄이 다 채워졌음
//		{
//			lines++;
//			show_total_block();
//			console.Color(BLUE);
//			console.gotoxy(1 * 2 + ab_x - 1, i + ab_y);
//			for (j = 0; j <= game_map[level].size_x - 1; j++)
//			{
//				PrintErase((1 + j) * 16 + ab_x - 1, i * 8 + ab_y);
//				Sleep(10);
//			}
//			console.gotoxy(1 * 16 + ab_x - 1, i * 8 + ab_y);
//			for (j = 0; j <= game_map[level].size_x - 1; j++)
//			{
//				PrintVoid((1 + j) * 16 + ab_x - 1, i * 8 + ab_y);
//				Sleep(10);
//			}
//
//			for (k = i; k > 0; k--)
//			{
//				for (j = 1; j <= game_map[level].size_x; j++)
//					game_map[level].map[k][j] = game_map[level].map[k - 1][j];
//			}
//			for (j = 1; j <= game_map[level].size_x; j++)
//				game_map[level].map[0][j] = 0;
//			score += 100 + (level * 10) + (rand() % 10);
//			show_gamestat();
//		}
//	}
//}