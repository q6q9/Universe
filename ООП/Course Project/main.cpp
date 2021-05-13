#include <iostream>
#include <vector>
//#include <windows.h>
//#include <clocale>

using namespace std;
class Film;
void print(string text) { cout << text << endl; }//вывод текста
void cls() { printf("\e[1;1H\e[2J"); }//очистка консоли

void menu(string text, ...)
{   
    string * texts =  text;
    for (size_t i = 0; i < texts.size(); i++)
    {
        /* code */
    }
    
}

class Repertoire
{
private:
    int id, price, free_places;
    string date;
    Film *film;

public:
    Repertoire::Repertoire(int id, int price, int free_places,
                           string date, Film *film);
    ~Repertoire();
};

Repertoire::Repertoire(int id, int price, int free_places,
                       string date, Film *film) : id(id), price(price),
                                                  free_places(free_places), date(date), film(film)
{
}

Repertoire::~Repertoire()
{
}

class Cinema
{
private:
    int id, places, halls;
    string name, address, category;
    bool state;

public:
    Cinema(int id, int places, int halls, string name,
           string address, string category, bool state);
    ~Cinema();
};

Cinema::Cinema(int id, int places, int halls, string name,
           string address, string category, bool state):
           id(id), places(places), halls(halls), name(name),
           address(address), category(category), state(state)
{
}

Cinema::~Cinema()
{
}

class Film
{
private:
    int id;
    string name, producer, oper, genre, studio;
    vector<string> actors;

public:
    Film(string name, string genre);
    ~Film();
};

Film::Film(string name, string genre) : name(name), genre(genre)
{
    print("Create new film!");
    cout << "Name - " << name << ", ���� - " << genre << endl;
}

Film::~Film()
{
}

int main()
{
    system("chcp 1251"); // ��������� ��� ����������� ���������
    cls();

    Film a("������� ����", "Fantastic"), b("men", "Ice");
    getchar();
    return 0;
}