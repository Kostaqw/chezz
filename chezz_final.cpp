// chezz_final.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "figurs.cpp"

using namespace std;

    string desk[8][8];
    string bite[8][8];
    void Clear(string desk[8][8])
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                desk[i][j] = "N";
    }

    void ShowDesk(string desk[8][8])
    {
        for (int i = 0; i < 8; i++)
        {
            cout << "\n";
            for (int j = 0; j < 8; j++)
                cout << desk[i][j]<<" ";
        }
    }

int main()
{
    Clear(desk);
    Clear(bite);
    Elephant e1(6, 0, desk, bite);
    Elephant e2(7, 1, desk, bite);
    Horse h1(2, 6, desk, bite);
    Pawn p1(2, 5, desk, bite);
    King k1(0, 7, desk, bite);
    ShowDesk(desk);
    cout << "\n";
    ShowDesk(bite);
    cout << "\n";
    if (k1.shahEwryvare(bite))
    {
        cout << "Math";
    }
    else
        cout << "Not Math";
  
   
}



