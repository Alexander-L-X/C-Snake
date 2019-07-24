#include"stdafx.h"

void Snake::Star_snake()
{
	for (auto& point : snake)//依次引用元素
	{
		point.Print_snake();
	}
}

void Snake::Snake_add()
{
	switch (direction)
	{
	case Direction::UP:
		//直接在容器后构造一个元素
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 1));
		break;
	case Direction::DOWN:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 1));
		break;
	case Direction::LEFT:
		snake.emplace_back(Point(snake.back().GetX() - 1, snake.back().GetY()));
		break;
	case Direction::RIGHT:
		snake.emplace_back(Point(snake.back().GetX() + 1, snake.back().GetY()));
		break;
	default:
		break;
	}
	SetColor(26);
	snake.back().Print_snake();
}

void Snake::Snake_move()
{
	Snake_add();
	snake.front().Clear();
	snake.pop_front();
}

bool Snake::Snake_wall()
{
	return snake.back().GetX() < 30 &&
		snake.back().GetY() < 30 &&
		snake.back().GetX() > 1 &&
		snake.back().GetY() > 1;
}

bool Snake::Snake_oneself()
{
	deque<Point>::size_type cnt = 1;
	Point *head = new Point(snake.back().GetX(), snake.back().GetY());//获得头部坐标
	for (auto& point : snake) //如果整条蛇中与蛇头不相同的坐标不等于蛇长，蛇吃自己
	{
		if (!(point == *head))
			++cnt;
		else
			break;
	}
	delete head;
	if (cnt == snake.size())
		return true;
	else
		return false;
}

bool Snake::ChangeDirection()
{
	char ch;
	if (_kbhit())//检查键盘是否有敲击事件
	{
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			//上下左右对应80 72 77 75 VK_LEFT 0x25 ；VK_UP 0x26；VK_RIGHT 0x27；VK_DOWN 0x28
			case 72:
				if (direction != Direction::DOWN)//如果方向与当前运动方向相反，无效
					direction = Direction::UP;
				break;
			case 80:
				if (direction != Direction::UP)
					direction = Direction::DOWN;
				break;
			case 75:
				if (direction != Direction::RIGHT)
					direction = Direction::LEFT;
				break;
			case 77:
				if (direction != Direction::LEFT)
					direction = Direction::RIGHT;
				break;
			default:
				break;
			}
			return true;
			//ESC暂停
		case 27:
			return false;

		default:
			return true;

		}
	}
	return true;
}

bool Snake::Snake_e_food(const Food& e_food)
{
	if (snake.back().GetX() == e_food.x && snake.back().GetY() == e_food.y)
		return true;
	else
		return false;
}

bool Snake::Snake_e_flashfood(Food& e_food)
{
	if (snake.back().GetX() == e_food.flash_x && snake.back().GetY() == e_food.flash_y)
	{
		e_food.flash_food_flag = false;
		e_food.flash_x = 0;
		e_food.flash_y = 0;
		SetCursorPosition(1, 0);
		cout << "                                                            ";
		return true;
	}
	else
		return false;
}