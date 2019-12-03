#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::starttetris()
{
	//*********************************
	//상수 선언
	//*********************************
	const char EXT_KEY = 0xffffffe0;
	const char KEY_LEFT = 0x4b;
	const char KEY_RIGHT = 0x4d;
	const char KEY_UP = 0x48;
	const char KEY_DOWN = 0x50;

	int i;
	int is_gameover = 0;
	char keytemp;
	init();
	show_logo();
	while (1)
	{
		input_data(); // PLUS i값 입력받은뒤에 난이도 설정. FIXED_2 입력 예외 처리
		show_total_block();// PLUS 플레이 화면에서 테두리 출력.
		block_shape = make_new_block();
		next_block_shape = make_new_block();
		show_next_block(next_block_shape);
		block_start(block_shape, &block_angle, &block_x, &block_y);
		show_gamestat();
		for (i = 1; 1; i++)

		{
			if (_kbhit())
			{
				keytemp = _getche();
				if (keytemp == 27) {
					erase_cur_block(block_shape, block_angle, block_x, block_y);
					show_cur_block(block_shape, block_angle, block_x, block_y);
				} // FIXED ESC 누르면 잔상 남는거 처리함.
				if (keytemp == EXT_KEY)
				{
					keytemp = _getche();
					switch (keytemp)
					{
					case KEY_UP: //회전하기

						if (strike_check(block_shape, (block_angle + 1) % 4, block_x, block_y) == 0)
						{
							erase_cur_block(block_shape, block_angle, block_x, block_y);
							block_angle = (block_angle + 1) % 4;
							show_cur_block(block_shape, block_angle, block_x, block_y);
						}
						else {
							erase_cur_block(block_shape, block_angle, block_x, block_y);
							for (int i = 0; i < 4; i++) {
								if (strike_check(block_shape, (block_angle + 1) % 4, block_x - i - 1, block_y) == 0) {
									block_x = block_x - i - 1;
									erase_cur_block(block_shape, block_angle, block_x, block_y);
									block_angle = (block_angle + 1) % 4;
									show_cur_block(block_shape, block_angle, block_x, block_y);
									break;
								}
							}
						}// FIXED 오른쪽에서 안돌아가는거 처리함.

						break;
					case KEY_LEFT: //왼쪽으로 이동
						if (block_x > 1)
						{
							erase_cur_block(block_shape, block_angle, block_x, block_y);
							block_x--;
							if (strike_check(block_shape, block_angle, block_x, block_y) == 1)
								block_x++;

							show_cur_block(block_shape, block_angle, block_x, block_y);
						}
						break;
					case KEY_RIGHT: //오른쪽으로 이동

						if (block_x < 14)
						{
							erase_cur_block(block_shape, block_angle, block_x, block_y);
							block_x++;
							if (strike_check(block_shape, block_angle, block_x, block_y) == 1)
								block_x--;
							show_cur_block(block_shape, block_angle, block_x, block_y);
						}
						break;
					case KEY_DOWN: //아래로 이동
						is_gameover = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);
						show_cur_block(block_shape, block_angle, block_x, block_y);
						break;
					}
				}
				if (keytemp == 32) //스페이스바를 눌렀을때
				{
					while (is_gameover == 0)
					{
						is_gameover = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);
					}
					show_cur_block(block_shape, block_angle, block_x, block_y);
				}
			}

			if (i % stage_data[level].speed == 0)
			{
				is_gameover = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);

				show_cur_block(block_shape, block_angle, block_x, block_y);
			}

			if (is_gameover == 1)
			{
				show_gameover();
				is_gameover = 0; // FIXED_3 게임 오버 시 재 실행하면 계속 FAILED 뜨는거 초기화해서 잡아줌.
				map.SetColor(GRAY);
				break;
			}

			if (stage_data[level].clear_line <= lines) //클리어 스테이지
			{
				if (level == 9) {
					break;
				}//  레벨 10클리어시 레벨 11로넘어가는 오류 수정
				level++;
				lines = 0;
				show_total_block(); // FIXED 스코어, 테두리 색깔 안바뀌는거 처리함.
				show_next_block(next_block_shape); // FIXED 스코어, 테두리 색깔 안바뀌는거 처리함.
				show_gamestat(); // FIXED 스코어, 테두리 색깔 안바뀌는거 처리함.

			}

			map.gotoxy(77, 23);
			Sleep(15);
			map.gotoxy(77, 23);
		} // PLUS 게임 하는 부분
		init();
	}

}

