#include"stdafx.h"
void Map::Map_show()//��ͼ
{
	for (auto& point : cin_map)
	{
		point.Print_wall();
		/*ϵͳSleep()
		�ɸ��ݾ�����ʾ����Ҫ�Ļ����ٶ�
		�ڴ�Ϊ����ʾ�趨ֱ�Ӵ�ӡ��ͼ*/
		Sleep(0);
	}
}