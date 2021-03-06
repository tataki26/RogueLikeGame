#include <iostream>
#include<cstdlib> // = <stdlib.h>
#include<Windows.h>
using namespace std;

const int N = 20;

char map[N][N + 1] =
{
"####################",
"# # ^ #Y  ###Ma ^^#",
"# ^ M  ##M#######^##",
"#####M  #^     M#  #",
"#  ^   #MM M#M  ^^#",
"#  ##^ #^  ^#####  #",
"#M  ^^#M #MY^ ^## M#",
"# ^# M#^ ###^   #^M#",
"# ^# ^M M### # M#  #",
"#  #Ma#  MYM # ^#M^#",
"# ^  Ma# ###^#M^#  #",
"#^###### ###^#^^^  #",
"#^## M ^  ^ ^ ###  #",
"#^## ^^##M#a# ##  ##",
"#^## ^#^^Y#######^^#",
"#^   ## ###M #   ^^#",
"# ###aM^ ^^^^  # ###",
"# ########### ^#  ##",
"#             ^#M aM",
"####################",
};

// 주인공 좌표
int mainY = 1;
int mainX = 1;
int hp = 100;

void printAll()
{
    // 화면 클리어 함수
    // 출력과 클리어를 반복하면 깜빡거리는 효과를 볼 수 있다
    system("cls");

    // 2중 for문 map 전체 출력
    for (int y = 0; y < N; y++)
    {
        // null 문자 제외
        for (int x = 0; x < N; x++)
        {
            if (y == mainY && x == mainX)
            {
                cout << "♀";
            }
            else if (map[y][x] == ' ')
            {
                cout << "  ";
            }
            else if (map[y][x] == 'a')
            {
                cout << "♥";
            }
            else if (map[y][x] == '^')
            {
                cout << "♨";
            }
            else if (map[y][x] == '#')
            {
                cout << "■";
            }
            else if (map[y][x] == 'Y')
            {
                cout << "δ";
            }
            else if (map[y][x] == 'M')
            {
                cout << "Ω";
            }
        }
        cout << "\n"; // endl보다 \n이 좀 더 빠름
    }

    cout << "HP: " << hp << "\n";

}


int main()
{
    system("color 3F");
    // 사용자가 종료하기 전까지 무한 반복
    while (1)
    {
        printAll();

        if (GetAsyncKeyState(VK_UP) & 0x8001)
        {
            if (map[mainY - 1][mainX] == '^') hp -= 10;
            if (map[mainY - 1][mainX] != '#') mainY--;

        }

        else if (GetAsyncKeyState(VK_DOWN) & 0x8001 != 0)
        {
            if (map[mainY + 1][mainX] == '^') hp -= 10;
            if (map[mainY + 1][mainX] != '#') mainY++;

        }

        else if (GetAsyncKeyState(VK_LEFT) & 0x8001 != 0)
        {
            if (map[mainY][mainX - 1] == '^') hp -= 10;
            if (map[mainY][mainX - 1] != '#') mainX--;

        }

        else if (GetAsyncKeyState(VK_RIGHT) & 0x8001 != 0)
        {
            if (map[mainY][mainX + 1] == '^') hp -= 10;
            if (map[mainY][mainX + 1] != '#') mainX++;

        }

        if (map[mainY][mainX] == 'M' || hp == 0)
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
            cout << "\n\n\n\n\t  You Win!!!\n\n";
            cout << "\tYour Score: " << hp << "\n\n\n\n";
            return 0;
        }

        if (map[mainY][mainX] == 'a')
        {
            hp = 100;
            map[mainY][mainX] = ' ';

        }

        Sleep(100);

        printAll();

    }
}