int Game::init()
{
	int i, j;

	srand((unsigned)time(NULL));

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if ((j == 0) || (j == 13))
			{
				total_block[i][j] = 1;
			}
			else {
				total_block[i][j] = 0;
			}
		}
	}

	for (j = 0; j < 14; j++) //화면의 제일 밑의 줄은 1로 채운다.
		total_block[20][j] = 1;

	//전역변수 초기화
	level = 0;
	lines = 0;
	score = 0;
	ab_x = 5;
	ab_y = 1;

	stage_data[0].speed = 40;
	stage_data[0].stick_rate = 20;
	stage_data[0].clear_line = 1;
	stage_data[1].speed = 38;
	stage_data[1].stick_rate = 18;
	stage_data[1].clear_line = 20;
	stage_data[2].speed = 35;
	stage_data[2].stick_rate = 18;
	stage_data[2].clear_line = 20;
	stage_data[3].speed = 30;
	stage_data[3].stick_rate = 17;
	stage_data[3].clear_line = 20;
	stage_data[4].speed = 25;
	stage_data[4].stick_rate = 16;
	stage_data[4].clear_line = 20;
	stage_data[5].speed = 20;
	stage_data[5].stick_rate = 14;
	stage_data[5].clear_line = 20;
	stage_data[6].speed = 15;
	stage_data[6].stick_rate = 14;
	stage_data[6].clear_line = 20;
	stage_data[7].speed = 10;
	stage_data[7].stick_rate = 13;
	stage_data[7].clear_line = 20;
	stage_data[8].speed = 6;
	stage_data[8].stick_rate = 12;
	stage_data[8].clear_line = 20;
	stage_data[9].speed = 4;
	stage_data[9].stick_rate = 11;
	stage_data[9].clear_line = 99999;
	return 0;
}

int Game::show_cur_block(int shape, int angle, int x, int y)
{
	int i, j;

	switch (shape)
	{
	case 0:
		map.SetColor(RED);
		break;
	case 1:
		map.SetColor(BLUE);
		break;
	case 2:
		map.SetColor(SKY_BLUE);
		break;
	case 3:
		map.SetColor(WHITE);
		break;
	case 4:
		map.SetColor(YELLOW);
		break;
	case 5:
		map.SetColor(VOILET);
		break;
	case 6:
		map.SetColor(GREEN);
		break;
	}

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if ((j + y) < 0)
				continue;

			if (Block.block[shape][angle][j][i] == 1)
			{
				map.gotoxy((i + x) * 2 + ab_x, j + y + ab_y);
				printf("■");

			}
		}
	}
	map.SetColor(BLACK);
	map.gotoxy(77, 23);
	return 0;
}

int Game::erase_cur_block(int shape, int angle, int x, int y)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (Block.block[shape][angle][j][i] == 1)
			{
				map.gotoxy((i + x) * 2 + ab_x, j + y + ab_y);
				printf("  ");
				//break;

			}
		}
	}
	return 0;
}

int Game::show_total_block()
{
	int i, j;
	map.SetColor(DARK_GRAY);
	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (j == 0 || j == 13 || i == 20) //레벨에 따라 외벽 색이 변함
			{
				map.SetColor((level % 6) + 1);

			}
			else {
				map.SetColor(DARK_GRAY);
			}
			map.gotoxy((j * 2) + ab_x, i + ab_y);
			if (total_block[i][j] == 1)
			{
				printf("■");
			}
			else {
				printf("  ");
			}

		}
	}
	map.SetColor(BLACK);
	map.gotoxy(77, 23);
	return 0;
}

