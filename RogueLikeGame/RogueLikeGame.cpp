#include <iostream>
#include<cstdlib> // = <stdlib.h>
#include<Windows.h>
using namespace std;

// 지도 배열
char map[5][6] = {
    "#####",
    "#   #",
    "# # #",
    "#M Y#",
    "#####"
};

// 주인공 좌표
int mainY = 1;
int mainX = 1;

void printAll()
{
    // 화면 클리어 함수
    // 출력과 클리어를 반복하면 깜빡거리는 효과를 볼 수 있다
    system("cls");

    // 2중 for문 map 전체 출력
    for (int y = 0; y < 5; y++)
    {
        // null 문자 제외
        for (int x = 0; x < 5; x++)
        {
            if (y == mainY && x == mainX) cout << "@";
            else cout << map[y][x];
        }
        cout << endl;
    }
}


int main()
{
    system("color 3F");
    // 사용자가 종료하기 전까지 무한 반복
    while(1)
    {
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {

                if (GetAsyncKeyState(VK_UP) & 0x8001)
                {
                    if(map[mainY-1][mainX] != '#') mainY--;

                }

                if (GetAsyncKeyState(VK_DOWN) & 0x8001 != 0)
                {

                    if (map[mainY + 1][mainX] != '#') mainY++;

                }

                if (GetAsyncKeyState(VK_LEFT) & 0x8001 != 0)
                {
                    if (map[mainY][mainX-1] != '#') mainX--;

                }

                if (GetAsyncKeyState(VK_RIGHT) & 0x8001 != 0)
                {
                    if (map[mainY][mainX+1] != '#') mainX++;

                }

                if (map[mainY][mainX] == 'M')
                {
                    printAll();
                    for (int i = 0; i < 5; i++)
                    {
                        system("color 3F");
                        Sleep(30);
                        system("color 0F");
                        Sleep(70);
                    }
                    system("color 0F");
                    Sleep(300);
                    system("cls");
                    cout << "\n\n\n\n\tGAME OVER\n\n\n\n\n";
                    return 0;
                }

                if (map[mainY][mainX] == 'Y')
                {
                    printAll();
                    for (int i = 0; i < 5; i++)
                    {
                        system("color 3F");
                        Sleep(30);
                        system("color 1F");
                        Sleep(70);
                    }
                    system("color 1F");
                    Sleep(300);
                    system("cls");
                    cout << "\n\n\n\n\tYou Win!!!\n\n\n\n\n";
                    return 0;
                }

                Sleep(100);

                printAll();
               
            }
        }
        
    }

}
