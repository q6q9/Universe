#include <iostream>
#include <stdarg.h>
#include <vector>
#include <fstream>
#include <numeric>
#include <string>
#include <regex>

using namespace std;


void print(string text) { cout << text << endl; } //вывод текста
void menu(int i, ...) //контекстное меню
{
va_list t;
va_start(t, i);
print("Выберите действие:");
for (size_t j = 0; j <= i; j++)
printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "Вернуться (выход)"));
}
void aa(vector<int>&b){
   
    
}











int main()
{
        system("chcp 1251");
vector<string> a;
string b;
a.push_back("asd");
b=a;
cout<<b;

getchar();









// for(;;){
// getline(cin, b);
// if(b=="-1") break;
// if(b!="")
// a.push_back(b);
// }
// for (string const &x:a)
// {
//     cout<<x<<endl;
// }




getchar();
}