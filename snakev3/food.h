#ifndef FOOD_H
#define FOOD_H
#include "snake.h"
class Snake;
class Food
{
public:
	Food() : cnt(0), flash_flag(false), flash_food_flag(false), x(0), y(0), flash_x(0), flash_y(0), progress_bar(0) {}
	void Food_draw(Snake&);//��ӡʳ��
	void Food_flash_draw(Snake&);//��ӡ����ʳ��
	int GetCnt();
	void Food_flash();//��˸ʳ��
	bool Getflashflag();
	int Getprogressbar();
private:
	int cnt;
	bool flash_flag;//��˸���
	bool flash_food_flag;//�Ƿ�������ʳ����
	int x, y;
	int flash_x, flash_y;
	int progress_bar;//�������������
	friend class Snake;
};
#endif 