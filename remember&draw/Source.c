#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

// 일단 간단한 맵들 난이도당 하나
#pragma region patterns
      int cross5x5[5][5] = {
          { 1,1,1,1,1 },
          { 1,1,0,1,1 },
          { 1,0,1,0,1 },
          { 1,1,0,1,1 },
          { 1,1,1,1,1 }     
     };

      int smile6x6[6][6] = {
        { 0,1,1,1,1,0 },
        { 1,0,1,1,0,1 },
        { 1,0,1,1,0,1 },
        { 1,1,0,0,1,1 },
        { 1,0,1,1,0,1 },
        { 0,1,1,1,1,0 }
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
#pragma endregion

// 게임 상태
enum GameState {
    TITLE_SCREEN,
    GAME_SCREEN_HARD,
    GAME_SCREEN_NORMAL,
    GAME_SCREEN_EASY,
    GAME_OVER_SCREEN
};
enum GameState currentState = TITLE_SCREEN;

char key;
int player_x = 0;
int player_y = 0;

// 시작 타이틀 화면 그리기
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
    printf("1.5x5(쉬움) 2.6x6(보통) 3.8x8(어려움) \n");
    printf("커서이동: 방향키 | 그리기,지우기: space\n");
}

void handleTitleInput() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == '1') {
            currentState = GAME_SCREEN_EASY; 
        }
        else if (ch == '2') {
            currentState = GAME_SCREEN_NORMAL;
        }
        else if (ch == '3') {
            currentState = GAME_SCREEN_HARD;
        }
        else if (ch == 'q' || ch=='Q') {
            exit(0);
        }
    }
}

// 커서만 바로 움직이기
void move(int x, int y)
{
    COORD position = { x, y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);

}

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
        if (player_y >= 0)
        {
            player_y--;
        }

        render(player_x, player_y);
        break;

    case LEFT:
        if (player_x >= 0)
        {
            player_x -= 2;
        }
        render(player_x, player_y);
        break;

    case RIGHT:
        if (player_x >= 0)
        {
            player_x += 2;
        }
        render(player_x, player_y);
        break;

    case DOWN:
        if (player_y >= 0)
        {
            player_y++;
        }
        render(player_x, player_y);
        break;

    default:
        break;

    }
    printf("\n");
}

void drawCountdown() // 카운트다운 10초
{
    for (int s = 10; s > 0; s--)
    {
        printf("화면에 나오는 그림을 외우세요!");
        printf("\n %d 초 남았습니다....", s);

        Sleep(1000);
    }
}

// 이지 난이도 출력 함수
void drawPattern5(int pattern[5][5]) 
{
    system("cls");

    drawCountdown();


    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            printf(pattern[i][j] ? "■ " : "□ ");
        }
        printf("\n");
    }
}
// drawPattern5(cross5x5); 호출할땐 이렇게 어차피 랜덤 안함

// 노말 난이도 출력 함수
void drawPattern6(int pattern[6][6]) 
{ 
    system("cls");
    for (int i = 0; i < 6; i++) 
    {
        for (int j = 0; j < 6; j++) 
        {
            printf(pattern[i][j] ? "■ " : "□ ");
        }
        printf("\n");
    }
}

// 하드 난이도 출력 함수
void drawPattern8(int pattern[8][8])
{
    system("cls");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf(pattern[i][j] ? "■ " : "□ ");
        }
        printf("\n");
    }
}\



int main() {


    while (1)
    {
        switch (currentState)
        {
        case TITLE_SCREEN: // 문제없음
         drawtitlescreen();
         handleTitleInput();

            break;

        case GAME_SCREEN_EASY:
            move(4, 4);

            break;

        case GAME_SCREEN_NORMAL:
          
            
            break;

        case GAME_SCREEN_HARD:
           // move(3, 3);
           // drawPattern8(star8x8);

            break;

        case GAME_OVER_SCREEN:


            break;

        default:
            break;
        }

    }
 
 
    return 0;
}