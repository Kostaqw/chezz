#include "figure.cpp"
#include <iostream>

using namespace std;

class Pawn : public figure
{
	
public:
	Pawn(int x, int y, string desk[8][8], string canBite[8][8]) : figure(x, y, "P")
	{
		//Присваимаем имя и размещаем на доске
		desk[x][y] = 'P';
		// помечаем клетки которые может бить фигуры, заполняя полученный массив
		if ((x < 8) && (y < 8))
		{
			if (y == 0)
			{
				canBite[x - 1][y + 1] = "+";
			}
			else if (y == 7)
			{
				canBite[x - 1][y - 1] = "+";
			}
			else if (y > 0)
			{
				canBite[x - 1][y + 1] = "+";
				canBite[x - 1][y - 1] = "+";
			}
		}
	};

};

class Horse : public figure
{
public:
	Horse(int x, int y, string desk[8][8], string canBite[8][8]) : figure(x, y, "H")
	{
		//Присваимаем имя и размещаем на доске
		desk[x][y] = 'H';

		// помечаем клетки которые может бить фигуры, заполняя полученный массив
		//2 верх 1 право
		if (((x - 2 >= 0) && ((x - 2 < 8))) && ((y + 1 > 0) && ((y + 1 < 8))))
		{
				canBite[x - 2][y + 1] = "+";
		}
		//2 верх 1 лево
		if (((x - 2 >= 0) && ((x - 2 < 8))) && ((y - 1 > 0) && ((y - 1 < 8))))
		{
			canBite[x - 2][y - 1] = "+";
		}
		//1 верх 2 лево
		if (((x - 1 >= 0) && ((x - 1 < 8))) && ((y - 2 > 0) && ((y - 2 < 8))))
		{
			canBite[x - 1][y - 2] = "+";
		}
		//1 низ 2 лево
		if (((x + 1 >= 0) && ((x + 1 < 8))) && ((y - 2 > 0) && ((y - 2 < 8))))
		{
			canBite[x + 1][y - 2] = "+";
		}
		//2 низ 1 лево
		if (((x + 2 >= 0) && ((x + 2 < 8))) && ((y - 1 > 0) && ((y - 1 < 8))))
		{
			canBite[x + 2][y - 1] = "+";
		}
		//2 низ 1 право
		if (((x + 2 >= 0) && ((x + 2 < 8))) && ((y + 1 > 0) && ((y + 1 < 8))))
		{
			canBite[x + 2][y + 1] = "+";
		}
		//1 низ 2 право
		if (((x + 1 >= 0) && ((x + 1 < 8))) && ((y + 2 > 0) && ((y + 2 < 8))))
		{
			canBite[x + 1][y + 2] = "+";
		}
		//1 верх 2 право
		if (((x - 1 >= 0) && ((x - 1 < 8))) && ((y + 2 > 0) && ((y + 2 < 8))))
		{
			canBite[x - 1][y + 2] = "+";
		}

	};
};

class Elephant : public figure
{
public:
	Elephant(int x, int y, string desk[8][8], string canBite[8][8]) : figure(x, y, "E")
	{
		//Присваимаем имя и размещаем на доске
		// помечаем клетки которые может бить фигуры, заполняя полученный массив
		desk[x][y] = 'E';
		
		//с лева на право
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				if (i + j == x + y)
					canBite[i][j] = "+";
		}

		//с права на лево
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				if (i - j == x-y)
					canBite[i][j] = "+";
		}
		
	
	};
};

class Tower : public figure
{
public:
	Tower(int x, int y, string desk[8][8], string canBite[8][8]) : figure(x, y, "T")
	{
		//Присваимаем имя и размещаем на доске
		// помечаем клетки которые может бить фигуры, заполняя полученный массив
		desk[x][y] = 'T';

		//горизонт
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				if (i  == x)
					canBite[i][j] = "+";
		}
		//вертикаль
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				if (j == y)
					canBite[i][j] = "+";
		}

	};
};
class Quin : public figure
{
public:
	Quin(int x, int y, string desk[8][8], string canBite[8][8]) : figure(x, y, "Q")
	{	//Присваимаем имя и размещаем на доске
		// помечаем клетки которые может бить фигуры, заполняя полученный массив
		desk[x][y] = 'Q';

		//горизонт
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				if (i == y)
					canBite[i][j] = "+";
		}
		//вертикаль
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				if (j == x)
					canBite[i][j] = "+";
		}
		//с лева на право
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				if (i + j == x + y)
					canBite[i][j] = "+";
		}

		//с права на лево
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				if (i - j == x - y)
					canBite[i][j] = "+";
		}
	};
};

