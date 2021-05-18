#ifndef Film_h
#define Film_h
#include "Film.cpp"
#include <iostream>
#include <vector>
using namespace std;

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
    //Film *
    Film(string str);
    Film();
    Film(int a);
    Film(Film const &a);
    Film(int id, string name, string studio,
         vector<string> producers, vector<string> opers,
         vector<string> genres, vector<string> actors);
    ~Film();

    //123467
    //10
    void set_id()
    {
        id = 1;
        bool z = false;
        // vector<Film> films;
        // get_films(films);
        // vector<int> ids(films.size());
        for (;;)
        {
            z = false;
            for (Film const &a : films)
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
    void input()
    {
        set_id();
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

    void find()
    {
        // vector<Film> films;
        vector<Film> _films;
        // get_films(films);
        // cout << -1114213;

        if (id)
        {
            for (Film a : films)
            {
                if (id == a.id)
                {
                    if (!binary_search(_films.begin(), _films.end(), a))
                    {
                        a.show();
                    }
                    else
                        _films.push_back(a);
                }
            }
            cc();
        }
        if (!name.empty())
        {
            for (Film a : films)
            {
                if (low(name) == low(a.name))
                {
                    if (!binary_search(_films.begin(), _films.end(), a))
                    {
                        a.show();
                    }
                    else
                        _films.push_back(a);
                }
            }
        }
        if (!studio.empty())
        {
            for (Film a : films)
            {
                if (low(studio) == low(a.studio))
                {
                    if (!binary_search(_films.begin(), _films.end(), a))
                    {
                        a.show();
                    }
                    else
                        _films.push_back(a);
                }
            }
        }
        if (!producers.empty())
        {
            for (Film a : films)
            {
                for (string &x : producers)
                {
                    for (string &y : a.producers)
                    {
                        // cout << low(x) << "==" << low(y) << endl;
                        if (low(x) == low(y))
                        {
                            if (!binary_search(_films.begin(), _films.end(), a))
                            {
                                a.show();
                                _films.push_back(a);
                            }
                        }
                    }
                }
            }
        }
        if (!opers.empty())
        {
            for (Film a : films)
            {
                for (string &x : opers)
                {
                    for (string &y : a.opers)
                    {
                        // cout << low(x) << "==" << low(y) << endl;
                        if (low(x) == low(y))
                        {
                            if (!binary_search(_films.begin(), _films.end(), a))
                            {
                                a.show();
                                _films.push_back(a);
                            }
                        }
                    }
                }
            }
        }
        if (!genres.empty())
        {
            for (Film a : films)
            {
                for (string &x : genres)
                {
                    for (string &y : a.genres)
                    {
                        if (low(x) == low(y))
                        {
                            if (!(binary_search(_films.begin(), _films.end(), a)))
                            {
                                a.show();
                                _films.push_back(a);
                            }
                        }
                    }
                }
            }
        }
        if (!actors.empty())
        {
            for (Film a : films)
            {
                for (string &x : actors)
                {
                    for (string &y : a.actors)
                    {
                        if (low(x) == low(y))
                        {
                            if (!binary_search(_films.begin(), _films.end(), a))
                            {
                                a.show();
                                _films.push_back(a);
                            }
                        }
                    }
                }
            }
        }
        _films.clear();
        print("Введите для продолжения:");

        getchar();
        cls();
    }

    void show()
    {
        cout << "ID : " << id << ". Название : " << name << ". Жанр(ы) : " << unvector(genres)
             << ". Студия : " << studio << ".\nПродюссер(ы) : " << unvector(producers)
             << ". Оператор(ы) : " << unvector(opers)
             << ".\nАктер(ы) : " << unvector(actors) << endl
             << endl;
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

    bool operator<(const Film &a) const
    {
        // cout <<"\t"<< this->id<<"_"<<a.id<<"\n_______"<< ((this->id == a.id) && (this->name == a.name) && (this->studio == a.studio) &&
        //     (this->producers == a.producers) && (this->opers == a.opers) &&
        //(this->genres == a.genres) && (this->actors == a.actors)) <<endl;
        if ((this->id == a.id) && (this->name == a.name) && (this->studio == a.studio) &&
            (this->producers == a.producers) && (this->opers == a.opers) &&
            (this->genres == a.genres) && (this->actors == a.actors))
            return false;
        return true;
    }
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
Film::Film(int a) {}
Film::Film(int id, string name, string studio,
           vector<string> producers, vector<string> opers,
           vector<string> genres, vector<string> actors) : id(id), name(name), studio(studio), producers(producers),
                                                           opers(opers), genres(genres), actors(actors)
{
    //  print("Конуструктор создания фильма был сипользован!\n");
}

Film::~Film();

#endif