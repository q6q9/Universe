#include <iostream>
//#include <windows.h>
//#include <clocale>

using namespace std;

void print(string text) { cout << text << endl; }
void cls() { printf("\e[1;1H\e[2J"); }

class Film
{
private:
    string name, genre;

public:
    Film(string name, string genre);
    ~Film();
};

Film::Film(string name, string genre) : name(name), genre(genre)
{
    print("Create new film!");
    cout<<"Name - "<<name<<", Жанр - "<< genre<<endl;
}

Film::~Film()
{
}

int main()
{
    // SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    system("chcp 1251");
    // SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    // setlocale(LC_CTYPE, "rus");
    cls();
    Film a("Человек паук", "Fantastic"), b("men", "Ice");
    getchar();
    return 0;
}