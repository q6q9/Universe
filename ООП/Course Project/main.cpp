#include <iostream>
#include <windows.h>

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
    cout<<"Name - "<<name<<", Genre - "<< genre<<endl;
}

Film::~Film()
{
}

int main()
{
   
    cls();
    Film a("Spider-man", "Fantastic"), b("men", "Ice");
    getchar();
    return 0;
}