class Player {
private:
	int point;	// 得点
	int dice;	// 出た目を一時的に保存
public:
	Player();
	void playDice();
	int showDice();
	void setPoint(int p);
	int getPoint();
};

class Human : public Player {};
class Enemy : public Player {};

class Game {
private:
	int count;
public:
	Game();
	void fightRound(int r, Human *h, Enemy *e);
	void screenResult(Human *h, Enemy *e);
};