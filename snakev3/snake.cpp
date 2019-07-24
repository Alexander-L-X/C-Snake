#include"stdafx.h"

void Snake::Star_snake()
{
	for (auto& point : snake)//��������Ԫ��
	{
		point.Print_snake();
	}
}

void Snake::Snake_add()
{
	switch (direction)
	{
	case Direction::UP:
		//ֱ������������һ��Ԫ��
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
	Point *head = new Point(snake.back().GetX(), snake.back().GetY());//���ͷ������
	for (auto& point : snake) //���������������ͷ����ͬ�����겻�����߳����߳��Լ�
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
	if (_kbhit())//�������Ƿ����û��¼�
	{
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			//�������Ҷ�Ӧ80 72 77 75 VK_LEFT 0x25 ��VK_UP 0x26��VK_RIGHT 0x27��VK_DOWN 0x28
			case 72:
				if (direction != Direction::DOWN)//��������뵱ǰ�˶������෴����Ч
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
			//ESC��ͣ
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