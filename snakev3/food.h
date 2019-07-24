#ifndef FOOD_H
#define FOOD_H
#include "snake.h"
class Snake;
class Food
{
public:
	Food() : cnt(0), flash_flag(false), flash_food_flag(false), x(0), y(0), flash_x(0), flash_y(0), progress_bar(0) {}
	void Food_draw(Snake&);//打印食物
	void Food_flash_draw(Snake&);//打印闪光食物
	int GetCnt();
	void Food_flash();//闪烁食物
	bool Getflashflag();
	int Getprogressbar();
private:
	int cnt;
	bool flash_flag;//闪烁标记
	bool flash_food_flag;//是否有闪光食物标记
	int x, y;
	int flash_x, flash_y;
	int progress_bar;//闪光进度条长度
	friend class Snake;
};
#endif 