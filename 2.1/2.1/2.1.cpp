#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;
	i = left; j = right;
	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}


void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}


int cmp(const void* a, const void* b) {    //функция сравнения элементов массива
	{
		return *(int*)a - *(int*)b;		// Если результат вычитания равен 0, то числа равны
	}
}

int main()
{
	int m[100000]; int x = 100000;

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setlocale(LC_ALL, "Rus");

	clock_t start, end; // объявляем переменные для определения времени выполнения


	printf("---------------------------------\n");
	printf("|Data\t|Shell\t|Qs\t|QSort\t|\n");
	printf("---------------------------------\n");
			srand(time(NULL));
			for (int i = 0; i < x; i++) {   //Заполнение массива рандомными числами
				m[i] = rand() % 100 + 1;
			}
			start = clock();
			shell(m, 10000);
			end = clock();
			printf("|rand\t|%.1f\t|", difftime(end, start));

			srand(time(NULL));
			for (int i = 0; i < x; i++) {   //Заполнение массива рандомными числами
				m[i] = rand() % 100 + 1;
			}
			start = clock();
			qs(m, 0, 10000 - 1);
			end = clock();
			printf("%.1f\t|", difftime(end, start));

			srand(time(NULL));
			for (int i = 0; i < x; i++) {   //Заполнение массива рандомными числами
				m[i] = rand() % 100 + 1;
			}
			start = clock();
			qsort(m, 10000, sizeof(int), cmp);
			end = clock();
			printf("%.1f\t|\n", difftime(end, start));
			printf("---------------------------------\n");
////////////////////////////////////////////////////////////////////////////////	

			for (int i = 1; i < x; i++) {		//Возрастающая последовательность
				m[i] = m[i - 1] + 1;
			}
			start = clock();
			shell(m, 10000);
			end = clock();
			printf("|up\t|%.1f\t|", difftime(end, start));

			for (int i = 1; i < x; i++) {		//Возрастающая последовательность
				m[i] = m[i - 1] + 1;
			}
			start = clock();
			qs(m, 0, 10000 - 1);
			end = clock();
			printf("%.1f\t|", difftime(end, start));

			for (int i = 1; i < x; i++) {		//Возрастающая последовательность
				m[i] = m[i - 1] + 1;
			}
			start = clock();
			qsort(m, 10000, sizeof(int), cmp);
			end = clock();
			printf("%.1f\t|\n", difftime(end, start));
			printf("---------------------------------\n");
////////////////////////////////////////////////////////////////////////////////	
		
			for (int i = 0; i < x; i++) {	//Убывающая последовательность
				m[i] = x - i;
			}
			start = clock();
			shell(m, 10000);
			end = clock();
			printf("|down\t|%.1f\t|", difftime(end, start));

			for (int i = 0; i < x; i++) {	//Убывающая последовательность
				m[i] = x - i;
			}
			start = clock();
			qs(m, 0, 10000 - 1);
			end = clock();
			printf("%.1f\t|", difftime(end, start));

			for (int i = 0; i < x; i++) {	//Убывающая последовательность
				m[i] = x - i;
			}
			start = clock();
			qsort(m, 10000, sizeof(int), cmp);
			end = clock();
			printf("%.1f\t|\n", difftime(end, start));
			printf("---------------------------------\n");
////////////////////////////////////////////////////////////////////////////////

			for (int i = 0; i < x / 2; i++) {	//Возрастающе-убывающая последовательность
				m[i] = m[i - 1] + 1;
			}
			start = clock();
			shell(m, 10000);
			end = clock();
			printf("|up/dw\t|%.1f\t|", difftime(end, start));

			for (int i = 0; i < x / 2; i++) {	//Возрастающе-убывающая последовательность
				m[i] = m[i - 1] + 1;
			}
			start = clock();
			qs(m, 0, 10000 - 1);
			end = clock();
			printf("%.1f\t|", difftime(end, start));

			for (int i = 0; i < x / 2; i++) {	//Возрастающе-убывающая последовательность
				m[i] = m[i - 1] + 1;
			}
			start = clock();
			qsort(m, 10000, sizeof(int), cmp);
			end = clock();
			printf("%.1f\t|\n", difftime(end, start));
			printf("---------------------------------\n");
	return (0);
}