int Game::show_next_block(int shape)
{
	int i, j;
	map.SetColor((level + 1) % 6 + 1);
	for (i = 1; i < 7; i++)
	{
		map.gotoxy(33, i);
		for (j = 0; j < 6; j++)
		{
			if (i == 1 || i == 6 || j == 0 || j == 5)
			{
				printf("■");
			}
			else {
				printf("  ");
			}

		}
	}
	show_cur_block(shape, 0, 15, 1);
	return 0;
}

int Game::make_new_block()
{
	int shape;
	int i;
	i = rand() % 100;
	if (i <= stage_data[level].stick_rate) //막대기 나올확률 계산
		return 0; //막대기 모양으로 리턴

	shape = (rand() % 6) + 1; //shape에는 1~6의 값이 들어감
	show_next_block(shape);
	return shape;
}

int Game::strike_check(int shape, int angle, int x, int y)
{
	int i, j;
	int block_dat;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (((x + j) == 0) || ((x + j) == 13))
				block_dat = 1;
			else
				block_dat = total_block[y + i][x + j];

			if (block_dat == 1 && (Block.block[shape][angle][i][j] == 1 || y < -2)) //좌측벽의 좌표를 빼기위함, FIXED_6 왼쪽에 일자블록 나오자마자 집어넣으면 Game over 뜨는 오류 수정
			{
				return 1;
			}
		}
	}
	return 0;
}

int Game::merge_block(int shape, int angle, int x, int y)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			total_block[y + i][x + j] |= Block.block[shape][angle][i][j];
		}
	}
	check_full_line();
	show_total_block();

	return 0;
}

int Game::block_start(int shape, int * angle, int * x, int * y)
{
	*x = 5;
	*y = -3;
	*angle = 0;
	return 0;
}

int Game::move_block(int * shape, int * angle, int * x, int * y, int * next_shape)
{
	erase_cur_block(*shape, *angle, *x, *y);

	(*y)++; //블럭을 한칸 아래로 내림
	if (strike_check(*shape, *angle, *x, *y))
	{
		if (*y <= 0) // FIXED 게임오버 판정 y==0일 때도 게임 오버임 (위에 y++ 때문에 y=-1일때 안먹음. #BUG 6
		{
			(*y)--; // FIXED 표시될 때 한칸 밑으로 겹쳐서 표시됨. #BUG 7
			return 1;
		}
		(*y)--;
		merge_block(*shape, *angle, *x, *y);
		*shape = *next_shape;
		*next_shape = make_new_block();

		block_start(*shape, angle, x, y); //angle,x,y는 포인터임
		show_next_block(*next_shape);
		return 2;
	}
	return 0;
}

int Game::show_gameover()
{
	map.SetColor(12);	// RED = 12
	map.gotoxy(15, 8);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	map.gotoxy(15, 9);
	cout << "┃**************************┃";
	map.gotoxy(15, 10);
	cout << "┃*        GAME OVER       *┃";
	map.gotoxy(15, 11);
	cout << "┃**************************┃";
	map.gotoxy(15, 12);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
	fflush(stdin);
	Sleep(1000);

	_getche();
	system("cls");

	return 0;
}

int Game::show_gamestat()
{
	static int printed_text = 0;
	map.SetColor(GRAY);
	if (printed_text == 0)
	{
		map.gotoxy(35, 7);
		cout<<"STAGE";

		map.gotoxy(35, 9);
		cout<<"SCORE";

		map.gotoxy(35, 12);
		cout << "LINES";

	}
	map.gotoxy(41, 7);
	cout<<level + 1;
	map.gotoxy(35, 10);
	cout<<score;
	map.gotoxy(35, 13);
	int remain = stage_data[level].clear_line - lines;
	cout<<remain;
	return 0;
}

