#include<stdio.h>
#include<stdlib.h>

struct zad
{
	double numerator, denominator;
	double chislo;
};

zad NumDen()
{
	zad val;
	printf("Enter numerator:");
	scanf_s("%lf", &val.numerator);
	printf("Enter denominator:");
	scanf_s("%lf", &val.denominator);
	val.chislo = (double)(val.numerator / val.denominator);
	return val;
}

void output(zad number)
{
	printf("%lf/%lf\nNumber: %lf\n", number.numerator, number.denominator, number.chislo);

}
void reverse(zad number)
{
	printf("%lf / %lf\n", number.denominator, number.numerator);
}

void sokr(zad number)
{
	zad ch_sokr = number;

	if (number.numerator == number.denominator)
	{
		ch_sokr.numerator = 1;
		ch_sokr.denominator = 1;
	}
	if (number.numerator < number.denominator) {
		for (int i = number.numerator; i >= 2; i--)
		{
			if ((int)number.numerator % i == 0 && (int)number.denominator % i == 0)
			{
				ch_sokr.numerator = number.numerator / i;
				ch_sokr.denominator = number.denominator / i;
				break;
			}
			else
			{
				ch_sokr.numerator = number.numerator;
				ch_sokr.denominator = number.denominator;
			}
		}
	}
	else
		for (int i = number.denominator; i >= 2; i--)
		{
			if ((int)number.numerator % i == 0 && (int)number.denominator % i == 0)
			{
				ch_sokr.numerator = number.numerator / i;
				ch_sokr.denominator = number.denominator / i;
				break;
			}
			else
			{
				ch_sokr.numerator = number.numerator;
				ch_sokr.denominator = number.denominator;
			}
		}
	printf("%lf / %lf\n", ch_sokr.numerator, ch_sokr.denominator);
}
void info(zad number)
{
	printf("Program: Visual Studio 2019 v8.3\nAuthor:Tsimbalist Ivan 2001 year of birth\nEspecially for Udovin Ivan\n");
}

void displayMenu() {

	printf("1.Enter Numerator & Denominator:\n"
		"2.Output data.\n"
		"3.Reverse number.\n"
		"4.Short number.\n"
		"5.Author of the program.\n"
		"6.Exit.\n");

}
int check()
{
	int run;
	while (!(scanf_s("%d", &run)) && (run > 6 || run < 1)) {
		rewind(stdin);
		printf("Enter correct value!!!\n");
	}
	return run;
}

void menu()
{
	int run = -1;
	zad number;
	bool flg = false;
	while (run != 6)
	{
		displayMenu();
		switch (run = check())
		{
		case 1:
			number = NumDen();
			flg = true;
			system("cls");
			break;
		case 2:
			system("cls");
			if (flg == true)
				output(number);
			else
				printf("Go to point ¹1!!!\n");
			break;
		case 3:
			system("cls");
			if (flg == true)
				reverse(number);
			else
				printf("Go to point ¹1!!!\n");
			break;
		case 4:
			system("cls");
			if (flg == true)
				sokr(number);
			else
				printf("Go to point ¹1!!!\n");
			break;
		case 5:
			system("cls");
			if (flg == true)
				info(number);
			else
				printf("Go to point ¹1!!!\n");
			break;
		}
	}

	system("cls");

}

int main()
{
	menu();

	return 0;
}