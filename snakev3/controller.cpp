#include"stdafx.h"
void Controller::Game_select()
{
	SetColor(4);
	SetCursorPosition(13, 26);
	cout << "                          ";
	SetCursorPosition(13, 27);
	cout << "                          ";
	SetCursorPosition(10, 23);
	cout << "��ӭ����̰������Ϸ";
	SetCursorPosition(10, 25);
	cout << "ѡ����Ϸ�Ѷȣ�";
	SetCursorPosition(10, 27);
	cout << "�����ѡ��,Enterȷ��";
	SetCursorPosition(27, 22);
	//��һ��ѡ��Ĭ�ϱ���Ϊѡ��
	SetBackColor();//�ı�����
	cout << "��";
	SetCursorPosition(27, 24);
	SetColor(5);//ģʽ������ɫ
	cout << "��ͨ";
	SetCursorPosition(27, 26);
	cout << "����";
	SetCursorPosition(27, 28);
	cout << "ս��";
	//����������½�
	SetCursorPosition(0, 31);
	score = 0;

	//��¼����ֵ
	int ch;
	//ѡ�Ĭ��ѡ���һ��
	key = 1;
	//�Ƿ�����Enter����ǣ�Ĭ�Ϸ�
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)//��������
		{
		case 72://�������
			if (key > 1)//Ĭ�ϵ�һ�����������Ч
			{
				switch (key)
				{
				case 2:
					//��ѡ���
					SetCursorPosition(27, 22);
					SetBackColor();
					cout << "��";
					//��ѡ��ȡ������
					SetCursorPosition(27, 24);
					SetColor(5);
					cout << "��ͨ";

					--key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "��ͨ";
					SetCursorPosition(27, 26);
					SetColor(5);
					std::cout << "����";

					--key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����";
					SetCursorPosition(27, 28);
					SetColor(5);
					std::cout << "ս��";

					--key;
					break;
				}
			}
			break;

		case 80:
			//�������
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "��ͨ";
					SetCursorPosition(27, 22);
					SetColor(5);
					cout << "��";

					++key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "����";
					SetCursorPosition(27, 24);
					SetColor(5);
					std::cout << "��ͨ";

					++key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "ս��";
					SetCursorPosition(27, 26);
					SetColor(5);
					std::cout << "����";

					++key;
					break;
				}
			}
			break;

		case 13:
			//Enter�س���
			flag = true;
			break;
		default:
			//��Ч����������
			break;
		}
		//����Enter�˳�ѭ��
		if (flag) break;
		SetCursorPosition(0, 31);
	}

	switch (key)
		// ������ѡ�Ѷ������ƶ��ٶȣ�ֵԽС���ٶ�Խ��
	{
	case 1:
		speed = 150;
		break;
	case 2:
		speed = 110;
		break;
	case 3:
		speed = 70;
		break;
	case 4:
		speed = 30;
		break;
	default:
		break;
	}
}

void Controller::Game_draw()
{
	system("cls");//�����Ļ
	//���Ʊ߽��ͼ
	//����ǽ����ɫ ��ɫ
	SetColor(12);
	Map *show_map = new Map();
	show_map->Map_show();
	delete show_map;

	//ϵͳ������ʾ��Ϣ
	SetColor(15);
	SetCursorPosition(42, 2);
	cout << "̰����";
	SetCursorPosition(42, 4);
	cout << "�Ѷȣ�";
	SetCursorPosition(45, 4);
	switch (key)
	{
	case 1:
		cout << "��";
		break;
	case 2:
		cout << "��ͨ";
		break;
	case 3:
		cout << "����";
		break;
	case 4:
		cout << "ս��";
		break;
	default:
		break;
	}
	SetCursorPosition(42, 7);
	cout << "������";
	SetCursorPosition(45, 7);
	std::cout << "     0";
	SetCursorPosition(42, 13);
	std::cout << " ������ı���ͷ����";
	SetCursorPosition(42, 15);
	std::cout << " ESC��ͣ";
}

int Controller::Game_play()
{
	Snake *s_snake = new Snake();
	Food *e_food = new Food();
	SetColor(6);
	//��ӡ��
	s_snake->Star_snake();
	//������Ϊ��ʹÿ�β�һ����ϵͳʱ����ȷ������
	srand((unsigned)time(NULL));
	e_food->Food_draw(*s_snake);
	//��Ϸѭ��
	//�Ƿ�ײǽor�Ե��Լ�
	while (s_snake->Snake_wall() && s_snake->Snake_oneself())
	{
		//ѡ��˵�
		if (!s_snake->ChangeDirection()) //��Esc��ʱ
		{
			int tmp = Game_end();//���Ʋ˵�
			switch (tmp)
			{
			//������Ϸ
			case 1:
				break;
			//���¿�ʼ
			case 2:
				delete s_snake;
				delete e_food;
				//��1��Ϊgame_play����ֵ��Game�����¿�ʼ
				return 1;
			//�˳���Ϸ
			case 3:
				delete s_snake;
				delete e_food;
				//��2��Ϊgame_play����ֵ��Game�˳�
				return 2;

			default:
				break;
			}
		}

		if (s_snake->Snake_e_food(*e_food)) //�Ե�ʳ��
		{
			s_snake->Snake_add();//�߳���
			Game_score(1);//���·���
			Game_coutscore();//���´�ӡ����
			e_food->Food_draw(*s_snake);//������ʳ��
		}
		else
		{
			s_snake->Snake_move();//���ƶ�
		}

		if (s_snake->Snake_e_flashfood(*e_food)) //�Ե�����ʳ��
		{
			s_snake->Snake_add();
			//������������ʳ�����ʱ��ȷ��Խ��Խ��
			Game_score(e_food->Getprogressbar() / 3);
			Game_coutscore();
		}
		//���������ʳ��
		if (e_food->Getflashflag())
		{
			e_food->Food_flash();
		}
		//�ߵ��ƶ�
		Sleep(speed);
	}

	//������
	delete s_snake;
	delete e_food;
	//��ӡ��Ϸ��������
	int tmp = Game_over();
	switch (tmp)
	{
	case 1:
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
	default:
		return 2;
	}
}