int Game::show_logo()
{
	int i, j;
	map.gotoxy(13, 3);
	cout<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
	Sleep(100);
	map.gotoxy(13, 4);
	cout<<"┃◆◆◆  ◆◆◆  ◆◆◆   ◆◆     ◆   ◆  ◆┃";
	Sleep(100);
	map.gotoxy(13, 5);
	cout<<"┃  ◆    ◆        ◆     ◆ ◆    ◆    ◆◆ ┃";
	Sleep(100);
	map.gotoxy(13, 6);
	cout<<"┃  ◆    ◆◆◆    ◆     ◆◆     ◆     ◆  ┃";
	Sleep(100);
	map.gotoxy(13, 7);
	cout<<"┃  ◆    ◆        ◆     ◆ ◆    ◆    ◆◆ ┃";
	Sleep(100);
	map.gotoxy(13, 8);
	cout<<"┃  ◆    ◆◆◆    ◆     ◆  ◆   ◆   ◆  ◆┃";
	Sleep(100);
	map.gotoxy(13, 9);
	cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";

	map.gotoxy(28, 20);
	cout<<"Please Press Any Key~!";

	for (i = 0; i >= 0; i++)
	{
		if (i % 40 == 0)
		{

			for (j = 0; j < 80; j++)
			{
				for (int z = 0; z < 5; z++) {
					map.gotoxy(6 + j, 14 + z);
					cout<<"  ";
				}

			}
			show_cur_block(rand() % 7, rand() % 4, 6, 14);
			show_cur_block(rand() % 7, rand() % 4, 12, 14);
			show_cur_block(rand() % 7, rand() % 4, 19, 14);
			show_cur_block(rand() % 7, rand() % 4, 24, 14);
		}
		if (_kbhit())
			break;
		Sleep(30);
	}

	_getche();
	system("cls");

	return 0;
}

int Game::input_data()
{
	int i = 0;
	while (i < 1 || i > 10)
	{
		system("cls");
		map.SetColor(GRAY);
		map.gotoxy(10, 7);
		cout<<"┏━━━━━━━━━<GAME KEY>━━━━━━━━━┓";
		Sleep(10);
		map.gotoxy(10, 8);
		cout<<"┃ UP   : Rotate Block        ┃";
		Sleep(10);
		map.gotoxy(10, 9);
		cout<<"┃ DOWN : Move One-Step Down  ┃";
		Sleep(10);
		map.gotoxy(10, 10);
		cout<<"┃ SPACE: Move Bottom Down    ┃";
		Sleep(10);
		map.gotoxy(10, 11);
		cout<<"┃ LEFT : Move Left           ┃";
		Sleep(10);
		map.gotoxy(10, 12);
		cout<<"┃ RIGHT: Move Right          ┃";
		Sleep(10);
		map.gotoxy(10, 13);
		cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";


		rewind(stdin);
		map.gotoxy(10, 3);
		cout<<"Select Start level[1-10]: ";
		cin >> i;
	}

	// FIXED_2 원래 i 값 int 로 받던거 char 로 해서 예외 안나오게 처리함.
	// RE_FIXED_4 큰 수 입력하면 그대로 넘어가서 rewind로 입력 버퍼 초기화시켜줌, 레벨 10까지 있어서 10으로 늘려줌.
	// FIXED_5 일정 길이 이상 입력하면 뒤에 잔상 안지워지는거 지움.

	level = i - 1;
	system("cls");
	return 0;
}

int Game::check_full_line()
{
	int i, j, k;
	for (i = 0; i < 20; i++)
	{
		for (j = 1; j < 13; j++)
		{
			if (total_block[i][j] == 0)
				break;
		}
		if (j == 13) //한줄이 다 채워졌음
		{
			lines++;
			show_total_block();
			map.SetColor(BLUE);
			map.gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j < 13; j++)
			{
				printf("□");
				Sleep(10);
			}
			map.gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j < 13; j++)
			{
				printf("  ");
				Sleep(10);
			}

			for (k = i; k > 0; k--)
			{
				for (j = 1; j < 13; j++)
					total_block[k][j] = total_block[k - 1][j];
			}
			for (j = 1; j < 13; j++)
				total_block[0][j] = 0;
			score += 100 + (level * 10) + (rand() % 10);
			show_gamestat();
		}
	}
	return 0;
}

