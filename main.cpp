#include <iostream>
#include <vector>
#include <stdarg.h>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <random>
#include "Film.h"
#include "Cinema.h"
#include "Repertoire.h"
#include "funcs.h"

#define d(a) a[0] << a[1] << "." << a[2] << a[3] << "." << a.substr(4, 4)
#define rand(x) engine() % x
#define ctoi(j) atoi(string({j[0]}).c_str())
using namespace std;

vector<Film> films;
vector<Cinema> cinemas;
vector<Repertoire> repertoires;
// void cc();
// void print(string text) { cout << text << endl; } //вывод текста
// void r_cin(int &j)
// {
//     for (;;)
//     {
//         cin >> j;
//         if (cin.fail())
//             cc();
//         else
//             break;
//         print("Неверный ввод, попробуйте ввести число:");
//     }
// }
// void to_lower(char *c)
// {
//     if (*c >= 'A' && *c <= 'Z')
//     {
//         *c = *c + 'a' - 'A';
//     }
//     if (*c >= 'А' && *c <= 'Я')
//     {
//         *c = *c + 'a' - 'A';
//     }
// }
// string low(string s)
// {
//     for (size_t i = 0; i < s.size(); i++)
//     {
//         to_lower(&s[i]);
//     }
//     return s;
// }
// vector<string> low(vector<string> x)
// {
//     for (string &s : x)
//         for (size_t i = 0; i < s.size(); i++)
//             s[i] = tolower(s[i], locale("ru"));

//     for (string &s : x)
//         cout << s << endl;
//     return x;
// }
// void reverseStr(string &str)
// {
//     int n = str.length();

//     // Swap character starting from two
//     // corners
//     for (int i = 0; i < n / 2; i++)
//         swap(str[i], str[n - i - 1]);
// }
// vector<string> e_parse(string str)
// {
//     int i = 0, j, y;
//     string word;
//     vector<string> a;
//     while (i < str.size())
//     {
//         word = "";
//         while (str[i] != ',' && i < str.size())
//         {
//             // cout << "1 " << str[i] << endl;
//             word += str[i];
//             i++;
//         }
//         j = 0;
//         // cout << "1.5 " << word[j] << endl;
//         if (word[j] == ' ')
//         {
//             for (j = 0; j < word.size(); j++)
//             {
//                 // cout << "2 " << word[j] << endl;
//                 if (word[j] != ' ')
//                 {
//                     j += word.size();
//                 }
//             };
//             // cout << "2.5 " << word[j] << endl;
//             word = word.substr(j - word.size() - 1);
//         }
//         for (j = 0; j < word.size(); j++)
//         {
//             // cout << "3 " << word[j] << endl;
//             if (word[j] == ' ')
//             {
//                 break;
//             }
//         };
//         for (y = j; y < word.size(); y++)
//         {
//             // cout << "4 " << word[y] << endl;
//             if (word[y] != ' ')
//             {
//                 break;
//             }
//         };
//         word = word.substr(0, j + 1) + word.substr(y);

//         reverseStr(word);
//         j = 0;
//         // cout << "3.5 " << word[j] << endl;
//         if (word[j] == ' ')
//         {
//             for (j = 0; j < word.size(); j++)
//             {
//                 // cout << "2 " << word[j] << endl;
//                 if (word[j] != ' ')
//                 {
//                     j += word.size();
//                 }
//             };
//             // cout << "2.5 " << word[j] << endl;
//             word = word.substr(j - word.size() - 1);
//         }
//         reverseStr(word);
//         a.push_back(word);
//         i++;
//     }
//     // for(string b:a)cout<<b<<endl;
//     return a;
// }
// void get_films(vector<Film> &films);
// void get_all(vector<Cinema> &cinemas, vector<Film> &films, vector<Repertoire> &repertoires);
// string unvector(const vector<string> &a)
// {
//     string s;
//     for (string const &b : a)
//         s += b + ((b != a[a.size() - 1]) ? ", " : "");
//     return s;
// }
// void cls() { printf("\e[1;1H\e[2J"); } //очистка консоли
// void menu(int i, ...)                  //контекстное меню
// {
//     va_list t;
//     va_start(t, i);
//     print("Выберите действие:");
//     for (size_t j = 0; j <= i; j++)
//         printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "Вернуться (выход)"));
// }
// void cc() //очистка потока ввода
// {
//     cin.clear();
//     cin.ignore(32767, '\n');
// }
// void cinx(int &x, string text, int i, ...) //ввод x
// {

