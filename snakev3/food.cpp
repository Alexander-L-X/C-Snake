#include"stdafx.h"

void Food::Food_draw(Snake& f_snake)
{
	//随机获得坐标在地图内,如果获得的坐标与蛇身重叠重新获取/每次
	while (true)
	{
		int tmp_x = rand() % 30;
		int tmp_y = rand() % 30;
		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;
		bool flag = false;
		for (auto& point : f_snake.snake)
		{
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == flash_x && tmp_y == flash_y)) {
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		x = tmp_x;
		y = tmp_y;
		SetCursorPosition(x, y);
		SetColor(13);
		cout << "※";
		++cnt;
		cnt %= 10;
		if (cnt == 0)
		{
			Food_flash_draw(f_snake);
		}
		break;
	}
}

void Food::Food_flash_draw(Snake& f_snake)
{
	SetCursorPosition(5, 0);
	SetColor(14);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";//进度条
	progress_bar = 42;
	while (true)
	{
		int tmp_x = rand() % 30;
		int tmp_y = rand() % 30;
		if (tmp_x < 2) tmp_x += 2;
		if (tmp_y < 2) tmp_y += 2;
		bool flag = false;
		for (auto& point : f_snake.snake)
		{
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y) || (tmp_x == x && tmp_y == y))
			{
				flag = true;
				break;
			}
		}
		if (flag)
			continue;

		flash_x = tmp_x;
		flash_y = tmp_y;
		SetCursorPosition(flash_x, flash_y);
		SetColor(15);
		cout << "☆";
		flash_food_flag = true;
		flash_flag = true;
		break;
	}
}

int Food::GetCnt()
{
	return cnt;
}

void Food::Food_flash()//闪烁食物
{
	SetCursorPosition(flash_x, flash_y);
	SetColor(15);
	if (flash_flag)
	{
		cout << "★";
		flash_flag = false;
	}
	else
	{
		cout << "☆";
		flash_flag = true;
	}

	SetCursorPosition(26, 0);
	SetColor(14);
	for (int i = 42; i >= progress_bar; --i)//进度条缩短
		cout << "\b \b";
	--progress_bar;
	if (progress_bar == 0) {
		SetCursorPosition(flash_x, flash_y);
		cout << "  ";
		flash_food_flag = false;
		flash_x = 0;
		flash_y = 0;
	}
}

bool Food::Getflashflag()
{
	return flash_food_flag;
}

int Food::Getprogressbar()
{
	return progress_bar;
}