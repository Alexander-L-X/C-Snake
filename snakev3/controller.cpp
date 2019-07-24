#include"stdafx.h"
void Controller::Game_select()
{
	SetColor(4);
	SetCursorPosition(13, 26);
	cout << "                          ";
	SetCursorPosition(13, 27);
	cout << "                          ";
	SetCursorPosition(10, 23);
	cout << "欢迎来到贪吃蛇游戏";
	SetCursorPosition(10, 25);
	cout << "选择游戏难度：";
	SetCursorPosition(10, 27);
	cout << "方向键选择,Enter确认";
	SetCursorPosition(27, 22);
	//第一个选项默认背景为选中
	SetBackColor();//文本背景
	cout << "简单";
	SetCursorPosition(27, 24);
	SetColor(5);//模式字体颜色
	cout << "普通";
	SetCursorPosition(27, 26);
	cout << "困难";
	SetCursorPosition(27, 28);
	cout << "战神";
	//光标置于左下角
	SetCursorPosition(0, 31);
	score = 0;

	//记录键入值
	int ch;
	//选项，默认选择第一个
	key = 1;
	//是否输入Enter键标记，默认否
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)//检测输入键
		{
		case 72://方向键上
			if (key > 1)//默认第一个方向键上无效
			{
				switch (key)
				{
				case 2:
					//待选项背景
					SetCursorPosition(27, 22);
					SetBackColor();
					cout << "简单";
					//已选项取消背景
					SetCursorPosition(27, 24);
					SetColor(5);
					cout << "普通";

					--key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "普通";
					SetCursorPosition(27, 26);
					SetColor(5);
					std::cout << "困难";

					--key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难";
					SetCursorPosition(27, 28);
					SetColor(5);
					std::cout << "战神";

					--key;
					break;
				}
			}
			break;

		case 80:
			//方向键下
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "普通";
					SetCursorPosition(27, 22);
					SetColor(5);
					cout << "简单";

					++key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难";
					SetCursorPosition(27, 24);
					SetColor(5);
					std::cout << "普通";

					++key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "战神";
					SetCursorPosition(27, 26);
					SetColor(5);
					std::cout << "困难";

					++key;
					break;
				}
			}
			break;

		case 13:
			//Enter回车键
			flag = true;
			break;
		default:
			//无效的其他按键
			break;
		}
		//输入Enter退出循环
		if (flag) break;
		SetCursorPosition(0, 31);
	}

	switch (key)
		// 根据所选难度设置移动速度，值越小，速度越快
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
	system("cls");//清除屏幕
	//绘制边界地图
	//设置墙警戒色 红色
	SetColor(12);
	Map *show_map = new Map();
	show_map->Map_show();
	delete show_map;

	//系统及其提示信息
	SetColor(15);
	SetCursorPosition(42, 2);
	cout << "贪吃蛇";
	SetCursorPosition(42, 4);
	cout << "难度：";
	SetCursorPosition(45, 4);
	switch (key)
	{
	case 1:
		cout << "简单";
		break;
	case 2:
		cout << "普通";
		break;
	case 3:
		cout << "困难";
		break;
	case 4:
		cout << "战神";
		break;
	default:
		break;
	}
	SetCursorPosition(42, 7);
	cout << "分数：";
	SetCursorPosition(45, 7);
	std::cout << "     0";
	SetCursorPosition(42, 13);
	std::cout << " 方向键改变蛇头方向";
	SetCursorPosition(42, 15);
	std::cout << " ESC暂停";
}

int Controller::Game_play()
{
	Snake *s_snake = new Snake();
	Food *e_food = new Food();
	SetColor(6);
	//打印蛇
	s_snake->Star_snake();
	//撒种子为了使每次不一样用系统时间来确定种子
	srand((unsigned)time(NULL));
	e_food->Food_draw(*s_snake);
	//游戏循环
	//是否撞墙or吃到自己
	while (s_snake->Snake_wall() && s_snake->Snake_oneself())
	{
		//选择菜单
		if (!s_snake->ChangeDirection()) //按Esc键时
		{
			int tmp = Game_end();//绘制菜单
			switch (tmp)
			{
			//继续游戏
			case 1:
				break;
			//重新开始
			case 2:
				delete s_snake;
				delete e_food;
				//将1作为game_play返回值到Game中重新开始
				return 1;
			//退出游戏
			case 3:
				delete s_snake;
				delete e_food;
				//将2作为game_play返回值到Game退出
				return 2;

			default:
				break;
			}
		}

		if (s_snake->Snake_e_food(*e_food)) //吃到食物
		{
			s_snake->Snake_add();//蛇长长
			Game_score(1);//更新分数
			Game_coutscore();//重新打印分数
			e_food->Food_draw(*s_snake);//绘制新食物
		}
		else
		{
			s_snake->Snake_move();//蛇移动
		}

		if (s_snake->Snake_e_flashfood(*e_food)) //吃到闪光食物
		{
			s_snake->Snake_add();
			//分数根据闪光食物存在时间确定越长越高
			Game_score(e_food->Getprogressbar() / 3);
			Game_coutscore();
		}
		//如果有闪光食物
		if (e_food->Getflashflag())
		{
			e_food->Food_flash();
		}
		//蛇的移动
		Sleep(speed);
	}

	//蛇死亡
	delete s_snake;
	delete e_food;
	//打印游戏结束界面
	int tmp = Game_over();
	switch (tmp)
	{
	case 1:
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 2;
	}
}

