#include <iostream>
//#include <windows.h>
//#include <clocale>

using namespace std;

void print(string text) { cout << text << endl; }
void cls() { printf("\e[1;1H\e[2J"); }

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
    bool  state;
public:
    Cinema(/* args */);
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
    string name, genre;

public:
    Film(string name, string genre);
    ~Film();
};

Film::Film(string name, string genre) : name(name), genre(genre)
{
    print("Create new film!");
    cout<<"Name - "<<name<<", Р вЂ“Р В°Р Р…РЎР‚ - "<< genre<<endl;
}

Film::~Film()
{
}

int main()
{
    // SetConsoleCP(1251);// РЎС“РЎРѓРЎвЂљР В°Р Р…Р С•Р Р†Р С”Р В° Р С”Р С•Р Т‘Р С•Р Р†Р С•Р в„– РЎРѓРЎвЂљРЎР‚Р В°Р Р…Р С‘РЎвЂ РЎвЂ№ win-cp 1251 Р Р† Р С—Р С•РЎвЂљР С•Р С” Р Р†Р Р†Р С•Р Т‘Р В°
    system("chcp 1251");
    // SetConsoleOutputCP(1251); // РЎС“РЎРѓРЎвЂљР В°Р Р…Р С•Р Р†Р С”Р В° Р С”Р С•Р Т‘Р С•Р Р†Р С•Р в„– РЎРѓРЎвЂљРЎР‚Р В°Р Р…Р С‘РЎвЂ РЎвЂ№ win-cp 1251 Р Р† Р С—Р С•РЎвЂљР С•Р С” Р Р†РЎвЂ№Р Р†Р С•Р Т‘Р В°
    // setlocale(LC_CTYPE, "rus");
    cls();
    Film a("Р В§Р ВµР В»Р С•Р Р†Р ВµР С” Р С—Р В°РЎС“Р С”", "Fantastic"), b("men", "Ice");
    getchar();
    return 0;
}