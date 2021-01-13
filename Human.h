#pragma once
#include "NHS_�ǽ�11_Monster.h" 
#include <conio.h>                                                          // kbhit()�Լ��� ����ϱ� ����
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };				// �ƽ�Ű�ڵ忡 �ش��ϴ� ����Ű�� ��

class Human : public Monster {      										// Monster Ŭ������ ��ӵ� Human Ŭ����
public:
	Human(string n = "�̷��η�", string i = "��", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() { cout << " [Human   ]"; }										// �Ҹ��ڿ� [Human  ] ���
	int getDirKey() { return _getche() == 224 ? _getche() : 0; }			// �Էµ� Ű�� ȭ��ǥ�̸� ȭ��ǥ Ű ���� ��ȯ, �ƴϸ� 0 ��ȯ
	void move(int** map, int maxx, int maxy) {								// �Էµ� Ű���� ���� �ش��ϴ� ������ ����
		if (_kbhit()) {
			char ch = getDirKey();
			if (ch == Left) p[0]--;
			else if (ch == Right) p[0]++;
			else if (ch == Up) p[1]--;
			else if (ch == Down) p[1]++;
			else return;
			clip(maxx, maxy);
			eat(map);
		}
	}
};