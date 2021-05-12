
#include <stdio.h>
#define N 2 //количество строк матриц
#define M 6 //количество столбцов матриц

//Очищаем поток входных данных
void flush_input(void)
{
	char c;
	while (scanf("%c", &c) == 1 && c != '\n');
}

int main()
{
	int arr[N][M], i, j, k;
	//вводим элементы исходного массива
	printf("Input numbers of array[%d][%d]:\n", N, M);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			while (scanf("%d", &arr[i][j]) == 0)//обработка в случае неверного ввода числа
			{
				printf("Incorrect number, try again : \n");
				flush_input();
			}
		}
	}
	printf("\nYour array:\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}


	//Операция сглаживания матрицы:
	float new_arr[N][M]; //инициализация нового массива
	printf("\nNew array:\n");

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			k = 0;
			new_arr[i][j] = 0;


			//проверки на существование соседей элемента матрицы
			if (i != 0)
			{
				k += 1;
				new_arr[i][j] += arr[i - 1][j];
			}
			if (N - i != 1)
			{
				k += 1;
				new_arr[i][j] += arr[i + 1][j];
			}
			if (j != 0)
			{
				k += 1;
				new_arr[i][j] += arr[i][j - 1];
			}
			if (M - j != 1)
			{
				k += 1;
				new_arr[i][j] += arr[i][j + 1];	
			}
			new_arr[i][j] = (float)new_arr[i][j] / k;

			printf("%f  ", new_arr[i][j]);
		}
		printf("\n");
	}
	getch();
}
