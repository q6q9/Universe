#include <iostream>
#include <stdarg.h>
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


int main()
{
        system("chcp 1251");
menu(4,"���������� ������� ����������", "���������� �������� ���������� �� �����",
"����� �����������", "�������������� �����������");
cout<<5;
getchar();
}