#include "Repertoire.h"
#include "funcs.h"
#include <fstream>
#define d(a) a[0] << a[1] << "." << a[2] << a[3] << "." << a.substr(4, 4)


class Cinema;
extern vector<Film> films;
extern vector<Cinema> cinemas;
extern vector<Repertoire> repertoires;

Repertoire::Repertoire(int a) {}
Repertoire::Repertoire() { input(); }
Repertoire::Repertoire(int id, int price, int free_places,
                       string date, Film *film) : id(id), price(price),
                                                  free_places(free_places), date(date), film(film)
{
}
Repertoire::Repertoire(string str)
{
    regex reg("\\w+");
    vector<string> a;
    a = parsing(reg, str);
    int d = stoi(a[1]);
    *this = Repertoire(stoi(a[0]), stoi(a[2]), stoi(a[3]), a[4], film->search(d));
}
Repertoire::~Repertoire()
{
}
Repertoire::Repertoire(Repertoire const &a) : Repertoire(a.id, a.price, a.free_places, a.date, a.film) {}

Repertoire * Repertoire::search(int &j)
{
    for (Repertoire &a : repertoires)
    {
        if (j == a.id)
        {
            return (&a);
            a.show();
        }
    }
    return 0;
}
void Repertoire::set_id()
{
    id = 1;
    bool z = false;
    for (;;)
    {
        z = false;
        for (Repertoire const &a : repertoires)
            if (id == a.id)
            {
                z = true;
                id++;
                continue;
            }
        if (!z)
            return;
    }
}
void Repertoire::input()
{
    int i;
    set_id();
    print("Введите дату в формате ДДММГГ (например, 30052021):");
    push_line(date);
    print("Введите ID фильма");
    r_cin(i);
    film = film->search(i);
    print("Введите цену билета");
    r_cin(price);
    print("Введите кол-во свободных мест");
    r_cin(free_places);
    print("Успех");
    cc;
    print("Введите для продолжения:");
    getchar();
    cls();
}
void Repertoire::find()
{
    vector<Repertoire> _reps;
    if (id)
    {
        for (Repertoire a : repertoires)
        {
            if (id == a.id)
            {
                if (!binary_search(_reps.begin(), _reps.end(), a))
                {
                    a.show();
                }
                else
                    _reps.push_back(a);
            }
        }
        cc();
    }
    if (price)
    {
        for (Repertoire a : repertoires)
        {
            if (price == a.price)
            {
                if (!binary_search(_reps.begin(), _reps.end(), a))
                {
                    a.show();
                }
                else
                    _reps.push_back(a);
            }
        }
        cc();
    }
    if (free_places)
    {
        for (Repertoire a : repertoires)
        {
            if (free_places == a.free_places)
            {
                if (!binary_search(_reps.begin(), _reps.end(), a))
                {
                    a.show();
                }
                else
                    _reps.push_back(a);
            }
        }
        cc();
    }
    if (!date.empty())
    {
        for (Repertoire a : repertoires)
        {
            if (date == a.date)
            {
                if (!binary_search(_reps.begin(), _reps.end(), a))
                {
                    a.show();
                }
                else
                    _reps.push_back(a);
            }
        }
        cc();
    }
    if (!date.empty())
    {
        for (Repertoire a : repertoires)
        {
            if (film == a.film)
            {
                if (!binary_search(_reps.begin(), _reps.end(), a))
                {
                    a.show();
                }
                else
                    _reps.push_back(a);
            }
        }
        cc();
    }
    if (_reps.empty())
        print("Ничего не найдено");
    _reps.clear();
    print("Введите для продолжения:");
    getchar();
    cls();
}
void Repertoire::save()
{
    ofstream out("data/repertoires.db", ios::app);
    if (out.is_open())
    {
        out << id << " " << film->id << " " << price << " "
            << free_places << " " << date << " ";
    }
    out.close();
    print("Репертуар сохранен");
}
void Repertoire::show(string tab)
{
    int j;
    cout << "ID : " << id << ". Дата : " << d(date) << ". Цена : " << price
         << ".\n"<< tab<<"Кол-во свободных мест: : " << free_places << ".\n  "<<tab
         <<"Фильм : " << endl<<endl;
    for (Film &a : films)
    {
        if (film == &a)
        {
            cout<<"        "+tab;
            film->show("        "+tab);
            return;
        }
    }
    print("Фильма с таким ID не существует");
}

bool    Repertoire::operator<(const Repertoire &a) const

    {
        if ((this->id == a.id) && (this->date == a.date) && (this->film == a.film) &&
            (this->free_places == a.free_places) && (this->price == a.price))
            return false;
        return true;
    }