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
#include "Output.h"
#include "Film.h"
#include "Cinema.h"
#include "Repertoire.h"
#include "funcs.h"
#define d(a) a[0] << a[1] << "." << a[2] << a[3] << "." << a.substr(4, 4)
#define rand(x) engine() % x
#define ctoi(j) atoi(string({j[0]}).c_str())
using namespace std;

extern vector<Film> films;
extern vector<Cinema> cinemas;
extern vector<Repertoire> repertoires;

int main(){
    std::mt19937 engine;
    engine.seed(std::time(nullptr));
    system("chcp 1251");
    cls();
    Output out;
    int x, y;
    get_all();
    for (;;)
    {   out.put("Для СОХРАНЕНИЯ ИЗМЕНЕНИЙ выходите из программы с помощью меню!");
        cinx(y, "Выберите область, с которой вы будете работать:", 3, "Кинотеатры", "Фильмы", "Репертуары");
        switch (y){
            case 1:
                for (;;){
                    out.put("Нажата 1");
                    cinx(x, "Выберите действие:", 4, "Отобразить текущие кинотеатры", "Отобразить сведения кинотеатра по ключу",
                         "Поиск кинотеатров", "Редактирование кинотеатров");
                    switch (x){
                        case 1:
                        {out.put("Список текущих кинотетров:");
                            for (Cinema &a : cinemas)
                                a.show();
                            out.put("Введите для продолжения");
                            getchar();
                            cls();
                            break;}
                        case 2:
                        {int j;
                            out.put("Введите ключ нужного вам кинотеатра или -1 для выхода");
                            r_cin(j);
                            if (j == -1){
                                cls();
                                break;}
                            for (Cinema &a : cinemas){
                                if (j == a.id){
                                    a.show();
                                    out.put("Введите для продолжения:");
                                    cc();
                                    getchar();
                                    cls();
                                    j = -1;}}
                            if (j != -1){
                                out.put("Кинотеатра с данным ключом не существует");
                                out.put("Введите для продолжения:");
                                cc();
                                getchar();
                                cls();}
                            break;}
                        case 3:
                        {   int j, i;
                            string b;
                            Cinema a(0);
                            cinx(j, "Выберите свойство, которое вы введете, и по которому будет происходить поиск:",
                                 8, "ID", "Название кинотеатра", "Кол-во залов", "Кол-во мест", "Адрес",
                                 "Категория", "Состояние", "ID репертуаров");
                            if (j == 0) {
                                cls();
                                break;}
                            if (j == 1){out.put("Введите ID:");
                                r_cin(a.id);}
                            if (j == 2){out.put("Введите название кинотеатра:");
                                push_line(a.name);}
                            if (j == 3){
                                out.put("Введите кол-во залов:");
                                r_cin(a.halls);}
                            if (j == 4){out.put("Введите кол-во мест");
                                r_cin(a.places);}
                            if (j == 5){
                                out.put("Введите адрес:");
                                push_line(a.address);}
                            if (j == 6){out.put("Введите категорию:");
                                push_line(a.category);}
                            if (j == 7){out.put("Введите состояние:");
                                r_cin(i);
                                a.state = (i == 1);}
                            if (j == 8){out.put("Введите ID репертуаров через Enter или -1 для выхода:");
                                push_vector(a.reps);}
                            cout << endl;
                            a.find();
                            break;}
                        case 4:
                        {   out.put("Нажата 4");
                            cinx(x, "Выберите действие:", 3, "Добавить кинотеатр", "Удалить кинотеатр", "Изменить кинотеатр");
                            switch (x){
                                case 1:
                                {   cinemas.push_back(Cinema());
                                    out.put("Успешно добавлен");
                                    out.put("Введите для продолжения:");
                                    getchar();
                                    cls();
                                    break;}
                                case 2:
                                {for (;;){
                                        int j;
                                        int x = rand(10);
                                        cinx(j, "Введите ключ фильма, который вы хотите удалить или -1 для выхода:");
                                        if (j == -1){
                                            cls();
                                            break;}
                                        for (auto it = films.begin(); it < films.end(); it++){
                                            if ((*it).id == j){
                                                out.put("Фильм который вы хотите удалить:");
                                                (*it).show();
                                                cout << "Для подтверждения удаления введите " << x << " :";
                                                r_cin(x);
                                                if (j == x){
                                                    films.erase(it);
                                                    out.put("Успех");}
                                                else
                                                    out.put("Отмена");
                                                j = -1337;
                                                break;}
                                        }
                                        if (j != -1337)
                                            out.put("Фильм не был найден");
                                    }
                                    break;}
                                case 3:
                                {   int j;
                                    int x;
                                    cinx(j, "Введите ID фильма, который нужно изменить:");
                                    for (size_t i = 0; i < films.size(); i++){
                                        if (films[i].id == j){
                                            out.put("Фильм который вы хотите изменить:");
                                            films[i].show();
                                            for (;;){
                                                cinx(x, "Выберите свойства для его замены:", 6, "Название фильма",
                                                     "Название студии", "Продюсеры", "Операторы", "Жанры", "Актеры");
                                                if (x == 0)
                                                    break;
                                                if (x == 1){
                                                    out.put("Введите название:");
                                                    films[i].name.clear();
                                                    push_line(films[i].name);}
                                                if (x == 2){
                                                    out.put("Введите название киностудии");
                                                    films[i].studio.clear();
                                                    push_line(films[i].studio);}
                                                if (x == 3){
                                                    out.put("Введите продюсеров через Enter (-1 для прекращения ввода)");
                                                    films[i].producers.clear();
                                                    push_vector(films[i].producers);}
                                                if (x == 4){
                                                    out.put("Введите операторов через Enter (-1 для прекращения ввода)");
                                                    films[i].opers.clear();
                                                    push_vector(films[i].opers);}
                                                if (x == 5){
                                                    out.put("Введите жанры ерез Enter (-1 для прекращения ввода)");
                                                    films[i].genres.clear();
                                                    push_vector(films[i].genres);}
                                                if (x == 6){
                                                    out.put("Введите актеров ерез Enter (-1 для прекращения ввода)");
                                                    films[i].actors.clear();
                                                    push_vector(films[i].actors);}
                                                out.put("Успех");
                                            }
                                            out.put("Измененный фильм:");
                                            films[i].show();
                                            cc();
                                            out.put("Введите для продолжения");
                                            getchar();
                                            cls();
                                            break;
                                        }
                                    }
                                }
                                default:
                                    break;
                                    break;
                            }
                        }
                        default:
                            break;
                    }
                    if (!x)
                        break;
                }
            case 2:{
                for (;;){
                    cinx(x, "Выберите действие:", 4, "Отобразить текущие фильмы", "Отобразить сведения фильма по ключу",
                         "Поиск фильма", "Редактирование фильмов");
                    switch (x){
                        case 1:
                        {   out.put("Список текущих фильмов:");
                            for (Film &a : films)
                                a.show();
                            out.put("Введите для продолжения");
                            getchar();
                            cls();
                            break;}
                        case 2:
                        {   int j;
                            out.put("Введите ключ нужного вам фильма или -1 для выхода");
                            r_cin(j);
                            if (j == -1){
                                cls();
                                break;}
                            for (Film &a : films){
                                if (j == a.id){
                                    a.show();
                                    out.put("Введите для продолжения:");
                                    cc();
                                    getchar();
                                    cls();
                                    j = -1;}
                            }

                            if (j != -1){
                                out.put("Фильма с данным ключом не существует");
                                out.put("Введите для продолжения:");
                                cc();
                                getchar();
                                cls();}
                            break;
                        }
                        case 3:
                        {   int j;
                            string b;
                            Film a(0);
                            cinx(j, "Выберите свойство, которое вы введете, и по которому будет происходить поиск:",
                                 7, "ID",
                                 "Название фильма", "Название студии", "Продюсеры", "Операторы", "Жанры", "Актеры");
                            if (j == 0){
                                cls();
                                break;}
                            if (j == 1){
                                out.put("Введите ID:");
                                cin >> a.id;}
                            if (j == 2){
                                out.put("Введите Название фильма:");
                                getline(cin, a.name);}
                            if (j == 3){
                                out.put("Введите Название студии:");
                                getline(cin, a.studio);}
                            if (j == 4){
                                out.put("Введите продюсеров через запятую:");
                                getline(cin, b);
                                a.producers = (e_parse(b));}
                            if (j == 5){
                                out.put("Введите операторов через запятую:");
                                getline(cin, b);
                                a.opers = (e_parse(b));}
                            if (j == 6){
                                out.put("Введите жанры через запятую:");
                                getline(cin, b);
                                a.genres = (e_parse(b));}
                            if (j == 7){
                                out.put("Введите актеров через запятую:");
                                getline(cin, b);
                                a.actors = (e_parse(b));}
                            cout << endl;
                            a.find();
                            break;}
                        case 4:
                        {   out.put("Нажата 4");
                            cinx(x, "Выберите действие:", 3, "Добавить фильм", "Удалить фильм", "Изменить фильм");
                            switch (x){
                                case 1:
                                {   films.push_back(Film());
                                    out.put("Успешно добавлен");
                                    out.put("Введите для продолжения:");
                                    getchar();
                                    cls();
                                    break;}
                                case 2:
                                {   for (;;){   int j;
                                        int x = rand(10);
                                        cinx(j, "Введите ключ фильма, который вы хотите удалить или -1 для выхода:");
                                        if (j == -1)
                                            cls();
                                        break;
                                        for (auto it = films.begin(); it < films.end(); it++){
                                            if ((*it).id == j){
                                                out.put("Фильм который вы хотите удалить:");
                                                (*it).show();
                                                cout << "Для подтверждения удаления введите " << x << " :";
                                                cinx(j, "");
                                                if (j == x){
                                                    films.erase(it);
                                                    out.put("Успех");}
                                                else
                                                    out.put("Отмена");
                                                j = -1337;
                                                break;}
                                        }
                                        if (j != -1337)
                                            out.put("Фильм не был найден");
                                    }
                                    break;}
                                case 3:
                                {   int j;
                                    int x;
                                    cinx(j, "Введите ID фильма, который нужно изменить:");
                                    for (size_t i = 0; i < films.size(); i++){
                                        {   if (films[i].id == j){
                                                out.put("Фильм который вы хотите изменить:");
                                                films[i].show();
                                                for (;;){
                                                    cinx(x, "Выберите свойства для его замены:", 6, "Название фильма",
                                                         "Название студии", "Продюсеры", "Операторы", "Жанры", "Актеры");
                                                    if (x == 0)
                                                        break;
                                                    if (x == 1){
                                                        out.put("Введите название:");
                                                        films[i].name.clear();
                                                        push_line(films[i].name);}
                                                    if (x == 2){
                                                        out.put("Введите название киностудии");
                                                        films[i].studio.clear();
                                                        push_line(films[i].studio);}
                                                    if (x == 3){
                                                        out.put("Введите продюсеров через Enter (-1 для прекращения ввода)");
                                                        films[i].producers.clear();
                                                        push_vector(films[i].producers);}
                                                    if (x == 4){
                                                        out.put("Введите операторов через Enter (-1 для прекращения ввода)");
                                                        films[i].opers.clear();
                                                        push_vector(films[i].opers);}
                                                    if (x == 5){
                                                        out.put("Введите жанры ерез Enter (-1 для прекращения ввода)");
                                                        films[i].genres.clear();
                                                        push_vector(films[i].genres);}
                                                    if (x == 6){
                                                        out.put("Введите актеров ерез Enter (-1 для прекращения ввода)");
                                                        films[i].actors.clear();
                                                        push_vector(films[i].actors);}
                                                    out.put("Успех");
                                                }
                                                out.put("Измененный фильм:");
                                                films[i].show();
                                                cc();
                                                out.put("Введите для продолжения");
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
                            break;
                    }
                    if (!x)
                        break;
                }
                break;}
            case 3:
                for (;;){
                    cinx(x, "Выберите действие:", 4, "Отобразить текущие репертуары", "Отобразить сведения репертуара по ключу",
                         "Поиск репертуара", "Редактирование репертуаров");
                    switch (x){
                        case 1:
                        {   out.put("Список текущих репертуаров:");
                            for (Repertoire &a : repertoires)
                                a.show();
                            //cout << "ID : " << a.id << ". Название : " << a.name << ". Жанр : " << unvector(a.genres) << "." << endl;
                            out.put("Введите для продолжения");
                            getchar();
                            cls();
                            break;}
                        case 2:
                        {   int j;
                            out.put("Введите ключ нужного вам репертуара или -1 для выхода");
                            r_cin(j);
                            if (j == -1){
                                cls();
                                break;}
                            for (Repertoire &a : repertoires){
                                if (j == a.id){
                                    a.show();
                                    out.put("Введите для продолжения:");
                                    cc();
                                    getchar();
                                    cls();
                                    j = -1;}
                            }
                            if (j != -1){
                                out.put("Репертуара с данным ключом не существует");
                                out.put("Введите для продолжения:");
                                cc();
                                getchar();
                                cls();}
                            break;}
                        case 3:
                        {int j, i;
                            string b;
                            Repertoire a(0);
                            cinx(j, "Выберите свойство, которое вы введете, и по которому будет происходить поиск:",
                                 5, "ID",
                                 "ID фильма", "Дата", "Цена", "Свободные места");
                            if (j == 0){
                                cls();
                                break;}
                            if (j == 1){
                                out.put("Введите ID:");
                                cin >> a.id;}
                            if (j == 2){
                                out.put("Введите ID фильма через Enter или -1:");
                                while (i != -1){
                                    r_cin(i);
                                    a.film = a.film->search(i);}
                            }
                            if (j == 3){
                                out.put("Введите дату в формате ДДММГГ (например, 30052021):");
                                getline(cin, a.date);}
                            if (j == 4){
                                out.put("Введите цену");
                                r_cin(i);
                                a.price = i;}
                            if (j == 5){
                                out.put("Введите количество свободных мест:");
                                r_cin(i);
                                a.free_places = i;}
                            cout << endl;
                            a.find();
                            break;}
                        case 4:
                        {   out.put("Нажата 4");
                            cinx(x, "Выберите действие:", 3, "Добавить реперутар", "Удалить реперутар", "Изменить реперутар");
                            switch (x){
                                case 1:
                                {   repertoires.push_back(Repertoire());
                                    //films[films.size() - 1].save(); //
                                    out.put("Успешно добавлен");
                                    out.put("Введите для продолжения:");
                                    getchar();
                                    cls();
                                    break;}
                                case 2:
                                {   for (;;)
                                    {   int j;
                                        int x = rand(10);
                                        cinx(j, "Введите ключ репертуара, который вы хотите удалить или -1 для выхода:");
                                        if (j == -1){
                                            cls();
                                            break;}
                                        for (auto it = repertoires.begin(); it < repertoires.end(); it++){
                                            if ((*it).id == j){
                                                out.put("Репертуар который вы хотите удалить:");
                                                (*it).show();
                                                cout << "Для подтверждения удаления введите " << x << " :";
                                                cinx(j, "");
                                                if (j == x){
                                                    repertoires.erase(it);
                                                    out.put("Успех");}
                                                else
                                                    out.put("Отмена");
                                                j = -1337;
                                                break;}
                                        }
                                        if (j != -1337)
                                            out.put("Репертуар не был найден");
                                    }
                                    break;}
                                case 3:
                                {   int j;
                                    int x;
                                    cinx(j, "Введите ID репертуара, который нужно изменить:");
                                    for (size_t i = 0; i < repertoires.size(); i++){
                                        if (repertoires[i].id == j){
                                            out.put("Репертуар который вы хотите изменить:");
                                            repertoires[i].show();
                                            for (;;){
                                                cinx(x, "Выберите свойства для его замены:", 4, "Дата",
                                                     "ID фильма", "Цена", "Кол-во свободных мест");
                                                if (x == 0)
                                                    break;
                                                if (x == 1){
                                                    out.put("Введите дату в формате ДДММГГ (например, 30052021):");
                                                    repertoires[i].date.clear();
                                                    push_line(repertoires[i].date);}
                                                if (x == 2){
                                                    out.put("Введите ID фильма");
                                                    r_cin(j);
                                                    repertoires[i].film = repertoires[i].film->search(j);}
                                                if (x == 3){
                                                    out.put("Введите цену");
                                                    r_cin(repertoires[i].price);}
                                                if (x == 4){
                                                    out.put("Введите кол-во свободных мест");
                                                    r_cin(repertoires[i].free_places);}
                                                out.put("Успех");
                                            }
                                            out.put("Измененный репертуар:");
                                            films[i].show();
                                            cc();
                                            out.put("Введите для продолжения");
                                            getchar();
                                            cls();
                                            break;
                                        }
                                    }
                                }
                                default:
                                    break;}
                            break;
                        }
                        default:
                        {break;}
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
