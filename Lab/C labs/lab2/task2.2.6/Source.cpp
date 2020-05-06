#include<stdio.h>
#include<stdlib.h>
#include<math.h>



float fact(int n)
{
	if (n < 0)// ���� ������������ ���� ������������� �����
	{
		return 0; // ���������� ����
	}

	if (n == 0)// ���� ������������ ���� ����,
	{
		return 1; // ���������� ��������� �� ���� -  1 )
	}

	else// �� ���� ��������� �������
	{
		return n * fact(n - 1); // ������ ��������.
	}

}

float leftsight(float x)
{
	float a = sin(x);
	return a;
}

float rightsight(float x, int n)
{
	float b = 0;
	for (int i = 1; i <= n; i++)
	{
		b = b + (powf(-1, i - 1) * (powf(x, 2 * i - 1) / fact(2 * i - 1)));

	}
	return b;
}

float check()
{
	float a;
	rewind(stdin);
	while (!scanf_s("%f", &a) || a < 0)
	{
		rewind(stdin);
		printf("������������ ����,������� ���������� ������:");
	}
	return a;
}

int check_int()
{
	int c;
	rewind(stdin);
	while (!scanf_s("%d", &c) || c < 0)
	{
		rewind(stdin);
		printf("������������ ����,������� ���������� ������:");
	}
	return c;
}

int main()
{
	system("chcp 1251"); // ��������� � ������� �� ������� ����
	float x = 0;
	int n = 0;
	float e = 0;
	float a = 0;
	float b = 0;

	printf("������� x:");
	scanf_s("%f", &x);
	x = check();

	printf("������� n:");
	scanf_s("%d", &n);
	n = check_int();

	printf("������� ����������� e:");
	scanf_s("%f", &e);
	e = check();

	a = leftsight(x);
	b = rightsight(x, n);

	printf("����� ����� ��������� �����:%f\n", a);
	printf("������ ����� ��������� �����:%f\n", b);

	if (fabsf(a - b) <= e)
	{
		printf("����������� ��������� �������� ��� n=%d\n", n);
	}
	else
	{
		printf("���������� ��������� �� ��������\n");
	}
}