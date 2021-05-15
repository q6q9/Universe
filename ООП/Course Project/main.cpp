#include <iostream>
#include <vector>
#include <stdarg.h>
#include <fstream>
#include <string>
#include <numeric>
#include <regex>

using namespace std;
class Cinema;
class Film;
class Repertoire;
string unvector(const vector<string> &a)
{
    string s;
    for (string const &b : a)
        s += b + ((b != a[a.size() - 1]) ? ", " : "");
    return s;
}
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

    print(text);
    va_list t;
    va_start(t, i);
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
    cls();
}
void push_line(string &str) //ввод не пустых строк
{
    for (;;)
    {
        getline(cin, str);
        string a;
        for (size_t i = 0; i < str.size(); i++)
        {
            if (str[i] != ' ')
                a += str[i];
        }
        str = a;
        if (str == "")
            print("Err: empty line");
        else
            return;
    }
}
string str(vector<string> &b) //"<%s>",b[]
{
    string a = "<";
    for (string &x : b)
        a += "'" + x + "'";

    return a + ">";
}
string str(string &b) //"<%s>",b
{
    return "<" + b + ">";
}
void push_vector(vector<string> &a)
{
    string b;
    string x;
    for (;;)
    {
        // cout << "_" << b << "_" << endl;
        getline(cin, b);
        x = "";
        for (size_t i = 0; i < b.size(); i++)
        {
            if (b[i] != ' ')
                x += b[i];
        }
        b = x;
        // cout << "_" << b << "_" << endl;
        if (b == "")
        {
            print("Err: empty line");
            continue;
        }
        if (b == "-1")
            break;
        a.push_back(b);
        break;
    }
}
vector<string> parsing(string &str, regex &reg)
{
    string s;
    vector<string> a;
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;
    while (currentMatch != lastMatch)
    {
        s = "";
        smatch match = *currentMatch;
        for (size_t i = 0; i < match.str().size(); i++)
        {
            if (i < match.str().size() - 2)
                s += match.str()[i + 1];
        }
        a.push_back(s);
        currentMatch++;
    }
    return a;
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

    // Сруктура файла .db:
    // id <name> <studio> <producers> <opers> <genres> <actors>
    // <.. , .. , ..>
public:
    int id;
    string name, studio;
    vector<string> producers;
    vector<string> opers;
    vector<string> genres;
    vector<string> actors;
    Film(string str);
    Film();
    Film(Film const &a);
    Film(int id, string name, string studio,
         vector<string> producers, vector<string> opers,
         vector<string> genres, vector<string> actors);
    ~Film();

    void input()
    {
        print("Введите название:");
        push_line(name);
        print("Введите название киностудии");
        push_line(studio);
        print("Введите продюсеров через Enter (-1 для прекращения ввода)");
        push_vector(producers);
        print("Введите операторов через Enter (-1 для прекращения ввода)");
        push_vector(opers);
        print("Введите жанры ерез Enter (-1 для прекращения ввода)");
        push_vector(genres);
        print("Введите актеров ерез Enter (-1 для прекращения ввода)");
        push_vector(actors);
        print("Успех");
    }

    void save()
    {
        ofstream out("data/films.db", ios::app);
        if (out.is_open())
        {
            out << id << str(name) << str(studio) << str(producers)
                << str(opers) << str(genres) << str(actors) << endl;
        }
        out.close();
        print("Фильм сохранен");
    }

    void upload();
};

Film::Film(Film const &a) : id(a.id), name(a.name), studio(a.studio), producers(a.producers),
                            opers(a.opers), genres(a.genres), actors(a.actors)
{
    // print("Использован КОНСТУРКТОР ПОКПИРОВАНИЯ");
}
Film::Film(string str)
{
    regex reg("\\d+");
    sregex_iterator abc(str.begin(),
                        str.end(), reg);
    vector<string> a;
    reg = ("(<.*?>)");
    a = parsing(str, reg);
    reg = ("'.*?'");

    *this = Film(stoi(smatch(*abc).str()), a[0], a[1], parsing(a[2], reg), parsing(a[3], reg),
                 parsing(a[4], reg), parsing(a[5], reg));
}
Film::Film() { input(); }
Film::Film(int id, string name, string studio,
           vector<string> producers, vector<string> opers,
           vector<string> genres, vector<string> actors) : id(id), name(name), studio(studio), producers(producers),
                                                           opers(opers), genres(genres), actors(actors)
{
    //  print("Конуструктор создания фильма был сипользован!\n");
}

Film::~Film()
{
}

void get_all(vector<Cinema> &cinemas, vector<Film> &films, vector<Repertoire> &repertoires)
{
    string line;
    ifstream in("data/films.db"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            //cout << line << endl;
            films.push_back(Film(line));
        }
    }
    print("Соединение проозшоло успешно");
}

