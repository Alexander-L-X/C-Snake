#ifndef MAP_H
#define MAP_H
#include <vector>
#include "point.h"
#include<iostream>
using namespace std;
class Map
{
public:
	//����ѹ������cinmap
	Map()
	{
		cin_map.emplace_back(Point(1, 1));
		cin_map.emplace_back(Point(2, 1));
		cin_map.emplace_back(Point(3, 1));
		cin_map.emplace_back(Point(4, 1));
		cin_map.emplace_back(Point(5, 1));
		cin_map.emplace_back(Point(6, 1));
		cin_map.emplace_back(Point(7, 1));
		cin_map.emplace_back(Point(8, 1));
		cin_map.emplace_back(Point(9, 1));
		cin_map.emplace_back(Point(10, 1));
		cin_map.emplace_back(Point(11, 1));
		cin_map.emplace_back(Point(12, 1));
		cin_map.emplace_back(Point(13, 1));
		cin_map.emplace_back(Point(14, 1));
		cin_map.emplace_back(Point(15, 1));
		cin_map.emplace_back(Point(16, 1));
		cin_map.emplace_back(Point(17, 1));
		cin_map.emplace_back(Point(18, 1));
		cin_map.emplace_back(Point(19, 1));
		cin_map.emplace_back(Point(20, 1));
		cin_map.emplace_back(Point(21, 1));
		cin_map.emplace_back(Point(22, 1));
		cin_map.emplace_back(Point(23, 1));
		cin_map.emplace_back(Point(24, 1));
		cin_map.emplace_back(Point(25, 1));
		cin_map.emplace_back(Point(26, 1));
		cin_map.emplace_back(Point(27, 1));
		cin_map.emplace_back(Point(28, 1));
		cin_map.emplace_back(Point(29, 1));
		cin_map.emplace_back(Point(30, 1));
		cin_map.emplace_back(Point(1, 2));
		cin_map.emplace_back(Point(30, 2));
		cin_map.emplace_back(Point(1, 3));
		cin_map.emplace_back(Point(30, 3));
		cin_map.emplace_back(Point(1, 4));
		cin_map.emplace_back(Point(30, 4));
		cin_map.emplace_back(Point(1, 5));
		cin_map.emplace_back(Point(30, 5));
		cin_map.emplace_back(Point(1, 6));
		cin_map.emplace_back(Point(30, 6));
		cin_map.emplace_back(Point(1, 7));
		cin_map.emplace_back(Point(30, 7));
		cin_map.emplace_back(Point(1, 8));
		cin_map.emplace_back(Point(30, 8));
		cin_map.emplace_back(Point(1, 9));
		cin_map.emplace_back(Point(30, 9));
		cin_map.emplace_back(Point(1, 10));
		cin_map.emplace_back(Point(30, 10));
		cin_map.emplace_back(Point(1, 11));
		cin_map.emplace_back(Point(30, 11));
		cin_map.emplace_back(Point(1, 12));
		cin_map.emplace_back(Point(30, 12));
		cin_map.emplace_back(Point(1, 13));
		cin_map.emplace_back(Point(30, 13));
		cin_map.emplace_back(Point(1, 14));
		cin_map.emplace_back(Point(30, 14));
		cin_map.emplace_back(Point(1, 15));
		cin_map.emplace_back(Point(30, 15));
		cin_map.emplace_back(Point(1, 16));
		cin_map.emplace_back(Point(30, 16));
		cin_map.emplace_back(Point(1, 17));
		cin_map.emplace_back(Point(30, 17));
		cin_map.emplace_back(Point(1, 18));
		cin_map.emplace_back(Point(30, 18));
		cin_map.emplace_back(Point(1, 19));
		cin_map.emplace_back(Point(30, 19));
		cin_map.emplace_back(Point(1, 20));
		cin_map.emplace_back(Point(30, 20));
		cin_map.emplace_back(Point(1, 21));
		cin_map.emplace_back(Point(30, 21));
		cin_map.emplace_back(Point(1, 22));
		cin_map.emplace_back(Point(30, 22));
		cin_map.emplace_back(Point(1, 23));
		cin_map.emplace_back(Point(30, 23));
		cin_map.emplace_back(Point(1, 24));
		cin_map.emplace_back(Point(30, 24));
		cin_map.emplace_back(Point(1, 25));
		cin_map.emplace_back(Point(30, 25));
		cin_map.emplace_back(Point(1, 26));
		cin_map.emplace_back(Point(30, 26));
		cin_map.emplace_back(Point(1, 27));
		cin_map.emplace_back(Point(30, 27));
		cin_map.emplace_back(Point(1, 28));
		cin_map.emplace_back(Point(30, 28));
		cin_map.emplace_back(Point(1, 29));
		cin_map.emplace_back(Point(30, 29));
		cin_map.emplace_back(Point(1, 30));
		cin_map.emplace_back(Point(2, 30));
		cin_map.emplace_back(Point(3, 30));
		cin_map.emplace_back(Point(4, 30));
		cin_map.emplace_back(Point(5, 30));
		cin_map.emplace_back(Point(6, 30));
		cin_map.emplace_back(Point(7, 30));
		cin_map.emplace_back(Point(8, 30));
		cin_map.emplace_back(Point(9, 30));
		cin_map.emplace_back(Point(10, 30));
		cin_map.emplace_back(Point(11, 30));
		cin_map.emplace_back(Point(12, 30));
		cin_map.emplace_back(Point(13, 30));
		cin_map.emplace_back(Point(14, 30));
		cin_map.emplace_back(Point(15, 30));
		cin_map.emplace_back(Point(16, 30));
		cin_map.emplace_back(Point(17, 30));
		cin_map.emplace_back(Point(18, 30));
		cin_map.emplace_back(Point(19, 30));
		cin_map.emplace_back(Point(20, 30));
		cin_map.emplace_back(Point(21, 30));
		cin_map.emplace_back(Point(22, 30));
		cin_map.emplace_back(Point(23, 30));
		cin_map.emplace_back(Point(24, 30));
		cin_map.emplace_back(Point(25, 30));
		cin_map.emplace_back(Point(26, 30));
		cin_map.emplace_back(Point(27, 30));
		cin_map.emplace_back(Point(28, 30));
		cin_map.emplace_back(Point(29, 30));
		cin_map.emplace_back(Point(30, 30));
	}
	//��ͼ
	void Map_show();
private:
	vector<Point> cin_map;//�����ͼ
};
#endif