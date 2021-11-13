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
	cout << "�T�C�R���Q�[��\n";
	cout << "�V�ѕ��FENTER�L�[�ŃT�C�R����U��܂��B\n";
	cout << "���Ȃ��ƃR���s���[�^�́A�ǂ��炪�������_�ł���ł��傤���H\n";
	cout << "����ł̓X�^�[�g�I\n\n";

	cout << "����T�C�R����U��܂����H> ";
	cin >> count;
	if (count < 1) {
		cout << "��߂�́H\n";
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
		cout << i + 1 << "���ځI[ENTER]\n";
		getchar();
		cout << "���Ȃ��̔Ԃł��B\n";
		cout << "ENTER�L�[�������ƃT�C�R����U��܂��B[ENTER]\n\n";
		getchar();
		cout << "�E�E�E�E�E�E�E�E�E�E�E�E�B\n\n";
		Sleep(1000);
		h->playDice();
		cout << h->showDice() << "�̖ڂ��o�܂����I\n";
		h->setPoint(h->showDice());

		cout << "�R���s���[�^�̔Ԃł��B[ENTER]\n";
		getchar();
		cout << "�E�E�E�E�E�E�E�E�E�E�E�E�B\n\n";
		Sleep(1000);

		e->playDice();
		cout << e->showDice() << "�̖ڂ��o�܂����I\n";
		e->setPoint(e->showDice());

		cout << "���Ȃ��̓��_�F" << h->getPoint() << "\t";
		cout << "�R���s���[�^�̓��_�F" << e->getPoint() << "\n";
	}
}

void Game::screenResult(Human *h, Enemy *e)
{
	cout << "\n\t��\t��\t��\n\n";
	if (h->getPoint() > e->getPoint())
		cout << "���Ȃ��̏����ł��I���߂łƂ��I\n";
	else if (h->getPoint() == e->getPoint())
		cout << "���������ł��B������x���킵�ĂˁB\n";
	else
		cout << "�c�O�A�R���s���[�^�̏����ł��B\n";
}