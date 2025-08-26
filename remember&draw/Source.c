#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80


#pragma region 패턴들
      int heart12x12[12][12] = {
         { 0,0,0,1,1,0,0,1,1,0,0,0 },
         { 0,0,1,1,1,1,1,1,1,1,0,0 },
         { 0,1,1,1,1,1,1,1,1,1,1,0 },
         { 1,1,1,1,1,1,1,1,1,1,1,1 },
         { 1,1,1,1,1,1,1,1,1,1,1,1 },
         { 0,1,1,1,1,1,1,1,1,1,1,0 },
         { 0,0,1,1,1,1,1,1,1,1,0,0 },
         { 0,0,0,1,1,1,1,1,1,0,0,0 },
         { 0,0,0,0,1,1,1,1,0,0,0,0 },
         { 0,0,0,0,0,1,1,0,0,0,0,0 },
         { 0,0,0,0,0,0,0,0,0,0,0,0 },
         { 0,0,0,0,0,0,0,0,0,0,0,0 }
     };

     int star8x8[8][8] = {
         {0,0,0,1,1,0,0,0},
         {0,0,0,1,1,0,0,0},
         {1,1,1,1,1,1,1,1},
         {0,0,1,1,1,1,0,0},
         {1,1,1,1,1,1,1,1},
         {0,0,0,1,1,0,0,0},
         {0,0,0,1,1,0,0,0},
         {0,0,0,0,0,0,0,0}
     };

     int smile6x6[6][6] = {
        {0, 1, 1, 1, 1, 0},
        { 1,0,0,0,0,1 },
        { 1,0,1,1,0,1 },
        { 1,0,0,0,0,1 },
        { 1,0,1,1,0,1 },
        { 0,1,1,1,1,0 }
    };





#pragma endregion


enum GameState {
    TITLE_SCREEN,
    GAME_SCREEN,
    GAME_OVER_SCREEN
};

enum GameState currentState = TITLE_SCREEN;


void drawtitlescreen()
{
    system("cls");
    printf(" ______   _______  _______          \n");
    printf("(  __  \ (  ____ )(  ___  )|\     /|\n");
    printf("| (  \  )| (    )|| (   ) || )   ( |\n");
    printf("| |   ) || (____)|| (___) || | _ | |\n");
    printf("| |   | ||     __)|  ___  || |( )| |\n");
    printf("| |   ) || (\ (   | (   ) || || || |\n");
    printf("| (__/  )| ) \ \__| )   ( || () () |\n");
    printf("(______/ |/   \__/|/     \|(_______)\n");
    printf("\n");
    printf("        __________________ _        \n");
    printf("        \__   __/\__   __/( )       \n");
    printf("           ) (      ) (   | |      \n");
    printf("           | |      | |   | |       \n");
    printf("           | |      | |   | |       \n");
    printf("           | |      | |   (_)       \n");
    printf("        ___) (___   | |    _        \n");
    printf("        \_______/   )_(   (_)       \n");
    printf("\n");
    printf("   1.6x6    2.8x8   3.12x12 \n");
    printf("커서이동: w a s d | 그리기,지우기: space\n");
}

void handleTitleInput() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 's' || ch == 'S') {
            currentState = GAME_SCREEN;  // ���� ����
        }
        else if (ch == 'q' || ch == 'Q') {
            exit(0);  // ���� ����
        }
    }
}

void move(int x, int y)
{
    COORD position = { x, y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

}

char key;
int x = 0;
int y = 0;
void render(int x, int y)
{
    COORD position = { x, y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

    printf("★");
}

void playermove()
{
    key = _getch();

    if (key == -32)
    {
        key = _getch();
    }

    system("cls");
    switch (key)
    {
    case UP:
        if (y >= 0)
        {
            y--;
        }

        render(x, y);
        break;

    case LEFT:
        if (x >= 0)
        {
            x -= 2;
        }
        render(x, y);
        break;

    case RIGHT:
        if (x >= 0)
        {
            x += 2;
        }
        render(x, y);
        break;

    case DOWN:
        if (y >= 0)
        {
            y++;
        }
        render(x, y);
        break;

    default:
        break;

    }
    printf("\n");
}

int main() {
    while (1)
    {
        switch (currentState)
        {
        case TITLE_SCREEN:
            drawtitlescreen();

            break;

        case GAME_SCREEN:


            break;

        case GAME_OVER_SCREEN:


            break;

        default:
            break;
        }

    }
 
 
    return 0;
}