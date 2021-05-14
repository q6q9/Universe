#include <iostream>
#include <vector>
#include <stdarg.h>
//#include <windows.h>
//#include <clocale>

using namespace std;
class Film;
void print(string text) { cout << text << endl; } //вывод текста
void cls() { printf("\e[1;1H\e[2J"); }            //очистка консоли
void menu(int i, ...)                             //контекстное меню
{
    va_list t;
    va_start(t, i);
    print("Выберите действие:");
    for (size_t j = 0; j <= i; j++)
        printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "Вернуться (выход)"));
}
void cc() //очистка потока ввода
{
    cin.clear();
    cin.ignore(32767, '\n');
}
void cinx(int &x, string text, int i, ...) //ввод x
{
    //cc();

    print(text);
    va_list t;
    va_start(t, i);
    //print("Выберите действие:");
    for (size_t j = 0; j <= i; j++)
        printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "Вернуться (выход)"));
    cin >> x;
    while (cin.fail() || (x < 0 || x > i))
    {
        cc();
        cout << "Неверное значение (введите цифру от 1 до " << i << ")" << endl;
        cin >> x;
    }
    cc();
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
    cout << "Название - " << name << ", Жанр - " << genre << endl;
}

Film::~Film()
{
}

int main()
{
    system("chcp 1251");
    cls();

    int x;
    bool flag = true;
    // print("Выберите область, с которой вы будете работать:");
    // while (flag)
    // {
    // menu(3, "Кинотеатры", "Фильмы", "Репертуары");
    cinx(x, "Выберите область, с которой вы будете работать:", 3, "Кинотеатры", "Фильмы", "Репертуары");
    // cin >> x;
    // if (cin.fail())
    // {
    //     print("Неверное значение (введите цифру от 1 до 3)");
    //     cc();
    //     continue;
    // }
    switch (x)
    {
    case 1:
        print("Нажата 1");

        // menu(4, "Отобразить текущие кинотеатры", "Отобразить сведения кинотеатра по ключу",
        //      "Поиск кинотеатров", "Редактирование кинотеатров");
        cinx(x, "Выберите действие:", 4, "Отобразить текущие кинотеатры", "Отобразить сведения кинотеатра по ключу",
             "Поиск кинотеатров", "Редактирование кинотеатров");
        switch (x)
        {
        case 1:
            print("Список текущих кинотетров:");
            break;
        
        default:
            break;
        }

        break;

    case 2:
        print("Нажата 2");
        flag = false;
        break;

    case 3:
        print("Нажата 3");
        flag = false;
        break;

    // case 0:
    //     return 0;
    default:
        // print("Неверное значение (введите цифру от 1 до 3)");
        return 0;
        
    }
    // cout<<0;

    // // }
    //     cout<<-1;
    Film a(" ", "Fantastic"), b("men", "Ice");
    getchar();
    return 0;
}