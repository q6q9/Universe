#include "Film.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdarg.h>
#include <string>
#include <regex>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <random>
#include "Repertoire.h"

void cc();
void print(string text);
void r_cin(int &j);
void to_lower(char *c);
string low(string s);
vector<string> low(vector<string> x);
void reverseStr(string &str);
vector<string> e_parse(string str);
void get_films(vector<Film> &films);
void get_all();
string unvector(const vector<string> &a);
void cls();
void menu(int i, ...);
void cc();
void cinx(int &x, string text, int i, ...);
void cinx(int &x, string text);
void cinx(string &x, string text, int i, ...);
void push_line(string &str);
string str(vector<string> &b);
string str(string &b);
void push_vector(vector<string> &a);
vector<string> parsing(string &str, regex &reg);
vector<string> parsing(regex &reg, string &str);
void get_films();
void get_repertoires();
void get_cinemas();
void get_all();
void set_all();
void push_vector(vector<Repertoire *> &a);

// class Cinema;
// class Repertoire;

vector<Film> films;
// vector<Cinema> cinemas;
vector<Repertoire> repertoires;

Film::Film(Film const &a) : id(a.id), name(a.name), studio(a.studio), producers(a.producers),
                            opers(a.opers), genres(a.genres), actors(a.actors) {}
Film::Film(string str)
{
    regex reg("\\d+");
    sregex_iterator abc(str.begin(), str.end(), reg);
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
                                                           opers(opers), genres(genres), actors(actors) {}
Film::~Film() {}
Film *search(int &j)
{

    for (Film &a : films)
    {
        if (j == a.id)
        {
            return &a;
            a.show();
        }
    }
    return 0;
}
void Film::set_id()
{
    id = 1;
    bool z = false;
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
void Film::input()
{
    set_id();
    print("������� ��������:");
    push_line(name);
    print("������� �������� ����������");
    push_line(studio);
    print("������� ���������� ����� Enter (-1 ��� ����������� �����)");
    push_vector(producers);
    print("������� ���������� ����� Enter (-1 ��� ����������� �����)");
    push_vector(opers);
    print("������� ����� ���� Enter (-1 ��� ����������� �����)");
    push_vector(genres);
    print("������� ������� ���� Enter (-1 ��� ����������� �����)");
    push_vector(actors);
    print("�����");
}
void Film::find()
{
    vector<Film> _films;
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
    print("������� ��� �����������:");
    getchar();
    cls();
}
void Film::show()
{
    cout << "ID : " << id << ". �������� : " << name << ". ����(�) : " << unvector(genres)
         << ". ������ : " << studio << ".\n���������(�) : " << unvector(producers)
         << ". ��������(�) : " << unvector(opers)
         << ".\n�����(�) : " << unvector(actors) << endl
         << endl;
}
void Film::save()
{
    ofstream out("data/films.db", ios::app);
    if (out.is_open())
    {
        out << id << str(name) << str(studio) << str(producers)
            << str(opers) << str(genres) << str(actors) << endl;
    }
    out.close();
    print("����� ��������");
}

// bool operator<(Film &b, const Film &a)
// {
//     if ((b.id == a.id) && (b.name == a.name) && (b.studio == a.studio) &&
//         (b.producers == a.producers) && (b.opers == a.opers) &&
//         (b.genres == a.genres) && (b.actors == a.actors))
//         return false;
//     return true;
// }
bool Film::operator<(const Film &a) const
    {
        if ((this->id == a.id) && (this->name == a.name) && (this->studio == a.studio) &&
            (this->producers == a.producers) && (this->opers == a.opers) &&
            (this->genres == a.genres) && (this->actors == a.actors))
            return false;
        return true;
    }