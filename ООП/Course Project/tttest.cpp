#include <iostream>
#include <stdarg.h>
using namespace std;


void print(string text) { cout << text << endl; } //вывод текста
void menu(int i, ...)                             //контекстное меню
{
    va_list t;
    va_start(t, i);
    print("Выберите действие:");
    for (size_t j = 0; j <= i; j++)
        printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "Вернуться (выход)"));
}
    

int main()
{
//    menu(4,"Отобразить текущие кинотеатры", "Отобразить сведения кинотеатра по ключу",
//    "Поиск кинотеатров", "Редактирование кинотеатров");
   cout<<5;
   getchar();
}