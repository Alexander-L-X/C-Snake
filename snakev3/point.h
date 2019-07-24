#ifndef POINT_H
#define POINT_H
class Point
{
public:
	Point() {}
	Point(const int x, const int y) : x(x), y(y) {}
	void Print_wall();//��ӡǽ
	void Print_snake();//��ӡ��
	void Clear();//�����Ϣ
	void ChangePosition(const int x, const int y);//�ı�����
	bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
	int GetX() { return this->x; }
	int GetY() { return this->y; }
private:
	int x, y;
};
#endif 