#include <iostream>
#include <stdarg.h>
#include <vector>
#include <fstream>
#include <numeric>
#include <string>
#include <regex>

using namespace std;


void print(string text) { cout << text << endl; } //����� ������
void menu(int i, ...) //����������� ����
{
va_list t;
va_start(t, i);
print("�������� ��������:");
for (size_t j = 0; j <= i; j++)
printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "��������� (�����)"));
}
void aa(vector<int>&b){
   
    
}











int main()
{
        // system("chcp 1251");
vector<string> a;
string c = {"0<������� ����><������><'���� ��''������� �����''���� ����'><'��� �������'><'����������''����������''����''�����'><'���� �������''������ ����''������� �����''������ ������'>"};
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