void Controller::Game_score(const int& tmp)//更新分数
{
	score += key * 1 * tmp;//所得分数根据游戏难度及吃食物数目确定
}

void Controller::Game_coutscore()
{
	//替换原来位置的默认分数0/以及其他的得分即更新分数
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

int Controller::Game_end()//结束的选择菜单
{
	//结束菜单
	SetColor(15);
	Sleep(0);
	SetCursorPosition(34, 21);
	SetBackColor();
	cout << "继续游戏";
	Sleep(0);
	SetCursorPosition(34, 23);
	SetColor(15);
	cout << "重新开始";
	Sleep(0);
	SetCursorPosition(34, 25);
	cout << "退出游戏";
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
					std::cout << "继续游戏";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "重新开始";

					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "重新开始";
					SetCursorPosition(34, 25);
					SetColor(11);
					std::cout << "退出游戏";

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
					std::cout << "重新开始";
					SetCursorPosition(34, 21);
					SetColor(11);
					std::cout << "继续游戏";

					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "退出游戏";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "重新开始";

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

	if (tmp_key == 1) //选择继续游戏消除结束菜单
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
		Game_select();//选择界面
		Game_draw();//绘制游戏界面
		int tmp = Game_play();//开启游戏循环
		if (tmp == 1) //返回值为1时重新开始游戏
		{
			system("cls");
			continue;
		}
		else if (tmp == 2) //返回值为2时退出游戏
		{
			break;
		}
		else
		{
			break;
		}
	}
}

int Controller::Game_over()//游戏结束界面
{
	//游戏结束框
	Sleep(0);
	SetColor(15);
	SetCursorPosition(10, 8);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(0);
	SetCursorPosition(9, 9);
	cout << " ┃                                 ┃";
	Sleep(0);
	SetCursorPosition(9, 10);
	cout << " ┃             Death               ┃";
	Sleep(0);
	SetCursorPosition(9, 11);
	cout << " ┃                                 ┃";
	Sleep(0);
	SetCursorPosition(9, 12);
	cout << " ┃             分数：              ┃";
	SetCursorPosition(20, 12);
	cout << score;
	Sleep(30);
	SetCursorPosition(9, 13);
	cout << " ┃                                 ┃";
	Sleep(30);
	SetCursorPosition(9, 14);
	cout << " ┃             继续？              ┃";
	Sleep(30);
	SetCursorPosition(9, 15);
	cout << " ┃                                 ┃";
	Sleep(30);
	SetCursorPosition(9, 16);
	cout << " ┃                                 ┃";
	Sleep(30);
	SetCursorPosition(9, 17);
	cout << " ┃    是                   否      ┃";
	Sleep(30);
	SetCursorPosition(9, 18);
	cout << " ┃                                 ┃";
	Sleep(30);
	SetCursorPosition(9, 19);
	cout << " ┃                                 ┃";
	Sleep(30);
	SetCursorPosition(10, 20);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

	Sleep(100);
	SetCursorPosition(12, 17);
	SetBackColor();
	cout << "是";
	SetCursorPosition(0, 31);

	//选择
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 75://方向键左
			if (tmp_key > 1)
			{
				SetCursorPosition(12, 17);
				SetBackColor();
				std::cout << "是";
				SetCursorPosition(22, 17);
				SetColor(15);
				std::cout << "否";
				--tmp_key;
			}
			break;

		case 77://方向键右
			if (tmp_key < 2)
			{
				SetCursorPosition(22, 17);
				SetBackColor();
				std::cout << "否";
				SetCursorPosition(12, 17);
				SetColor(15);
				std::cout << "是";
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
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 1;
	}
}