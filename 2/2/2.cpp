#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <iostream>

using namespace std;
int n = 1000;
int a[1000][1000], b[1000][1000], c[1000][1000], elem_c;

void main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // объявляем переменные для определения времени выполнения

	start = clock();

	int i = 0, j = 0, r;


	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < n)
	{
		while (j < n)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < n)
	{
		while (j < n)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			elem_c = 0;
			for (r = 0; r < n; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}

	end = clock();

	printf("Use %.0f ms", difftime(end, start));
	_getch();
}
