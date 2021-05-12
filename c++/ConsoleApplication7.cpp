#include <stdio.h>
#include <string.h>
#define letter(x) (x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z') || (x >= 'А' && x <= 'Я' || x >= 'а' && x <= 'я')



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


int main(){
	char* p[3], word[20], str[512] = "  FUCKING MACHINE world, hi, hi man, but you say me HI!",  str_copy[512];
	int n = 3, k=0;

	p[0] = str;
	p[1] = str_copy;

	int i = 0, j = 0;
	
	// убирем символы спереди
	while (!letter(str[i]))
	{
		i++;

	}
	del(str, i);
	strcpy(p[1], p[0]);
	to_lower(p[0]);



	// найдем первое слово предложения
	printf("%s\n\n", p[0]);
	while (letter(str[j]))
	{	
		
		word[j+1] = str[j];
		j++;
	}
	word[0] = ' ';
	word[j + 1] = ' ';
	word[j + 2] = '\0';

	word[0] = ' ';
	word[1] = 'h';
	word[2] = 'i';
	word[3] = ' ';
	word[4] = '\0';
	printf("%s\n", word);
	
	//зная слово найдем кол-во повторений этого слова попутная удаляя их, если кол-во меньше n то не копируем эту строку

	while (NULL != strstr(p[0], word))
	{	
		p[0] = strstr(p[0], word);
		p[0] = strchr(p[0], p[0][strlen(word)]);
		printf("\t%s\n", p[0]);
	
		
	}
	printf("%d", k);
	/*
	printf("%s\n\n\n\n", word);
	del(p[0], strlen(word)+1);
	printf("%s\n\t%s\n__________________________\n", p[0],str);
	p[0] = strchr(str, str[strlen(word)]);
	printf("%s\n", strchr(p[0], str[strlen(word)]));
	printf("%s\n", str);

	*/
	

}