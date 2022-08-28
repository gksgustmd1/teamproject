#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

#define X_MAX 79
#define Y_MAX 24

void gotoxy(int x, int y); //좌표값을 잡아주는 함수
void move_arrow_key(char c, int* x, int* y, int x_b, int y_b); //화살표 키를 이용하여 이동
void intro_color_set(void); //글자 컬러 UI
void text_color(char attr[]); //글자 컬러 선택

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void move_arrow_key(char c, int* x, int* y, int x_b, int y_b)
{
	switch (c)
	{
	case 72:
		*y = *y - 1;
		if (*y < 1)
		{
			*y = 1;
		}
		break;

	case 75:
		*x = *x - 1;
		if (*x > x_b)
		{
			*x = x_b;
		}
		break;
	case 77:
		*x = *x + 1;
		if (*x > x_b)
		{
			*x = x_b;
		}
		break;
	case 80:
		*y = *y + 1;
		if (*y > y_b)
		{
			*y = y_b;
		}
		break;
	default:
		return;
	}
}

void intro_color_set(void)
{
	printf("텍스트화면의 색상변경\n\n");
	printf("0: 검정색,	1: 파랑색,	2: 초록색\n");
	printf("3: 옥색,	4: 빨간색,	5: 자주색\n");
	printf("6: 노란색,	7: 흰색,	8: 회색\n");
	printf("9: 연한 파란색,	A: 연한 초록색\n");
	printf("B: 연한 옥색,	C: 연한 빨간색\n");
	printf("D: 연한 자주색, E: 연한 노란색\n");
	printf("F: 밝은 흰색\n\n");
}

void text_color(char attr[])
{
	char dos_command[9];
	sprintf(dos_command, "color %s", attr);
	system("cls");
	system(dos_command);
}

int main(void)
{
	char attr[3];
	intro_color_set();
	printf("입력 후 Enter");
	scanf_s("%s", attr);
	text_color(attr);

	printf("바탕색과 문자색의 변경을 확인합니다.");

	return 0;
}