//     print(text);
//     va_list t;
//     va_start(t, i);
//     for (size_t j = 0; j <= i; j++)
//         printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "Вернуться (выход)"));
//     cin >> x;
//     while (cin.fail() || (x < 0 || x > i))
//     {
//         cc();
//         cout << "Неверное значение (введите цифру от 1 до " << i << ")" << endl;
//         cin >> x;
//     }
//     cc();
//     cls();
// }
// void cinx(int &x, string text)
// {
//     print(text);
//     cin >> x;
//     while (cin.fail())
//     {
//         cc();
//         cout << "Неверное значение (введите число)" << endl;
//         cin >> x;
//     }
// }
// void cinx(string &x, string text, int i, ...) //ввод x
// {

//     print(text);
//     va_list t;
//     va_start(t, i);
//     for (size_t j = 0; j <= i; j++)
//         printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "Вернуться (выход)"));
//     // getline(cin, x);

//     // while ((ctoi(x) < 0) || (ctoi(x) > i) || (x[1] != ' '))
//     // {

//     //     cout << "Неверное значение (введите цифру от 1 до " << i << " и команду)" << endl;
//     //     getline(cin, x);
//     // }
//     // cc();
//     // cls();
// }
// void push_line(string &str) //ввод не пустых строк
// {
//     for (;;)
//     {
//         getline(cin, str);
//         string a;
//         for (size_t i = 0; i < str.size(); i++)
//         {
//             if (str[i] != ' ')
//                 a += str[i];
//         }
//         if (a == "")
//             print("Err: empty line");
//         else
//             return;
//     }
// }
// string str(vector<string> &b) //"<%s>",b[]
// {
//     string a = "<";
//     for (string &x : b)
//         a += "'" + x + "'";

//     return a + ">";
// }
// string str(string &b) //"<%s>",b
// {
//     return "<" + b + ">";
// }
// void push_vector(vector<string> &a)
// {
//     string b;
//     string x;
//     for (;;)
//     {
//         // cout << "_" << b << "_" << endl;
//         getline(cin, b);
//         x = "";
//         for (size_t i = 0; i < b.size(); i++)
//         {
//             if (b[i] != ' ')
//                 x += b[i];
//         }

