#ifndef POINT_H
#define POINT_H
class Point
{
public:
	Point() {}
	Point(const int x, const int y) : x(x), y(y) {}
	void Print_wall();//打印墙
	void Print_snake();//打印蛇
	void Clear();//清除信息
	void ChangePosition(const int x, const int y);//改变坐标
	bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
	int GetX() { return this->x; }
	int GetY() { return this->y; }
private:
	int x, y;
};
#endif 