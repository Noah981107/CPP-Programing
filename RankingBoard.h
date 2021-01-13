#pragma once
#include <iostream>
#include <fstream>
#include "NHS_�ǽ�11_FileException.h"
using namespace std;
#define NUM_MVP	5

struct PlayInfo {		                                              // ���� ���� Ŭ����
	string name;		                                              // ���̸��� �̸�
	int nItem;		                                                  // ȹ���� �������� ��
	double itemPerMove;	                                              // �̵� �Ÿ��� ������ ��
	PlayInfo(string na = "���η�", int ni = 0, double ipm = 0.0)      // �����ڿ� ����Ʈ �Ű������� �̿��� ��� �ʱ�ȭ ����Ʈ ���
		: name(na), nItem(ni), itemPerMove(ipm) {}
};

class RankingBoard {		                                          // ��ŷ ���� Ŭ����
	PlayInfo MVP[NUM_MVP];                                            // �÷��̾��� ������ �����ϴ� Ŭ����
	int nMVP = NUM_MVP;                                               // �÷��̾� ����
public:
	void load(string filename) {                                      // ������ ���� �Լ�
		ifstream is;                
		is.open(filename);
		if (!is) 
			throw(FileException(filename, true));                     // ������ ������ ���� �� ���� ó�� -> catch�� �Ѿ
		for (int i = 0; i < nMVP; i++)
			is >> MVP[i].nItem >> MVP[i].name >> MVP[i].itemPerMove;
		is.close();
	}
	void store(string filename) {                                     // ���Ͽ� �����ϴ� �Լ�
		ofstream os;
		os.open(filename);
		if (!os)
			throw(FileException(filename, false));                    // ���Ͽ� ������ �� ���� �� ���� ó�� -> catch�� �Ѿ
		for (int i = 0; i < nMVP; i++)
			os << MVP[i].nItem << " " << MVP[i].name << " "
			<< MVP[i].itemPerMove << "\n";
		os.close();
	}
	void print(string title = "���� ��ŷ") {                          // ���� ���ȭ�� ����ϴ� �Լ�
		cout << endl << title << endl;
		for (int i = 0; i < nMVP; i++)
			cout << "[" << i + 1 << "��] " << MVP[i].name << "\t"
			<< MVP[i].nItem << " " << MVP[i].itemPerMove << "\n";
		cout << "���͸� �Է��ϼ���.";
		getchar();
		cout << endl;
	}
	int add(int nItem, double ipm) {                                  // ����� ������ �߰��ϴ� �Լ�
		if (nItem <= MVP[nMVP - 1].nItem) return 0;

		int pos = nMVP - 1;
		for (; pos > 0; pos--) {
			if (nItem <= MVP[pos - 1].nItem) break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nItem = nItem;
		MVP[pos].itemPerMove = ipm;
		cout << "\n[" << pos + 1 << "��] �̸��� �Է��ϼ���: ";
		cin >> MVP[pos].name;
		return pos + 1;
	}
};