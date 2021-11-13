#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

Player::Player()
{
	point = 0;
}
int Player::showDice()
{
	return dice;
}
void Player::setPoint(int p)
{
	point += p;
}

int Player::getPoint()
{
	return point;
}
void Player::playDice()
{
	dice = rand() % 6 + 1;
}
Game::Game()
{
	int count;
	Human h;
	Enemy e;
	cout << "サイコロゲーム\n";
	cout << "遊び方：ENTERキーでサイコロを振ります。\n";
	cout << "あなたとコンピュータの、どちらが多く得点できるでしょうか？\n";
	cout << "それではスタート！\n\n";

	cout << "何回サイコロを振りますか？> ";
	cin >> count;
	if (count < 1) {
		cout << "やめるの？\n";
		return;
	}
	fightRound(count, &h, &e);
	screenResult(&h, &e);
}

void Game::fightRound(int r, Human *h, Enemy *e)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < r; i++) {
		cout << "--------------------\n";
		cout << i + 1 << "回戦目！[ENTER]\n";
		getchar();
		cout << "あなたの番です。\n";
		cout << "ENTERキーを押すとサイコロを振ります。[ENTER]\n\n";
		getchar();
		cout << "・・・・・・・・・・・・。\n\n";
		Sleep(1000);
		h->playDice();
		cout << h->showDice() << "の目が出ました！\n";
		h->setPoint(h->showDice());

		cout << "コンピュータの番です。[ENTER]\n";
		getchar();
		cout << "・・・・・・・・・・・・。\n\n";
		Sleep(1000);

		e->playDice();
		cout << e->showDice() << "の目が出ました！\n";
		e->setPoint(e->showDice());

		cout << "あなたの得点：" << h->getPoint() << "\t";
		cout << "コンピュータの得点：" << e->getPoint() << "\n";
	}
}

void Game::screenResult(Human *h, Enemy *e)
{
	cout << "\n\t※\t※\t※\n\n";
	if (h->getPoint() > e->getPoint())
		cout << "あなたの勝ちです！おめでとう！\n";
	else if (h->getPoint() == e->getPoint())
		cout << "引き分けです。もう一度挑戦してね。\n";
	else
		cout << "残念、コンピュータの勝ちです。\n";
}