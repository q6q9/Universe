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
        // system("chcp 1251");
vector<string> a;
string c = {"0<Человек паук><Марвел><'стэн ли''кирстен данст''марк уэбб'><'дон бёрджесс'><'фантастика''супергерои''экшн''драма'><'Тоби Магуайр''Уиллем Дефо''Кирстен Данст''Джеймс Франко'>"};
string b;
regex rx(R"([0-9*])");
smatch res;
cout<<regex_match(c,res,rx)<<endl<<res.str()<<endl;




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