#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

#define X_MAX 79
#define Y_MAX 24

void gotoxy(int x, int y); //��ǥ���� ����ִ� �Լ�
void move_arrow_key(char c, int* x, int* y, int x_b, int y_b); //ȭ��ǥ Ű�� �̿��Ͽ� �̵�
void intro_color_set(void); //���� �÷� UI
void text_color(char attr[]); //���� �÷� ����

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
	printf("�ؽ�Ʈȭ���� ���󺯰�\n\n");
	printf("0: ������,	1: �Ķ���,	2: �ʷϻ�\n");
	printf("3: ����,	4: ������,	5: ���ֻ�\n");
	printf("6: �����,	7: ���,	8: ȸ��\n");
	printf("9: ���� �Ķ���,	A: ���� �ʷϻ�\n");
	printf("B: ���� ����,	C: ���� ������\n");
	printf("D: ���� ���ֻ�, E: ���� �����\n");
	printf("F: ���� ���\n\n");
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
	printf("�Է� �� Enter");
	scanf_s("%s", attr);
	text_color(attr);

	printf("�������� ���ڻ��� ������ Ȯ���մϴ�.");

	return 0;
}


