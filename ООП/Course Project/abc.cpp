#include <iostream>
#include <vector>
#include <stdarg.h>
//#include <windows.h>
//#include <clocale>

using namespace std;
class Film;
void print(string text) { cout << text << endl; } //˜˜˜˜˜ ˜˜˜˜˜˜
void cls() { printf("\e[1;1H\e[2J"); }            //˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜
void menu(int i, ...)                             //˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜
{
    va_list t;
    va_start(t, i);
    print("˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜:");
    for (size_t j = 0; j <= i; j++)
        printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "˜˜˜˜˜˜˜˜˜ (˜˜˜˜˜)"));
}
void cc()
{
    cin.clear();
    cin.ignore(32767, '\n');
}
class Repertoire
{
private:
    // int id, price, free_places;
    // string date;
    // Film *film;

public:
    int id, price, free_places;
    string date;
    Film *film;
    Repertoire(int id, int price, int free_places,
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
    // int id, places, halls;
    // string name, address, category;
    // bool state;

public:
    int id, places, halls;
    string name, address, category;
    bool state;
    Cinema(int id, int places, int halls, string name,
           string address, string category, bool state);
    ~Cinema();
};

Cinema::Cinema(int id, int places, int halls, string name,
               string address, string category, bool state) : id(id), places(places), halls(halls), name(name),
                                                              address(address), category(category), state(state)
{
}

Cinema::~Cinema()
{
}

class Film
{
private:
    // int id;
    // string name, producer, oper, genre, studio;
    // vector<string> actors;

public:
    int id;
    string name, producer, oper, genre, studio;
    vector<string> actors;
    Film(string name, string genre);
    ~Film();
};

Film::Film(string name, string genre) : name(name), genre(genre)
{
    print("Create new film!");
    cout << "Name - " << name << ", ˜˜˜˜ - " << genre << endl;
}

Film::~Film()
{
}

int main()
{
    system("chcp 1251"); // ˜˜˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜
    cls();

    int x;
    bool flag = true;
    print("˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜, ˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜, ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜, ˜ ˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜");
    while (flag)
    {
        menu(3, "˜˜˜˜˜˜˜˜˜˜", "˜˜˜˜˜˜", "˜˜˜˜˜˜˜˜˜˜");

        // print("˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜:\n[1] - ˜˜˜˜˜˜˜˜˜˜\n[2] - ˜˜˜˜˜˜"
        //       "\n[3] - ˜˜˜˜˜˜˜˜˜˜\n[0] - ˜˜˜˜˜");
        
        cin >> x;
        if (cin.fail())
        {
            cc();
            continue;
        }
        switch (x)
        {
        case 1:
            flag = false;


            print("àôó 1");
            
            
            break;

        case 2:
            flag = false;


            print("˜˜˜˜˜˜ 2");
            
            
            break;

        case 3:
            flag = false;


            print("˜˜˜˜˜˜ 3");
            
            
            break;

        case 0:
            return 0;
        default:
            print("˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜ (˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜ 1 ˜˜ 3)");
            break;
        }
        cin.clear();
        cin.ignore(32767, '\n');
    }

    Film a("˜˜˜˜˜˜˜ ˜˜˜˜", "Fantastic"), b("men", "Ice");
    getchar();
    return 0;
}