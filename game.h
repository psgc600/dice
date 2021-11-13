class Player {
private:
	int point;	// “¾“_
	int dice;	// o‚½–Ú‚ğˆê“I‚É•Û‘¶
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