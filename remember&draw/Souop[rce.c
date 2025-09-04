#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

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

// 패턴 생성 (랜덤 필요 없으면 직접 설정 가능)
void makePattern() {
    // 예시: 단순 패턴
    int temp[SIZE][SIZE] = {
        {1,0,1,0,1},
        {0,1,0,1,0},
        {1,0,1,0,1},
        {0,1,0,1,0},
        {1,0,1,0,1}
    };
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            originalBoard[i][j] = temp[i][j];
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

// 6초 카운트다운 표시
void countdown(int sec) {
    for (int i = sec; i > 0; i--) {
        gotoxy(0, SIZE + 1);
        printf("패턴을 기억하세요: %d초 남음  ", i);
        Sleep(1000);
    }
}

// 플레이어 화면 그리기
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

// 점수 계산
int calculateScore() {
    int score = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (originalBoard[i][j] == playerBoard[i][j]) score++;
    return score;
}

// 시작 화면
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

    _getch(); // 엔터 대기
}

int main() {
    srand((unsigned int)time(NULL));
    hideCursor();

    // 시작 화면
    titleScreen();

    // 패턴 생성 및 보여주기
    makePattern();
    showPattern();
    countdown(6); // 6초 카운트다운

    // 초기화 후 플레이어 그림 모드
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

    // 점수 계산
    int score = calculateScore();

    // 결과 화면
    system("cls");
    printf("=== 결과 ===\n");
    printf("원래 그림:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) printf(originalBoard[i][j] ? "■ " : "□ ");
        printf("\n");
    }
    printf("\n플레이어 그림:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) printf(playerBoard[i][j] ? "■ " : "□ ");
        printf("\n");
    }
    printf("\n맞춘 칸: %d/%d\n", score, SIZE * SIZE);

    return 0;
}
