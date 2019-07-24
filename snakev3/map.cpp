#include"stdafx.h"
void Map::Map_show()//绘图
{
	for (auto& point : cin_map)
	{
		point.Print_wall();
		/*系统Sleep()
		可根据具体显示你需要的绘制速度
		在此为了演示设定直接打印地图*/
		Sleep(0);
	}
}