//         // cout << "_" << b << "_" << endl;
//         if (x == "")
//         {
//             print("Err: empty line");
//             continue;
//         }
//         if (b == "-1" && a.size() > 0)
//             break;
//         a.push_back(b);
//     }
// }
// vector<string> parsing(string &str, regex &reg)
// {
//     string s;
//     // int i == 0;
//     vector<string> a;
//     sregex_iterator currentMatch(str.begin(), str.end(), reg);
//     sregex_iterator lastMatch;
//     while (currentMatch != lastMatch)
//     {
//         s = "";
//         smatch match = *currentMatch;
//         for (size_t i = 0; i < match.str().size(); i++)
//         {
//             if (i < match.str().size() - 2)
//                 s += match.str()[i + 1];
//         }
//         a.push_back(s);
//         currentMatch++;
//     }
//     if (a.size() == 7)
//         a.push_back("0");
//     return a;
// }
// vector<string> parsing(regex &reg, string &str)
// {
//     string s;
//     vector<string> a;
//     sregex_iterator currentMatch(str.begin(), str.end(), reg);
//     sregex_iterator lastMatch;
//     while (currentMatch != lastMatch)
//     {
//         smatch match = *currentMatch;
//         a.push_back(match.str());
//         currentMatch++;
//     }
//     return a;
// }
// void get_films()
// {
//     films.clear();
//     string line;
//     ifstream in("data/films.db"); // окрываем файл для чтения
//     if (in.is_open())
//     {
//         while (getline(in, line))
//         {
//             films.push_back(Film(line));
//         }
//         in.close();
//     }
// }
// void get_repertoires()
// {
//     repertoires.clear();
//     string line;
//     ifstream in("data/repertoires.db"); // окрываем файл для чтения
//     if (in.is_open())
//     {
//         while (getline(in, line))
//         {
//             repertoires.push_back(Repertoire(line));
//         }
//         in.close();
//     }
// }
// void get_cinemas()
// {
//     cinemas.clear();
//     string line;
//     ifstream in("data/cinemas.db"); // окрываем файл для чтения
//     if (in.is_open())
//     {
//         while (getline(in, line))
//         {
//             cinemas.push_back(Cinema(line));
//         }
//         in.close();
//     }
// }
// void get_all(/*vector<Cinema> &cinemas, vector<Film> &films, vector<Repertoire> &repertoires*/) //выгрузка данных
// {
//     get_films();
//     get_repertoires();
//     get_cinemas();
//     print("Соединение проозшоло успешно");
// }
// void set_all(/*vector<Cinema> &cinemas, vector<Film> &films, vector<Repertoire> &repertoires*/) //сохранение данных
// {
//     ofstream out;              // поток для записи
//     out.open("data/films.db"); // окрываем файл для записи
//     out.close();
//     out.open("data/films.db");

//     if (out.is_open())
//     {
//         for (Film &a : films)
//         {
//             a.save();
//         }
//         out.close();
//     }
//     out.open("data/repertoires.db"); // окрываем файл для записи
//     out.close();
//     out.open("data/repertoires.db");

//     if (out.is_open())
//     {
//         for (Repertoire &a : repertoires)
//         {
//             a.save();
//         }
//         out.close();
//     }
//     out.open("data/cinemas.db"); // окрываем файл для записи
//     out.close();
//     out.open("data/cinemas.db");

//     if (out.is_open())
//     {
//         for (Cinema &a : cinemas)
//         {
//             a.save();
//         }
//         out.close();
//     }
//     print("Соединение проозшоло успешно");
// }
// void push_vector(vector<Repertoire *> &a)
// {

//     int x;
//     for (;;)
//     {
//         r_cin(x);
//         Repertoire z(0);
//         // Repertoire *ptr;
//         if (x != -1)
//         {
//             if (z.search(x) != NULL)
//                 a.push_back(z.search(x));
//         }
//         else
//             return;
//     }
// }


