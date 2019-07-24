#ifndef SNAKE_H
#define SNAKE_H
#include <deque>//����һ��˫�˶���
#include "point.h"
#include "food.h"

class Snake
{
public:
	enum Direction { UP, DOWN, LEFT, RIGHT };//ö���޶���������
	//��ʼ��һ������Ϊһ����������Ĭ�Ϸ�������
	Snake() {
		snake.emplace_back(15, 15);
		direction = Direction::RIGHT;
	}
	void Star_snake();//��ʼ����
	void Snake_add();//������
	void Snake_move();//���ƶ�ͷ�䳤
	bool Snake_wall();//�����߽�
	bool Snake_oneself();//���Լ�
	bool ChangeDirection();//�ı䷽��
	bool Snake_e_food(const Food&);//��ʳ��
	bool Snake_e_flashfood(Food&);//������ʳ��
private:
	deque<Point> snake;
	Direction direction;
	//ʳ������Ϊ��Ԫֻ���߿ɷ�����˽�ж�������
	friend class Food;
};
#endif