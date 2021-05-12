#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#define letter(x) (x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z') || (x >= 'А' && x <= 'Я' || x >= 'а' && x <= 'я')
#define lenw(x) (arr[x][1] - arr[x][0]+1)
#define bl(x) (arr[x][2])

//все буквы приравнивает к нижнему регистру
void to_lower(char* p) {
	char* c;
	int j = 0;
	for (size_t i = 0; i < strlen(p); i++)
	{
		c = &p[j];
		if (*c >= 'A' && *c <= 'Z') {
			*c = *c + 'a' - 'A';
		}
		if (*c >= 'А' && *c <= 'Я') {
			*c = *c + 'a' - 'A';
		}
		j++;
	}

}
//массив *p смещает на k символов
void del(char* p, int k) {

	int j = 0;
	for (size_t i = 0; i < strlen(p); i++) {
		p[i] = p[i + k];
	}
}


int main() {

	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

	char *p, word[20], str[512], str_copy[512]="", c='#';
	int n,t, k = 0, i = 0, j = 0, arr[100][3], bl;

	// Итак, вот например, вот вот к3528 тестовове сообщение, итак выглядит но следующим образом, тестововое сообщение, тестововое).
	// Привет мир сказал бы я миру : привет мир мир мир!
	// Привет мир мир мир привет

	p = str;
	printf("Введите предложение:\n\n");
	//ввод и запись слов
	while (c!='\n')
	{
		//вводим символы

		scanf("%c", &c);
		p[i] = c;
		//если буква
		if (letter(c))
		{
			arr[j][0] = i;

			
			while (letter(c))
			{
				i++;
				scanf("%c", &c);
				p[i] = c;				
			}
			arr[j][1] = i-1;

			j++;
		}

		i++;
	}
	
	str[i] = '\0';
	strcat(str_copy, str);
	to_lower(p);

	for (size_t i = 0; i < j; i++)
	{
		
		k = 0;
		for (size_t x = 0; x < j; x++)
		{
			bl = 1;
			//проверяем повторения каждых слов, и если их не надо удалять приписуем флаг о том, что их можно не проверять
			
				if (lenw(i) == lenw(x) && bl(x) && i!=x)
				{
					for (size_t b = 0; b < lenw(i); b++)
					{
						if (!(p[arr[i][0] + b] == p[arr[x][0] + b])) {
							bl = 0;
							
						}
					}


					if (bl)
					{
						
						k++;
					}
				}
		}
		arr[i][2] = k + 1;
		//printf("%d\t\t % d, % d\t", arr[i][2], arr[i][0], arr[i][1]);
		for (size_t b = 0; b < lenw(i); b++)
		{
			//printf("%c", p[arr[i][0] + b]);
		}
		//printf("\n");

	}
	printf("Введите n - минимальное количество повторений слов для их удаления:\n\n");
	scanf("%d", &n);
	int h = 0;
	//для всех слов в массиве arr
	k = 0;
	for (size_t i = 0; i < j; i++)
	{
		if (!bl)
		{
			k += lenw(i - 1);
		}
		bl = 1;
		
		if (n<= arr[i][2])
		{
			// от начала повторяющего слова до конца строки

			for ( t = arr[i][0]-k; t < strlen(str_copy)-lenw(i); t++)
			

			
			{
				
				//printf("%d\t%d\t%d\n_________________________\n", t,i, lenw(i));
				//printf("\n%s", str_copy);
				str_copy[t] = str_copy[t + lenw(i)];
				
				
				
			}
			str_copy[t] = '\0';
			bl = 0;
		}
		
	}
	printf("%s", str_copy);
}