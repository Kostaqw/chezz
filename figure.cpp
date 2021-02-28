#include <iostream>
#include <string>

using namespace std;

class figure
{
public:
	
	int x;
	int y;
	string name;

	//�����������
	figure(int x, int y, string name)
	{
		
		this->x = x;
		this->y = y;
		this->name = name;
		
	}

	//����� ������ ������
	void show()
	{
		cout << convert(x, y) + "_" + name;
	}

	
	// ����� ��� ����������� ������� ������ � ���������� ������
private:
	string convert(int x, int y)
	{
		char symb;

		switch (x)
		{
		case 0: {symb = 'a'; break; }
		case 1: {symb = 'b';break; }
		case 2: {symb = 'c';break; }
		case 3: {symb = 'd';break; }
		case 4: {symb = 'e'; break; }
		case 5: {symb = 'f'; break; }
		case 6: {symb = 'g'; break; }
		case 7: {symb = 'h'; break; }
		default: {symb = 'q'; break; }
		}
		string result = symb + to_string(y);
		return result;
	}
};

