#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller
{
public:
	Controller() : speed(200), key(1), score(0) {}
	void Game_select();//ѡ�����
	void Game_draw();//������Ϸ����
	int Game_play();//������Ϸ
	void Game_score(const int&);//����
	void Game_coutscore();//���´�ӡ����
	int Game_end();//�˵�
	void Game();//����Ϸ
	int Game_over();//��Ϸ��������
private:
	int speed;
	int key;
	int score;
};
#endif