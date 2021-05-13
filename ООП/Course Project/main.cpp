#include <iostream>
#include <vector>
#include <stdarg.h>
//#include <windows.h>
//#include <clocale>

using namespace std;
class Film;
void print(string text) { cout << text << endl; } //вывод текста
void cls() { printf("\e[1;1H\e[2J"); }            //очистка консоли
void menu(int i, ...) //контекстное меню
{
    va_list t;
    va_start(t, i);
    for (size_t j = 0; j <= i; j++)
        printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "Вернуться"));
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
    cout << "Name - " << name << ", Жанр - " << genre << endl;
}

Film::~Film()
{
}

int main()
{
    system("chcp 1251"); // Кодировка для отображения кириллицы
    cls();

    int x;
    bool flag = true;
    while (flag)
    {
        menu(3, "Кинотеатры", "Фильмы", "Репертуары");

        // print("Выберите область для работы:\n[1] - Кинотеатры\n[2] - Фильмы"
        //       "\n[3] - Репертуары\n[0] - выход");
        cin >> x;
        switch (x)
        {
        case 1:
            print("Нажата 1");
            flag = false;
            break;

        case 2:
            print("Нажата 2");
            flag = false;
            break;

        case 3:
            print("Нажата 3");
            flag = false;
            break;

        case 0:
            return 0;
        default:
            print("Неверное значение (введите цифру от 1 до 3)");
            break;
        }
        cin.clear();
        cin.ignore(32767, '\n');
    }

    Film a("Человек паук", "Fantastic"), b("men", "Ice");
    getchar();
    return 0;
}