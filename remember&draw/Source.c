#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

enum GameState {
    TITLE_SCREEN,
    TOOL_SCREEN,
    GAME_SCREEN,
    GAME_OVER_SCREEN
};

enum GameState currentState = TITLE_SCREEN;

void gotoxy(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawGameTitle()
{
    system("cls");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
}

int main() {
    setConsoleSize(20, 20);

    // int difficulty;
    // int size = 12;
    // 
    // int pict[12][12] = {
    //  {0,0,0,1,1,0,0,1,1,0,0,0},
    // {0,0,1,1,1,1,1,1,1,1,0,0},
    // {0,1,1,1,1,1,1,1,1,1,1,0},
    // {1,1,1,1,1,1,1,1,1,1,1,1},
    // {1,1,1,1,1,1,1,1,1,1,1,1},
    // {0,1,1,1,1,1,1,1,1,1,1,0},
    // {0,0,1,1,1,1,1,1,1,1,0,0},
    // {0,0,0,1,1,1,1,1,1,0,0,0},
    // {0,0,0,0,1,1,1,1,0,0,0,0},
    // {0,0,0,0,0,1,1,0,0,0,0,0},
    // {0,0,0,0,0,0,0,0,0,0,0,0},
    // {0,0,0,0,0,0,0,0,0,0,0,0}
    // };
    // 
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++) {
    //         if (pict[i][j] == 1)
    //             printf("▦");
    //         else
    //             printf("  "); 
    //     }
    //     printf("\n");
    // }

    while (1)
    {
        switch (currentState) {
        case TITLE_SCREEN:
       
            break;
        case TOOL_SCREEN:

            break;
        case GAME_SCREEN:
    
            break;
        case GAME_OVER_SCREEN:

            break;
        }

    }

    return 0;
}