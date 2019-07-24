// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

// TODO: 在此处引用程序需要的其他头文件
#pragma once
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include "controller.h"
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <deque>
#include <vector>
#include "controller.h"
#include "map.h"
#include "snake.h"
#include "food.h"
#include "point.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void HideCursor();//隐藏光标 
void SetWindowSize(int cols, int lines);
void SetCursorPosition(const int x, const int y);
void SetColor(int colorID);
void SetBackColor();