class King : public figure
{
public:
	int posX;
	int posY;
	string desk[8][8];
	string canBite[8][8];
	
	King(int x, int y, string desk[8][8], string canBite[8][8]) : figure(x, y, "K")
	{
		//Присваимаем имя и размещаем на доске
		desk[x][y] = 'K';
		this->posX = x;
		this->posY = y;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				this->desk[i][j] = desk[i][j];
				this->canBite[i][j] = canBite[i][j];
			}
		}
		

	}

	bool Math (string desk[8][8], string canBite[8][8])
	{
		//для временного хранения позиции
		int tmpX;
		int tmpY;

		//проврека на шах
		if (shahEwryvare(canBite))
		{
			cout << "Math";
			return true;
		}

		if (shah(canBite))
			if (!haveNear(desk))
			{
				cout << "Math";
				return true;
			}
		cout << "not Math";
	return true;
	}

	//метод провреки на шах
	bool shah(string canBite[8][8])
	{
		if (canBite[y][x] == "+")
			return true;
		return false;
	}

	//проверка на шах во всех окружающих клетках.
	bool shahEwryvare(string canBite[8][8])
	{
		bool pos[9] = { false };
		int count=0;
		if (canBite[x][y] == "+" || y>7 || x>7 || y<0 || x<0)
		{
			pos[0] = true;
			/*cout << "1 условия" << "\n";
			canBite[y][x] = "1";*/
		}
		if (canBite[x-1][y] == "+" || y > 7 || x-1 > 7 || y < 0 || x-1 < 0)
		{
			pos[1] = true;
			/*cout << "2 условия" << "\n";
			canBite[y-1][x] = "2";*/
		}
		if (canBite[x-1][y+1] == "+" || y+1 > 7 || x-1 > 7 || y+1 < 0 || x-1 < 0)
		{
			pos[2] = true;
			/*cout << "3 условия" << "\n";
			canBite[y-1][x+1] = "3";*/
		}
		if (canBite[x][y+1] == "+" || y+1 > 7 || x > 7 || y+1 < 0 || x < 0)
		{
			pos[3] = true;
			/*cout << "4 условия" << "\n";
			canBite[y][x+1] = "4";*/
		}
		if (canBite[x+1][y+1] == "+" || y+1 > 7 || x+1 > 7 || y+1 < 0 || x+1 < 0)
		{
			pos[4] = true;
			/*cout << "5 условия" << "\n";
			canBite[y+1][x+1] = "5";*/
		}
		if (canBite[x+1][y] == "+" || y > 7 || x+1 > 7 || y < 0 || x+1 < 0)
		{
			pos[5] = true;
			/*cout << "6 условия" << "\n";
			canBite[y+1][x] = "6";*/
		}
		if (canBite[x+1][y-1] == "+" || y-1 > 7 || x+1 > 7 || y-1 < 0 || x+1 < 0)
		{
			pos[6] = true;
			/*cout << "7 условия" << "\n";
			canBite[y+1][x-1] = "7";*/
		}
		if (canBite[x][y - 1] == "+" || y-1 > 7 || x > 7 || y-1 < 0 || x < 0)
		{
			pos[7] = true;
			/*cout << "8 условия" << "\n";
			canBite[y][x-1] = "8";*/
		}
		if (canBite[x - 1][y - 1] == "+" || y-1 > 7 || x-1 > 7 || y-1 < 0 || x-1 < 0)
		{
			pos[8] = true;
			/*cout << "9 условия" << "\n";
			canBite[y-1][x-1] = "9";*/
		}
		for (int i = 0; i < 9; i++)
		{
			if (pos[i])
			{
				count++;
				
			}

		}
		
		if(count == 9)
			return true;
		return false;
	}
	//метод провреки есть ли рядом фигура
	bool haveNear(string desk[8][8])
	{
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				if (desk[i][j] != "N")
					return true;
		}
		return false;
	}
	
	//метод провреки возможности уйти
	bool canMove(string desk[8][8], string canBite[8][8])
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				if (desk[i][j] != "N")
					return true;
		}
		return false;
	}

};