#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller
{
public:
	Controller() : speed(200), key(1), score(0) {}
	void Game_select();//选择界面
	void Game_draw();//绘制游戏界面
	int Game_play();//进行游戏
	void Game_score(const int&);//分数
	void Game_coutscore();//重新打印分数
	int Game_end();//菜单
	void Game();//主游戏
	int Game_over();//游戏结束界面
private:
	int speed;
	int key;
	int score;
};
#endif