int main()
{
    std::mt19937 engine;
    engine.seed(std::time(nullptr));
    system("chcp 1251");
    cls();

    int x, y;
    get_all();
    getchar();
    for (;;)
    {
        print("Для СОХРАНЕНИЯ ИЗМЕНЕНИЙ выходите из программы с помощью меню!");
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
                    for (Cinema &a : cinemas)
                        a.show();
                    print("Введите для продолжения");
                    getchar();
                    cls();
                    break;
                }
                case 2:
                {
                    int j;
                    print("Введите ключ нужного вам кинотеатра или -1 для выхода");
                    r_cin(j);
                    if (j == -1)
                    {
                        cls();
                        break;
                    }
                    for (Cinema &a : cinemas)
                    {
                        if (j == a.id)
                        {
                            a.show();
                            print("Введите для продолжения:");
                            cc();
                            getchar();
                            cls();
                            j = -1;
                        }
                    }

                    if (j != -1)
                    {
                        print("Кинотеатра с данным ключом не существует");
                        print("Введите для продолжения:");
                        cc();
                        getchar();
                        cls();
                    }
                    break;
                }
                case 3:
                {
                    int j, i;
                    string b;
                    Cinema a(0);

                    cinx(j, "Выберите свойство, которое вы введете, и по которому будет происходить поиск:",
                         8, "ID", "Название кинотеатра", "Кол-во залов", "Кол-во мест", "Адрес",
                         "Категория", "Состояние", "ID репертуаров");
                    if (j == 0)
                    {
                        cls();
                        break;
                    }

                    if (j == 1)
                    {
                        print("Введите ID:");
                        r_cin(a.id);
                    }

                    if (j == 2)
                    {

                        print("Введите название кинотеатра:");

                        push_line(a.name);
                    }

                    if (j == 3)
                    {
                        print("Введите кол-во залов:");
                        r_cin(a.halls);
                    }

                    if (j == 4)
                    {
                        print("Введите кол-во мест");
                        r_cin(a.places);
                    }
                    if (j == 5)
                    {
                        print("Введите адрес:");
                        push_line(a.address);
                    }
                    if (j == 6)
                    {
                        print("Введите категорию:");
                        push_line(a.category);
                    }
                    if (j == 7)
                    {
                        print("Введите состояние:");
                        r_cin(i);
                        a.state = (i == 1);
                    }
                    if (j == 8)
                    {
                        print("Введите ID репертуаров через Enter или -1 для выхода:");
                        push_vector(a.reps);
                    }
                    cout << endl;
                    a.find();

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
                        cinemas.push_back(Cinema());
                        print("Успешно добавлен");
                        print("Введите для продолжения:");
                        getchar();
                        cls();
                        break;
                    }

                    case 2:
                    {
                        for (;;)
                        {
                            int j;
                            int x = rand(10);
                            cinx(j, "Введите ключ фильма, который вы хотите удалить или -1 для выхода:");
                            if (j == -1)
                            {
                                cls();
                                break;
                            }

                            for (auto it = films.begin(); it < films.end(); it++)
                            {
                                if ((*it).id == j)
                                {

                                    print("Фильм который вы хотите удалить:");
                                    (*it).show();
                                    cout << "Для подтверждения удаления введите " << x << " :";
                                    cinx(j, "");
                                    if (j == x)
                                    {
                                        films.erase(it);
                                        print("Успех");
                                        j = -1337;
                                    }
                                    else
                                    {
                                        print("Отмена");
                                        j = -1337;
                                    }
                                    break;
                                }
                            }
                            if (j != -1337)
                            {
                                print("Фильм не был найден");
                            }
                        }

                        break;
                    }
                    case 3:
                    {
                        int j;
                        int x;
                        cinx(j, "Введите ID фильма, который нужно изменить:");
                        for (size_t i = 0; i < films.size(); i++)
                        {
                            {
                                if (films[i].id == j)
                                {
                                    print("Фильм который вы хотите изменить:");
                                    films[i].show();
                                    for (;;)
                                    {
                                        cinx(x, "Выберите свойства для его замены:", 6, "Название фильма",
                                             "Название студии", "Продюсеры", "Операторы", "Жанры", "Актеры");
                                        if (x == 0)
                                            break;
                                        if (x == 1)
                                        {
                                            print("Введите название:");
                                            films[i].name.clear();
                                            push_line(films[i].name);
                                        }
                                        if (x == 2)
                                        {
                                            print("Введите название киностудии");
                                            films[i].studio.clear();
                                            push_line(films[i].studio);
                                        }
                                        if (x == 3)
                                        {
                                            print("Введите продюсеров через Enter (-1 для прекращения ввода)");
                                            films[i].producers.clear();
                                            push_vector(films[i].producers);
                                        }
                                        if (x == 4)
                                        {
                                            print("Введите операторов через Enter (-1 для прекращения ввода)");
                                            films[i].opers.clear();
                                            push_vector(films[i].opers);
                                        }
                                        if (x == 5)
                                        {
                                            print("Введите жанры ерез Enter (-1 для прекращения ввода)");
                                            films[i].genres.clear();
                                            push_vector(films[i].genres);
                                        }
                                        if (x == 6)
                                        {
                                            print("Введите актеров ерез Enter (-1 для прекращения ввода)");
                                            films[i].actors.clear();
                                            push_vector(films[i].actors);
                                        }
                                        print("Успех");
                                    }
                                    print("Измененный фильм:");
                                    films[i].show();
                                    cc();
                                    print("Введите для продолжения");
                                    getchar();
                                    cls();
                                    break;
                                }
                            }
                        }
                    }
                    default:
                        break;
                    }

                    break;
                }
                default:
                {

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
                cinx(x, "Выберите действие:", 4, "Отобразить текущие фильмы", "Отобразить сведения фильма по ключу",
                     "Поиск фильма", "Редактирование фильмов");
                switch (x)
                {
                case 1:
                {
                    print("Список текущих фильмов:");
                    for (Film &a : films)
                        a.show();

                    print("Введите для продолжения");
                    getchar();
                    cls();
                    break;
                }
                case 2:
                {
                    int j;
                    print("Введите ключ нужного вам фильма или -1 для выхода");
                    r_cin(j);
                    if (j == -1)
                    {
                        cls();
                        break;
                    }
                    for (Film &a : films)
                    {
                        if (j == a.id)
                        {
                            a.show();
                            print("Введите для продолжения:");
                            cc();
                            getchar();
                            cls();
                            j = -1;
                        }
                    }

                    if (j != -1)
                    {
                        print("Фильма с данным ключом не существует");
                        print("Введите для продолжения:");
                        cc();
                        getchar();
                        cls();
                    }
                    break;
                }
                case 3:
                {
                    int j;
                    string b;
                    Film a(0);

                    cinx(j, "Выберите свойство, которое вы введете, и по которому будет происходить поиск:",
                         7, "ID",
                         "Название фильма", "Название студии", "Продюсеры", "Операторы", "Жанры", "Актеры");
                    if (j == 0)
                    {
                        cls();
                        break;
                    }

                    if (j == 1)
                    {
                        print("Введите ID:");
                        cin >> a.id;
                    }

                    if (j == 2)
                    {
                        print("Введите Название фильма:");
                        getline(cin, a.name);
                    }

                    if (j == 3)
                    {
                        print("Введите Название студии:");
                        getline(cin, a.studio);
                    }

                    if (j == 4)
                    {
                        print("Введите продюсеров через запятую:");
                        getline(cin, b);

                        a.producers = (e_parse(b));
                    }
                    if (j == 5)
                    {
                        print("Введите операторов через запятую:");
                        getline(cin, b);
                        a.opers = (e_parse(b));
                    }
                    if (j == 6)
                    {
                        print("Введите жанры через запятую:");
                        getline(cin, b);
                        a.genres = (e_parse(b));
                    }
                    if (j == 7)
                    {
                        print("Введите актеров через запятую:");
                        getline(cin, b);
                        a.actors = (e_parse(b));
                    }
                    cout << endl;
                    a.find();

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

                        films.push_back(Film());
                        print("Успешно добавлен");
                        print("Введите для продолжения:");
                        getchar();
                        cls();
                        break;
                    }
                    case 2:
                    {
                        for (;;)
                        {
                            int j;
                            int x = rand(10);
                            cinx(j, "Введите ключ фильма, который вы хотите удалить или -1 для выхода:");
                            if (j == -1)
                                cls();
                            break;

                            for (auto it = films.begin(); it < films.end(); it++)
                            {
                                if ((*it).id == j)
                                {

                                    print("Фильм который вы хотите удалить:");
                                    (*it).show();
                                    cout << "Для подтверждения удаления введите " << x << " :";
                                    cinx(j, "");
                                    if (j == x)
                                    {
                                        films.erase(it);
                                        print("Успех");
                                        j = -1337;
                                    }
                                    else
                                    {
                                        print("Отмена");
                                        j = -1337;
                                    }
                                    break;
                                }
                            }
                            if (j != -1337)
                            {
                                print("Фильм не был найден");
                            }
                        }

                        break;
                    }
                    case 3:
                    {
                        int j;
                        int x;
                        cinx(j, "Введите ID фильма, который нужно изменить:");
                        for (size_t i = 0; i < films.size(); i++)
                        {
                            {
                                if (films[i].id == j)
                                {
                                    print("Фильм который вы хотите изменить:");
                                    films[i].show();
                                    for (;;)
                                    {
                                        cinx(x, "Выберите свойства для его замены:", 6, "Название фильма",
                                             "Название студии", "Продюсеры", "Операторы", "Жанры", "Актеры");
                                        if (x == 0)
                                            break;
                                        if (x == 1)
                                        {
                                            print("Введите название:");
                                            films[i].name.clear();
                                            push_line(films[i].name);
                                        }
                                        if (x == 2)
                                        {
                                            print("Введите название киностудии");
                                            films[i].studio.clear();
                                            push_line(films[i].studio);
                                        }
                                        if (x == 3)
                                        {
                                            print("Введите продюсеров через Enter (-1 для прекращения ввода)");
                                            films[i].producers.clear();
                                            push_vector(films[i].producers);
                                        }
                                        if (x == 4)
                                        {
                                            print("Введите операторов через Enter (-1 для прекращения ввода)");
                                            films[i].opers.clear();
                                            push_vector(films[i].opers);
                                        }
                                        if (x == 5)
                                        {
                                            print("Введите жанры ерез Enter (-1 для прекращения ввода)");
                                            films[i].genres.clear();
                                            push_vector(films[i].genres);
                                        }
                                        if (x == 6)
                                        {
                                            print("Введите актеров ерез Enter (-1 для прекращения ввода)");
                                            films[i].actors.clear();
                                            push_vector(films[i].actors);
                                        }
                                        print("Успех");
                                    }
                                    print("Измененный фильм:");
                                    films[i].show();
                                    cc();
                                    print("Введите для продолжения");
                                    getchar();
                                    cls();
                                    break;
                                }
                            }
                        }
                    }
                    default:
                        break;
                    }

                    break;
                }
                default:
                {
                    break;
                }
                }
                if (!x)
                    break;
            }
            break;
        }
        case 3:
            for (;;)
            {
                cinx(x, "Выберите действие:", 4, "Отобразить текущие репертуары", "Отобразить сведения репертуара по ключу",
                     "Поиск репертуара", "Редактирование репертуаров");
                switch (x)
                {
                case 1:
                {
                    print("Список текущих репертуаров:");
                    for (Repertoire &a : repertoires)
                        a.show();
                    //cout << "ID : " << a.id << ". Название : " << a.name << ". Жанр : " << unvector(a.genres) << "." << endl;
                    print("Введите для продолжения");
                    getchar();
                    cls();
                    break;
                }
                case 2:
                {
                    int j;
                    print("Введите ключ нужного вам репертуара или -1 для выхода");
                    r_cin(j);
                    if (j == -1)
                    {
                        cls();
                        break;
                    }
                    for (Repertoire &a : repertoires)
                    {
                        if (j == a.id)
                        {
                            a.show();
                            print("Введите для продолжения:");
                            cc();
                            getchar();
                            cls();
                            j = -1;
                        }
                    }

                    if (j != -1)
                    {
                        print("Репертуара с данным ключом не существует");
                        print("Введите для продолжения:");
                        cc();
                        getchar();
                        cls();
                    }
                    break;
                }
                case 3:
                {
                    int j, i;
                    string b;
                    Repertoire a(0);

                    cinx(j, "Выберите свойство, которое вы введете, и по которому будет происходить поиск:",
                         5, "ID",
                         "ID фильма", "Дата", "Цена", "Свободные места");
                    if (j == 0)
                    {
                        cls();
                        break;
                    }

                    if (j == 1)
                    {
                        print("Введите ID:");
                        cin >> a.id;
                    }

                    if (j == 2)
                    {

                        print("Введите ID фильма через Enter или -1:");
                        while (i != -1)
                        {
                            r_cin(i);
                            a.film = a.film->search(i);
                        }
                    }

                    if (j == 3)
                    {
                        print("Введите дату в формате ДДММГГ (например, 30052021):");
                        getline(cin, a.date);
                    }

                    if (j == 4)
                    {
                        print("Введите цену");
                        r_cin(i);

                        a.price = i;
                    }
                    if (j == 5)
                    {
                        print("Введите количество свободных мест:");
                        r_cin(i);

                        a.free_places = i;
                    }
                    cout << endl;
                    a.find();

                    break;
                }

                case 4:
                {
                    print("Нажата 4");
                    cinx(x, "Выберите действие:", 3, "Добавить реперутар", "Удалить реперутар", "Изменить реперутар");

                    switch (x)
                    {
                    case 1:
                    {

                        repertoires.push_back(Repertoire());
                        //films[films.size() - 1].save(); //
                        print("Успешно добавлен");
                        print("Введите для продолжения:");
                        getchar();
                        cls();
                        break;
                    }
                    case 2:
                    {
                        for (;;)
                        {
                            int j;
                            int x = rand(10);
                            cinx(j, "Введите ключ репертуара, который вы хотите удалить или -1 для выхода:");
                            if (j == -1)
                            {
                                cls();
                                break;
                            }

                            for (auto it = repertoires.begin(); it < repertoires.end(); it++)
                            {
                                if ((*it).id == j)
                                {

                                    print("Репертуар который вы хотите удалить:");
                                    (*it).show();
                                    cout << "Для подтверждения удаления введите " << x << " :";
                                    cinx(j, "");
                                    if (j == x)
                                    {
                                        repertoires.erase(it);
                                        print("Успех");
                                        j = -1337;
                                    }
                                    else
                                    {
                                        print("Отмена");
                                        j = -1337;
                                    }
                                    break;
                                }
                            }
                            if (j != -1337)
                            {
                                print("Репертуар не был найден");
                            }
                        }

                        break;
                    }
                    case 3:
                    {
                        int j;
                        int x;
                        cinx(j, "Введите ID репертуара, который нужно изменить:");
                        for (size_t i = 0; i < repertoires.size(); i++)
                        {
                            {
                                if (repertoires[i].id == j)
                                {
                                    print("Репертуар который вы хотите изменить:");
                                    repertoires[i].show();
                                    for (;;)
                                    {
                                        cinx(x, "Выберите свойства для его замены:", 4, "Дата",
                                             "ID фильма", "Цена", "Кол-во свободных мест");
                                        if (x == 0)
                                            break;
                                        if (x == 1)
                                        {
                                            print("Введите дату в формате ДДММГГ (например, 30052021):");
                                            repertoires[i].date.clear();
                                            push_line(repertoires[i].date);
                                        }
                                        if (x == 2)
                                        {
                                            print("Введите ID фильма");
                                            r_cin(j);
                                            repertoires[i].film = repertoires[i].film->search(j);
                                        }
                                        if (x == 3)
                                        {
                                            print("Введите цену");
                                            r_cin(repertoires[i].price);
                                        }
                                        if (x == 4)
                                        {
                                            print("Введите кол-во свободных мест");
                                            r_cin(repertoires[i].free_places);
                                        }

                                        print("Успех");
                                    }
                                    print("Измененный репертуар:");
                                    films[i].show();
                                    cc();
                                    print("Введите для продолжения");
                                    getchar();
                                    cls();
                                    break;
                                }
                            }
                        }
                    }
                    default:
                        break;
                    }

                    break;
                }
                default:
                {
                    // cout << -12356889;
                    break;
                }
                }
                if (!x)
                    break;
            }
            break;
        default:
            set_all();
            return 0;
        }
    }
}
