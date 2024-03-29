// stdafx.cpp : 只包括标准包含文件的源文件
// snakev3.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

void HideCursor()//隐藏光标 
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void SetWindowSize(int cols, int lines)//设置窗口大小
{
	system("title 贪吃蛇");//设置窗口标题
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//图形占两个字符*2
	system(cmd);//设置窗口宽度和高度
}

void SetCursorPosition(const int x, const int y)//设置光标位置
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID)//设置文本颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//设置文本背景色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用
