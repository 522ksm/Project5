#include <stdio.h>
#include <windows.h>

#define UP 0
#define DOWN 1
#define SUBMIT 2
#define WIDTH 100


int keyControl();
void init();
void titleDraw();
int menuDraw();
void gotoxy(int, int);

int main(void) {
	init();
	titleDraw();
	menuDraw();

	return 0;
}

int keyControl() {
	int temp = getch();
	if (temp == 224) {
		temp = getch();
		if (temp == 72) {
			return UP;
		}
		else if (temp == 80) {
			return DOWN;
		}
	}
	else if (temp == ' ') {
		return SUBMIT;
	}
}

void init() {
	system("mode con cols=100 lines=40 | title 도서 대여");
}

void titleDraw() {												
	char str1[] = "<도서 대여>";
	int minwidth = strlen(str1) + (WIDTH - strlen(str1)) / 2;
	printf("\n\n\n%*s", minwidth, str1);
}

int menuDraw() {
	int x = 24;
	int y = 12;
	gotoxy(24 - 2, 12);
	printf("> 로그인");
	gotoxy(24, 13);
	printf("회원가입");
	while (1) {
		int n = keyControl();
		switch (n) {
			case UP: {
				if (y > 12) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, --y);
					printf(">");
				}
				break;
			}
			case DOWN: {
				if (y < 13) {
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, ++y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				return y - 12;
			}
		}
	}
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}