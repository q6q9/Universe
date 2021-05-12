#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num(x) ((x>='0')&&(x<='9'))

//Запись строки str в файл name
void out_f(char* name, char* str) {
    FILE* f;
    f = fopen(name, "w");
    fputs(str, f);
    fclose(f);
}
//Завершение цикла и обнуление логической переменной
void fail(int *j, int *bl, char * str){
    *j= strlen(str);
    *bl = 0;
}

int main(void) {
    FILE* f;
    char str[255], *a;
    int i = 0 , bl;
    char name[] = "In.txt";
    if ((f = fopen(name, "r")) == NULL)
    {
        out_f("Out.txt", "Исходного файла не существует");
        return 0;
    }

    while(feof(f)!=1) {
        bl = 1;
        fgets(str, sizeof(str), f); // Чтение строки  из файла
        for (size_t j = 0; j < strlen(str); j++) {//каждая буква из строки

            while (str[j] == ' '|| str[j] == '\t') j++; //пока отступы
            (str[j] == '-' || str[j] == '+') ? (j++) : NULL; //если перед числом будет знак
            if (num(str[j])) {//если цифра - проверяем, иначе выходим
                while (num(str[j])) j++; //пока цифры
                if (str[j] == '.') {//если точка после цифр - проверяем, иначе выходим
                        j++;
                        if (num(str[j])) { // если цифра после точки проверяем, иначе выходим
                            while (num(str[j])) {//пока цифры
                                j++;
                            }
                            while (j<strlen(str)) {
                                if ((str[j] != ' ') && (str[j] != '\t') && (str[j] != '\n')&& (str[j] != '\0')) {
                                    fail(&j, &bl, str);
                                }
                                j++;
                            }
                        }
                        else fail(&j, &bl, str); //если после точки нет цифры -выходим
                }
                else fail(&j, &bl, str);//если нет точки после цифр -выходим
            }
            else fail(&j, &bl, str);//если после отступов нет цифры -выходим
        }
        (bl) ? (i++) : NULL;
    }
    fclose(f);
    sprintf(str, "В исходном файле %d строк, удовлетворяющих заданному условию", i);
    (i) ? (out_f("Out.txt", str)) : (out_f("Out.txt", "В исходном файле нет искомых строк"));
}
