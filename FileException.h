#pragma once
#include <string>
class FileException {	                                                 // ���� ���� Ŭ����
	string filename;													 // ���� �̸�
	bool bRead;		        											 // ���� ���
public:
	FileException(string name, bool b) : filename(name), bRead(b) {}     // �����ڸ� �̿��� ������� �ʱ�ȭ
};