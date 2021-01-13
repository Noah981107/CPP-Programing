#pragma once
#include <iostream>
#include <string>
#include "NHS_�ǽ�11_Point.h"			
#define MAXLINES 100
using namespace std;

class Canvas {														
	string line[MAXLINES];                                         // ȭ�� ����� ���� ���ڿ�
	int xMax, yMax;												   // ���� ũ��
public:
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {		   // ���Ͱ� ������ ĵ������ ����Ʈ �Ű������� �̿��� �ʱ�ȭ
		for (int y = 0; y < yMax; y++)
			line[y] = string(xMax * 2, ' ');
	}
	void draw(int x, int y, string val) {						   // ���Ͱ� ������ ȭ���� �׸��� �Լ�
		if (x >= 0 && y >= 0 && x < xMax && y < yMax)
			line[y].replace(x * 2, 2, val);
	}

	void draw(Point& p, string val) { draw(p.x, p.y, val); }       // draw �Լ��� �ߺ��Ͽ� ���Ͱ� ������ ȭ���� �׸��� �Լ�

	void clear(string val = ". ") {                                // ���� ������ ȭ���� �ʱ�ȭ �ϴ� �Լ�
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				draw(x, y, val);
	}
	void print(const char* title = "<My Canvas>") {				   // ���Ͱ� ������ ��ü ���� ȭ���� ����ϴ� �Լ�
		system("cls");
		cout << title << endl;
		for (int y = 0; y < yMax; y++)
			cout << line[y] << endl;
		cout << endl;
	}
};