int main()
{
    system("chcp 1251");
    cls();

    int x, y;

    vector<Film> films;
    vector<Cinema> cinemas;
    vector<Repertoire> repertoires;
    get_all(cinemas, films, repertoires);
    for (;;)
    {

        cinx(y, "Выберите область, с которой вы будете работать:", 3, "Кинотеатры", "Фильмы", "Репертуары");

        switch (y)
        {
        case 1:
        {
            for (;;)
            {

                print("Нажата 1");
                cinx(x, "Выберите действие:", 4, "Отобразить текущие кинотеатры", "Отобразить сведения кинотеатра по ключу",
                     "Поиск кинотеатров", "Редактирование кинотеатров");
                switch (x)
                {
                case 1:
                {
                    print("Список текущих кинотетров:");
                    for (Cinema const &a : cinemas)
                        cout << "ID : " << a.id << "| Название : " << a.name << endl;
                    print("Введите для продолжения");
                    getchar();
                    break;
                }
                case 2:
                {
                    print("Введите ключ нужного вам кинотеатра или -1 для выхода");

                    break;
                    //case 4:
                    // print("Нажата 4");
                    // cinx(x, "Выберите действие:", 3, "Добавить фильм", "Удалить фильм", "Изменить фильм");
                }
                case 3:
                { //int id, int places, int halls, string name,
                    //string address, string category, bool state
                    cinx(x, "Установите нужные вам значения некоторым свойствам:", 7, "ID",
                         "Название кинотеатра", "Кол-во залов", "Кол-во мест", "Адрес", "Категория", "Состояние");
                    break;
                }

                case 4:
                {
                    print("Нажата 4");
                    cinx(x, "Выберите действие:", 3, "Добавить кинотеатр", "Удалить кинотеатр", "Изменить кинотеатр");

                    switch (x)
                    {
                    case 1:
                    {
                        print("1) добавить фильм");
                        Film a;
                        a.input();
                        a.save();
                        print("добавлен");
                        break;
                    }
                    default:
                        break;
                    }

                    break;
                }
                default:
                {
                    cout << -12356889;
                    break;
                }
                }
                if (!x)
                    break;
            }
            break;
        }
        case 2:
        {
            for (;;)
            {

                print("Нажата 1");
                cinx(x, "Выберите действие:", 4, "Отобразить текущие фильмы", "Отобразить сведения фильма по ключу",
                     "Поиск фильма", "Редактирование фильмов");
                switch (x)
                {
                case 1:
                {
                    print("Список текущих фильмов:");
                    for (Film const &a : films)
                        cout << "ID : " << a.id << ". Название : " << a.name << ". Жанр : " << unvector(a.genres)<<"."<< endl;
                    print("Введите для продолжения");
                    getchar();
                    break;
                }
                case 2:
                {
                    print("Введите ключ нужного вам фильма или -1 для выхода");

                    break;
                    //case 4:
                    // print("Нажата 4");
                    // cinx(x, "Выберите действие:", 3, "Добавить фильм", "Удалить фильм", "Изменить фильм");
                }
                case 3:
                { //int id, int places, int halls, string name,
                    //string address, string category, bool state
                    cinx(x, "Установите нужные вам значения некоторым свойствам:", 7, "ID",
                         "Название фильма", "Название студии", "Продюсеры", "Операторы", "Жанры", "Актеры");
                    break;
                }

                case 4:
                {
                    print("Нажата 4");
                    cinx(x, "Выберите действие:", 3, "Добавить фильм", "Удалить фильм", "Изменить фильм");

                    switch (x)
                    {
                    case 1:
                    {
                        //print("1) добавить фильм");
                        films.push_back(Film());
                        print("добавлен");
                        break;
                    }
                    default:
                        break;
                    }

                    break;
                }
                default:
                {
                    cout << -12356889;
                    break;
                }
                }
                if (!x)
                    break;
            }
            break;
        }
        case 3:
        {
            for (;;)
            {

                print("Нажата 3");
                cinx(x, "Выберите действие:", 4, "Отобразить текущие репертуары", "Отобразить сведения репертуара по ключу",
                     "Поиск репертуаров", "Редактирование репертуаров");
                switch (x)
                {
                case 1:
                {
                    print("Список текущих репертуаров:");
                    for (Cinema const &a : cinemas)
                        cout << "ID : " << a.id << "| Название : " << a.name << endl;
                    print("Введите для продолжения");
                    getchar();
                    break;
                }
                case 2:
                {
                    print("Введите ключ нужного вам репертуара или -1 для выхода");

                    break;
                    //case 4:
                    // print("Нажата 4");
                    // cinx(x, "Выберите действие:", 3, "Добавить фильм", "Удалить фильм", "Изменить фильм");
                }
                case 3:
                { //int id, int places, int halls, string name,
                    //string address, string category, bool state
                    cinx(x, "Установите нужные вам значения некоторым свойствам:", 5, "ID",
                         "Фильм", "Дата", "Цена", "Свободные места");
                    break;
                }

                case 4:
                {
                    print("Нажата 4");
                    cinx(x, "Выберите действие:", 3, "Добавить репертуар", "Удалить репертуар", "Изменить репертуар");

                    switch (x)
                    {
                    case 1:
                    {
                        print("1) добавить репертуар");

                        print("добавлен");
                        break;
                    }
                    default:
                        break;
                    }

                    break;
                }
                default:
                {
                    cout << -12356889;
                    break;
                }
                }
                if (!x)
                    break;
            }
            break;
        }

        default:

            return 0;
        }
    }

    getchar();
    return 0;
}