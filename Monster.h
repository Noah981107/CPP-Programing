#pragma once
#include "NHS_�ǽ�08_Canvas.h"
#define DIM 40

class Monster {
protected:
	string name, icon;	                         // ���� �̸��� ȭ�� ��¿� ������
	int x, y, nItem; 	                         // ���� ��ġ�� ���� ������ ��

	void clip(int maxx, int maxy) {              // ���Ͱ� ������ ������ �ʰ� �ϴ� �Լ�
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;
	} 
	void eat(int** map) {                        // ���Ͱ� �������� �Դ� �Լ�
		if (map[y][x] == 1) {
			map[y][x] = 0;
			nItem++;
		}
	}
public:
	Monster(string n = "������", string i = "��", int px = 0, int py = 0)  // ������ ����Ʈ �Ű������� �̿��� �ʱ�ȭ
		: name(n), icon(i), x(px), y(py), nItem(0) {}
	~Monster() { cout << "\t" << name << icon << " �������ϴ�~~~\n"; }     // �Ҹ��ڸ� �̿��� ���� ���

	void draw(Canvas& canvas) { canvas.draw(x, y, icon); }                 // ���Ͱ� ������ ȭ���� �׸��� �Լ�
	void move(int** map, int maxx, int maxy) {                             // ���Ͱ� �����̴� �Լ� 8������ �������� ������
		switch (rand() % 8) {
		case 0: y--; break;
		case 1: x++; y--; break;
		case 2: x++; break;
		case 3: x++; y++; break;
		case 4: y++; break;
		case 5: x--; y++; break;
		case 6: x--; break;
		case 7: x--; y--; break;
		}
		clip(maxx, maxy);
		eat(map);
	}
	void print() { cout << "\t" << name << icon << ":" << nItem << endl; }  // ���Ϳ� ���� ���� ���
};