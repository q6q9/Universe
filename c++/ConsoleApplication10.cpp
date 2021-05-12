#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <Windows.h>

//запись файла
void out_f(char* name, char* str) {
    FILE* f;
    f = fopen(name, "a");
    fputs(str, f);
    fclose(f);
}

void main() {
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    FILE* f;
    char name[32], num[64];
    int i = 0, k = 0, m=0; 
    float *a = NULL;

   do{ //открытие файла
        if (!i) {
            printf("Введите имя исходного файла, например 'name.txt':\n");
            i++;
        }
        else printf("Неверное имя файла, повторите попытку, например 'name.txt':\n");
    gets(name);
    } while ((f = fopen(name, "r")) == NULL);

  
    printf("Введите имя выходного файла, например 'out.txt':\n");
    gets(name);
    fopen(name, "w");//создание нового выходного файла
    i = 0;
    while (!feof(f)) {   
        a = (float*)realloc(a, (i+1) * sizeof(float));
        fscanf(f, "%f", &a[i]);
        i++;
    }
    
    for (size_t j = 0; j < i-1; j++) {
        k = 0;
        if (a[j] > a[j + 1]) {
            if (j == i - 2) j++;
            else {
                k++;
                j++;
            }
            while (a[j] > a[j + 1]) {
                if (j == i - 2) j++;
                else {
                    k++;
                    j++;
                }
                    
            }
        }
        sprintf(num, "%d ",k+1);
        (k) ? (out_f(name, num)) : 0;
    }
    free(a);
    fclose(f);
    getchar();
}