void Controller::Game_score(const int& tmp)//���·���
{
	score += key * 1 * tmp;//���÷���������Ϸ�Ѷȼ���ʳ����Ŀȷ��
}

void Controller::Game_coutscore()
{
	//�滻ԭ��λ�õ�Ĭ�Ϸ���0/�Լ������ĵ÷ּ����·���
	SetCursorPosition(45, 7);
	SetColor(7);
	int bit = 0;
	int tmp = score;
	while (tmp != 0)
	{
		++bit;
		tmp /= 10;
	}
	for (int i = 0; i < (6 - bit); ++i)
	{
		cout << " ";
	}
	cout << score;
}

int Controller::Game_end()//������ѡ��˵�
{
	//�����˵�
	SetColor(15);
	Sleep(0);
	SetCursorPosition(34, 21);
	SetBackColor();
	cout << "������Ϸ";
	Sleep(0);
	SetCursorPosition(34, 23);
	SetColor(15);
	cout << "���¿�ʼ";
	Sleep(0);
	SetCursorPosition(34, 25);
	cout << "�˳���Ϸ";
	SetCursorPosition(0, 31);

	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 72:
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					SetCursorPosition(34, 21);
					SetBackColor();
					std::cout << "������Ϸ";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "���¿�ʼ";

					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 25);
					SetColor(11);
					std::cout << "�˳���Ϸ";

					--tmp_key;
					break;
				}
			}
			break;

		case 80:
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "���¿�ʼ";
					SetCursorPosition(34, 21);
					SetColor(11);
					std::cout << "������Ϸ";

					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "�˳���Ϸ";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "���¿�ʼ";

					++tmp_key;
					break;
				}
			}
			break;

		case 13:
			flag = true;
			break;

		default:
			break;
		}

		if (flag)
		{
			break;
		}
		SetCursorPosition(0, 31);
	}

	if (tmp_key == 1) //ѡ�������Ϸ���������˵�
	{
		SetCursorPosition(32, 19);
		cout << "      ";
		SetCursorPosition(34, 21);
		cout << "        ";
		SetCursorPosition(34, 23);
		cout << "        ";
		SetCursorPosition(34, 25);
		cout << "        ";
	}
	return tmp_key;
}

void Controller::Game()
{
	while (true)
	{
		Game_select();//ѡ�����
		Game_draw();//������Ϸ����
		int tmp = Game_play();//������Ϸѭ��
		if (tmp == 1) //����ֵΪ1ʱ���¿�ʼ��Ϸ
		{
			system("cls");
			continue;
		}
		else if (tmp == 2) //����ֵΪ2ʱ�˳���Ϸ
		{
			break;
		}
		else
		{
			break;
		}
	}
}

int Controller::Game_over()//��Ϸ��������
{
	//��Ϸ������
	Sleep(0);
	SetColor(15);
	SetCursorPosition(10, 8);
	cout << "��������������������������������������������������������������������";
	Sleep(0);
	SetCursorPosition(9, 9);
	cout << " ��                                 ��";
	Sleep(0);
	SetCursorPosition(9, 10);
	cout << " ��             Death               ��";
	Sleep(0);
	SetCursorPosition(9, 11);
	cout << " ��                                 ��";
	Sleep(0);
	SetCursorPosition(9, 12);
	cout << " ��             ������              ��";
	SetCursorPosition(20, 12);
	cout << score;
	Sleep(30);
	SetCursorPosition(9, 13);
	cout << " ��                                 ��";
	Sleep(30);
	SetCursorPosition(9, 14);
	cout << " ��             ������              ��";
	Sleep(30);
	SetCursorPosition(9, 15);
	cout << " ��                                 ��";
	Sleep(30);
	SetCursorPosition(9, 16);
	cout << " ��                                 ��";
	Sleep(30);
	SetCursorPosition(9, 17);
	cout << " ��    ��                   ��      ��";
	Sleep(30);
	SetCursorPosition(9, 18);
	cout << " ��                                 ��";
	Sleep(30);
	SetCursorPosition(9, 19);
	cout << " ��                                 ��";
	Sleep(30);
	SetCursorPosition(10, 20);
	cout << "��������������������������������������������������������������������";

	Sleep(100);
	SetCursorPosition(12, 17);
	SetBackColor();
	cout << "��";
	SetCursorPosition(0, 31);

	//ѡ��
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 75://�������
			if (tmp_key > 1)
			{
				SetCursorPosition(12, 17);
				SetBackColor();
				std::cout << "��";
				SetCursorPosition(22, 17);
				SetColor(15);
				std::cout << "��";
				--tmp_key;
			}
			break;

		case 77://�������
			if (tmp_key < 2)
			{
				SetCursorPosition(22, 17);
				SetBackColor();
				std::cout << "��";
				SetCursorPosition(12, 17);
				SetColor(15);
				std::cout << "��";
				++tmp_key;
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		SetCursorPosition(0, 31);
		if (flag) {
			break;
		}
	}

	SetColor(15);
	switch (tmp_key)
	{
	case 1:
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
	default:
		return 1;
	}
}