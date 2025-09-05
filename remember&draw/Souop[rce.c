#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h> 

#define SIZE 5
#define EMPTY 0
#define FILLED 1

int originalBoard[SIZE][SIZE];
int playerBoard[SIZE][SIZE];
int cursorX = 0, cursorY = 0;

// 커서 이동
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 커서 숨기기
void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// 랜덤패턴 생성하기
void makePattern() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            originalBoard[i][j] = rand() % 2;
        }
    }
}

// 패턴 보여주기
void showPattern() {
    system("cls");
    gotoxy(0, 0);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(originalBoard[i][j] ? "■ " : "□ ");
        }
        printf("\n");
    }
}

// 카운트다운
void countdown(int sec) {
    for (int i = sec; i > 0; i--) {
        gotoxy(0, SIZE + 1);
        printf("패턴을 기억하세요! \n 남은시간 : %ds...  ", i);
        Sleep(1000);
    }
}

// 화면 그리기
void drawPlayerBoard() {
    gotoxy(0, 0);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == cursorY && j == cursorX) printf("★ ");
            else printf(playerBoard[i][j] ? "■ " : "□ ");
        }
        printf("\n");
    }
}

// 점수
int calculateScore() {
    int score = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (originalBoard[i][j] == playerBoard[i][j]) score++;
    return score;
}

// 타이틀 화면
void titleScreen() {
    system("cls");
    printf("====================================\n");
    printf("   ___                    ______  __\n");
    printf("  / _ \\_______ __    __  /  _/ /_/ /\n");
    printf(" / // / __/ _ `/ |/|/ / _/ // __/_/ \n");
    printf("/____/_/  \\_,_/|__,__/ /___/\\__(_)  \n");
    printf("\n");
    printf("====================================\n");
    printf("\n");
    printf("     == Press enter to start ==     \n");

    // 엔터 대기
    _getch(); 
}

void playGame() {
    
    makePattern(); // 패턴 만들고
    showPattern(); // 패턴보여주면서
    countdown(5); // 카운트다운

    // 플레이어 화면 초기화
    system("cls");
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            playerBoard[i][j] = 0;

    cursorX = cursorY = 0;

    int running = 1;
    while (running) {
        drawPlayerBoard();
        gotoxy(0, SIZE + 1);
        printf("[WASD] 이동 | [Space] 찍기 | [Enter] 완료");

        int key = _getch();
        if (key == 'w' && cursorY > 0) cursorY--;
        else if (key == 's' && cursorY < SIZE - 1) cursorY++;
        else if (key == 'a' && cursorX > 0) cursorX--;
        else if (key == 'd' && cursorX < SIZE - 1) cursorX++;
        else if (key == ' ') playerBoard[cursorY][cursorX] = !playerBoard[cursorY][cursorX];
        else if (key == '\r') running = 0; 
    }

    int score = calculateScore();

    // 결과 화면
    system("cls");
    printf(" ============================================\n");
    printf("  ___ ____ ___ _  ___   ___ _  _____ ____\n");
    printf(" / _ `/ _ `/  ' \\/ -_) / _ \\ |/ / -_) __/\n");
    printf(" \\_, /\\_,_/_/_/_/\\__/  \\___/___/\\__/_/ \n");
    printf("/___/                                    \n");
    printf(" ============================================\n");

    printf(" 원래 그림:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) printf(originalBoard[i][j] ? "■ " : "□ ");
        printf("\n");
    }
    printf("\n 플레이어 그림:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) printf(playerBoard[i][j] ? "■ " : "□ ");
        printf("\n");
    }
    printf("\n 점수: %d/%d\n", score, SIZE * SIZE);

    // 다시하기
    printf(" Enter: 다시하기 / q: 종료)\n");
    int c = _getch();
    if (c == 'q') exit(0);
}

int main() {
    srand((unsigned int)time(NULL));
    hideCursor();

    while (1) {
        titleScreen();
        playGame();
    }

    return 0;
}
