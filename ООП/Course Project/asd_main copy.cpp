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
#include "asd.h"
#define d(a) a[0] << a[1] << "." << a[2] << a[3] << "." << a.substr(4, 4)
#define rand(x) engine() % x
#define ctoi(j) atoi(string({j[0]}).c_str())
using namespace std;


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
