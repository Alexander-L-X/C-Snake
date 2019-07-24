#ifndef SNAKE_H
#define SNAKE_H
#include <deque>//设置一个双端队列
#include "point.h"
#include "food.h"

class Snake
{
public:
	enum Direction { UP, DOWN, LEFT, RIGHT };//枚举限定上下左右
	//初始化一条长度为一的蛇于中央默认方向向右
	Snake() {
		snake.emplace_back(15, 15);
		direction = Direction::RIGHT;
	}
	void Star_snake();//初始化蛇
	void Snake_add();//蛇增长
	void Snake_move();//蛇移动头变长
	bool Snake_wall();//超出边界
	bool Snake_oneself();//吃自己
	bool ChangeDirection();//改变方向
	bool Snake_e_food(const Food&);//吃食物
	bool Snake_e_flashfood(Food&);//吃闪光食物
private:
	deque<Point> snake;
	Direction direction;
	//食物类设为友元只有蛇可访问其私有定义类型
	friend class Food;
};
#endif