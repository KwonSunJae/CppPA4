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
	//��� ����
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
		input_data(); // PLUS i�� �Է¹����ڿ� ���̵� ����. FIXED_2 �Է� ���� ó��
		show_total_block();// PLUS �÷��� ȭ�鿡�� �׵θ� ���.
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
				} // FIXED ESC ������ �ܻ� ���°� ó����.
				if (keytemp == EXT_KEY)
				{
					keytemp = _getche();
					switch (keytemp)
					{
					case KEY_UP: //ȸ���ϱ�

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
						}// FIXED �����ʿ��� �ȵ��ư��°� ó����.

						break;
					case KEY_LEFT: //�������� �̵�
						if (block_x > 1)
						{
							erase_cur_block(block_shape, block_angle, block_x, block_y);
							block_x--;
							if (strike_check(block_shape, block_angle, block_x, block_y) == 1)
								block_x++;

							show_cur_block(block_shape, block_angle, block_x, block_y);
						}
						break;
					case KEY_RIGHT: //���������� �̵�

						if (block_x < 14)
						{
							erase_cur_block(block_shape, block_angle, block_x, block_y);
							block_x++;
							if (strike_check(block_shape, block_angle, block_x, block_y) == 1)
								block_x--;
							show_cur_block(block_shape, block_angle, block_x, block_y);
						}
						break;
					case KEY_DOWN: //�Ʒ��� �̵�
						is_gameover = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);
						show_cur_block(block_shape, block_angle, block_x, block_y);
						break;
					}
				}
				if (keytemp == 32) //�����̽��ٸ� ��������
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
				is_gameover = 0; // FIXED_3 ���� ���� �� �� �����ϸ� ��� FAILED �ߴ°� �ʱ�ȭ�ؼ� �����.
				map.SetColor(GRAY);
				break;
			}

			if (stage_data[level].clear_line <= lines) //Ŭ���� ��������
			{
				if (level == 9) {
					break;
				}//  ���� 10Ŭ����� ���� 11�γѾ�� ���� ����
				level++;
				lines = 0;
				show_total_block(); // FIXED ���ھ�, �׵θ� ���� �ȹٲ�°� ó����.
				show_next_block(next_block_shape); // FIXED ���ھ�, �׵θ� ���� �ȹٲ�°� ó����.
				show_gamestat(); // FIXED ���ھ�, �׵θ� ���� �ȹٲ�°� ó����.

			}

			map.gotoxy(77, 23);
			Sleep(15);
			map.gotoxy(77, 23);
		} // PLUS ���� �ϴ� �κ�
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

	for (j = 0; j < 14; j++) //ȭ���� ���� ���� ���� 1�� ä���.
		total_block[20][j] = 1;

	//�������� �ʱ�ȭ
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
				printf("��");

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
			if (j == 0 || j == 13 || i == 20) //������ ���� �ܺ� ���� ����
			{
				map.SetColor((level % 6) + 1);

			}
			else {
				map.SetColor(DARK_GRAY);
			}
			map.gotoxy((j * 2) + ab_x, i + ab_y);
			if (total_block[i][j] == 1)
			{
				printf("��");
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
				printf("��");
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
	if (i <= stage_data[level].stick_rate) //����� ����Ȯ�� ���
		return 0; //����� ������� ����

	shape = (rand() % 6) + 1; //shape���� 1~6�� ���� ��
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

			if (block_dat == 1 && (Block.block[shape][angle][i][j] == 1 || y < -2)) //�������� ��ǥ�� ��������, FIXED_6 ���ʿ� ���ں�� �����ڸ��� ��������� Game over �ߴ� ���� ����
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

	(*y)++; //���� ��ĭ �Ʒ��� ����
	if (strike_check(*shape, *angle, *x, *y))
	{
		if (*y <= 0) // FIXED ���ӿ��� ���� y==0�� ���� ���� ������ (���� y++ ������ y=-1�϶� �ȸ���. #BUG 6
		{
			(*y)--; // FIXED ǥ�õ� �� ��ĭ ������ ���ļ� ǥ�õ�. #BUG 7
			return 1;
		}
		(*y)--;
		merge_block(*shape, *angle, *x, *y);
		*shape = *next_shape;
		*next_shape = make_new_block();

		block_start(*shape, angle, x, y); //angle,x,y�� ��������
		show_next_block(*next_shape);
		return 2;
	}
	return 0;
}

int Game::show_gameover()
{
	map.SetColor(12);	// RED = 12
	map.gotoxy(15, 8);
	cout << "��������������������������������������������������������";
	map.gotoxy(15, 9);
	cout << "��**************************��";
	map.gotoxy(15, 10);
	cout << "��*        GAME OVER       *��";
	map.gotoxy(15, 11);
	cout << "��**************************��";
	map.gotoxy(15, 12);
	cout << "��������������������������������������������������������";
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
	cout<<"����������������������������������������������������������������������������������������������";
	Sleep(100);
	map.gotoxy(13, 4);
	cout<<"���ߡߡ�  �ߡߡ�  �ߡߡ�   �ߡ�     ��   ��  �ߦ�";
	Sleep(100);
	map.gotoxy(13, 5);
	cout<<"��  ��    ��        ��     �� ��    ��    �ߡ� ��";
	Sleep(100);
	map.gotoxy(13, 6);
	cout<<"��  ��    �ߡߡ�    ��     �ߡ�     ��     ��  ��";
	Sleep(100);
	map.gotoxy(13, 7);
	cout<<"��  ��    ��        ��     �� ��    ��    �ߡ� ��";
	Sleep(100);
	map.gotoxy(13, 8);
	cout<<"��  ��    �ߡߡ�    ��     ��  ��   ��   ��  �ߦ�";
	Sleep(100);
	map.gotoxy(13, 9);
	cout<<"����������������������������������������������������������������������������������������������";

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
		cout<<"��������������������<GAME KEY>��������������������";
		Sleep(10);
		map.gotoxy(10, 8);
		cout<<"�� UP   : Rotate Block        ��";
		Sleep(10);
		map.gotoxy(10, 9);
		cout<<"�� DOWN : Move One-Step Down  ��";
		Sleep(10);
		map.gotoxy(10, 10);
		cout<<"�� SPACE: Move Bottom Down    ��";
		Sleep(10);
		map.gotoxy(10, 11);
		cout<<"�� LEFT : Move Left           ��";
		Sleep(10);
		map.gotoxy(10, 12);
		cout<<"�� RIGHT: Move Right          ��";
		Sleep(10);
		map.gotoxy(10, 13);
		cout<<"������������������������������������������������������������";


		rewind(stdin);
		map.gotoxy(10, 3);
		cout<<"Select Start level[1-10]: ";
		cin >> i;
	}

	// FIXED_2 ���� i �� int �� �޴��� char �� �ؼ� ���� �ȳ����� ó����.
	// RE_FIXED_4 ū �� �Է��ϸ� �״�� �Ѿ�� rewind�� �Է� ���� �ʱ�ȭ������, ���� 10���� �־ 10���� �÷���.
	// FIXED_5 ���� ���� �̻� �Է��ϸ� �ڿ� �ܻ� ���������°� ����.

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
		if (j == 13) //������ �� ä������
		{
			lines++;
			show_total_block();
			map.SetColor(BLUE);
			map.gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j < 13; j++)
			{
				printf("��");
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

