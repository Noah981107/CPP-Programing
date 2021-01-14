#pragma once
#include "NHS_�ǽ�08_Canvas.h"
#include "NHS_�ǽ�08_VariousMonsters.h"
#include "NHS_�ǽ�08_Matrix.h"
#include <windows.h>
#define MAXMONS 9

class MonsterWorld {                                         // Monster Ŭ���� ��ü b
	Matrix world;											 // Matrix Ŭ���� ��ü world
	int xMax, yMax, nMon, nMove;							 // ��� ���� xMax, yMax, nMon, nMove
	Monster* pMon[MAXMONS];									 // ������ ��ü�� �����Ҵ� �ϱ����Ͽ� ����Ʈ �迭 ���
	Canvas	canvas;											 // Canvas Ŭ���� ��ü canvas

	int& Map(int x, int y) { return world.elem(x, y); }		 // ������ ����Ǵ� �ʵ� ���
	bool isDone() { return countItems() == 0; }				 // ������ ���Ῡ�� Ȯ���ϴ� �Լ�
	int countItems() {										 // ������ ���ڸ� ��ȯ�ϴ� �Լ�
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;
		return nItems;
	}
	void print() {										     // ���� �ӿ��� ���Ͱ� Ȱ���ϴ� ��ü���� ȭ�� ��� �ϴ� �Լ�
		canvas.clear();
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "��");
		for (int i = 0; i < nMon; i++)
			pMon[i]->draw(canvas);
		canvas.print("[ Monster World (������ ��� �ͽ�) ]");

		cerr << " ��ü �̵� Ƚ�� = " << nMove << endl;
		cerr << " ���� ������ �� = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			pMon[i]->print();
	}
public:
	MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {   // �����ڸ� �̿��� ���� �� ����
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;  
	} 
	~MonsterWorld() {                                                            // �Ҹ��ڸ� �̿��� ���� �Ҵ� ����
		for (int i = 0; i < nMon; i++) 
			delete pMon[i];
	}
	void add(Monster* m) {                                                       // ������ ������ �߰��ϴ� �Լ�
		if (nMon < MAXMONS)
			pMon[nMon++] = m;
	}																			
	void play(int maxwalk, int wait) {										     // �������� ������ �����Ű�� �Լ�
		print();
		cerr << " ���͸� ��������...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {                                      // ���Ϳ� ���� ������ ����
			((Zombie*)pMon[0])->move(world.Data(), xMax, yMax);
			((Vampire*)pMon[1])->move(world.Data(), xMax, yMax);
			((KGhost*)pMon[2])->move(world.Data(), xMax, yMax);
			((Jiangshi*)pMon[3])->move(world.Data(), xMax, yMax);
			((Jiangshi*)pMon[4])->move(world.Data(), xMax, yMax);
			((Smombi*)pMon[5])->move(world.Data(), xMax, yMax);
			((Siangshi*)pMon[6])->move(world.Data(), xMax, yMax);
			((Siangshi*)pMon[7])->move(world.Data(), xMax, yMax);
			((HyunSeung*)pMon[8])->move(world.Data(), xMax, yMax);
			nMove++;
			print();
			if (isDone()) break;
			Sleep(wait);
		}
	}
};