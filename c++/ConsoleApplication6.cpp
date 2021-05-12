#include <stdio.h>
#include <locale>
#include <Windows.h>
#include <string.h>
#define N 1024


void to_lower(char *c) {
    if (*c >= 'A' && *c <= 'Z') {
        *c = *c + 'a' - 'A';
    }
    if (*c >= 'А' && *c <= 'Я') {
        *c = *c + 'a' - 'A';
    }
}



int main(void)
{

    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    setlocale(LC_ALL, "RU");
    int i = 0, j = 0, z = 0, k = 1, n, bl;
    char a[] = "привет мир!    фыв ", b[] = "Привет мир!", d[] = "Привет мир! ";
   
    char str[N]="Я Привет мир, я хотел сказать всем привет мир, мир, мир я я.", n_str[N], p_str[N], word[20], *c;
//нижний регситр
    for (size_t j = 0; j < strlen(str); j++)
    {
        c = &str[j];
        to_lower(c);
    }

    //n=3; Привет, бы хотел сказать всем привет,,. 
    while ((str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'А' && str[i] <= 'Я' || str[i] >= 'а' && str[i] <= 'я'))
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    printf("%s\n", word);
    //printf("a и b: %d \na и d:%d", strcmp(a, b), strcmp(a, d));
    int y;
    for (y = 0; y < strlen(str); y++)
    {
        p_str[y] = str[y];
    }
    p_str[y] = '\0';
    
    c = p_str;
  
    do
    {
        k++;
        c = strchr(c, c[strlen(word)]);
        c = strstr(c, word);
        bl = NULL != strstr(c, word);
        printf("%s\t%d\n",c,k);
        
    } while (bl);
        
        printf("%s\n", strchr(c, c[strlen(word) + 1]));
        c = strchr(c, c[strlen(word) + 1]);
        printf("%s\n", strchr(c, c[strlen(word) + 1]));
        c = strchr(c, c[strlen(word) + 1]);
        printf("%s\n", strchr(c, c[strlen(word) + 1]));
   


}

