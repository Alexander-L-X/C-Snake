#include"stdafx.h"
void Point::Print_wall()
{
	SetCursorPosition(x, y);
	cout << "▓";
}

void Point::Print_snake()
{
	SetCursorPosition(x, y);
	cout << "●";
}

void Point::Clear()
{
	SetCursorPosition(x, y);
	cout << "  ";
}

void Point::ChangePosition(const int x, const int y)
{
	this->x = x;
	this->y = y;
}