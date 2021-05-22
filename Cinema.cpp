#include "Cinema.h"
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
#include "funcs.h"
#include "Repertoire.h"

vector<Film> films;
vector<Cinema> cinemas;
vector<Repertoire> repertoires;

Cinema::Cinema(Cinema const &a) : Cinema(a.id, a.places, a.halls, a.name, a.address, a.category, a.state, a.reps) {}
Cinema::Cinema(int a) {}
Cinema::Cinema() { input(); }
Cinema::Cinema(string str)
{
    regex reg("<.*?>");
    vector<string> a;
    vector<string> h;
    vector<Repertoire *> c;
    a = parsing(str, reg);
    int f;
    reg = ("\\d+");
    h = parsing(reg, a[7]);
    Repertoire x(0);
    for (string &z : h)
    {
        f = stoi(z);
        if (x.search(f) != NULL)
        {
            c.push_back(x.search(f));
        }
    }
    *this = Cinema(stoi(a[0]), stoi(a[2]), stoi(a[3]), a[1], a[4], a[5], (a[6] == "1"), c);
}
Cinema::Cinema(int id, int places, int halls, string name,
               string address, string category, bool state, vector<Repertoire *> reps) : id(id), places(places), halls(halls), name(name),
                                                                                         address(address), category(category), state(state), reps(reps)
{
}
Cinema::~Cinema() {}

void Cinema::set_id()
{
    id = 1;
    bool z = false;
    for (;;)
    {
        z = false;
        for (Cinema const &a : cinemas)
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
void Cinema::find()
    {
        vector<Cinema> _cinemas;
        if (id)
        {
            for (Cinema a : cinemas)
            {
                if (id == a.id)
                {
                    if (!binary_search(_cinemas.begin(), _cinemas.end(), a))
                    {
                        a.show();
                    }
                    else
                        _cinemas.push_back(a);
                }
            }
            cc();
        }
        if (places)
        {
            for (Cinema a : cinemas)
            {
                if (places == a.places)
                {
                    if (!binary_search(_cinemas.begin(), _cinemas.end(), a))
                    {
                        a.show();
                    }
                    else
                        _cinemas.push_back(a);
                }
            }
        }
        if (halls)
        {
            for (Cinema a : cinemas)
            {
                if (halls == a.halls)
                {
                    if (!binary_search(_cinemas.begin(), _cinemas.end(), a))
                    {
                        a.show();
                    }
                    else
                        _cinemas.push_back(a);
                }
            }
        }
        if (state)
        {
            for (Cinema a : cinemas)
            {
                if (state == a.state)
                {
                    if (!binary_search(_cinemas.begin(), _cinemas.end(), a))
                    {
                        a.show();
                    }
                    else
                        _cinemas.push_back(a);
                }
            }
        }
        if (!name.empty())
        {
            for (Cinema a : cinemas)
            {
                if (name == a.name)
                {
                    if (!binary_search(_cinemas.begin(), _cinemas.end(), a))
                    {
                        a.show();
                    }
                    else
                        _cinemas.push_back(a);
                }
            }
        }
        if (!address.empty())
        {
            for (Cinema a : cinemas)
            {
                if (address == a.address)
                {
                    if (!binary_search(_cinemas.begin(), _cinemas.end(), a))
                    {
                        a.show();
                    }
                    else
                        _cinemas.push_back(a);
                }
            }
        }
        if (!category.empty())
        {
            for (Cinema a : cinemas)
            {
                if (category == a.category)
                {
                    if (!binary_search(_cinemas.begin(), _cinemas.end(), a))
                    {
                        a.show();
                    }
                    else
                        _cinemas.push_back(a);
                }
            }
        }
        if (!reps.empty())
        {
            for (Cinema a : cinemas)
            {
                if (reps == a.reps)
                {
                    if (!binary_search(_cinemas.begin(), _cinemas.end(), a))
                    {
                        a.show();
                    }
                    else
                        _cinemas.push_back(a);
                }
            }
        }
        if (_cinemas.empty())
        {
            print("������ �� �������");
        }

        print("������� ��� �����������:");
        _cinemas.clear();
        getchar();
        cls();
    }
void Cinema::show()
{
    bool flag;
    cout << "ID : " << id << ". �������� : " << name << ". ����� : " << address
         << ". ��������� : " << category << ".\n ���-�� ���� : " << places
         << ". ���-�� ����� : " << halls
         << ". ��������� : " << ((1 == state) ? ("��������") : ("�� ��������")) << ". \n\t ���������� :\n\n";
    for (Repertoire *&a : reps)
    {
        flag = false;
        for (Repertoire &b : repertoires)
        {
            if (a == &b)
            {
                b.show();
                flag = true;
                break;
            }
        }
        print("____________________________________________________");
        if (!flag)
            print("���������� � ����� ID �� ����������");
    }
}
void Cinema::save()
{
    ofstream out("data/cinemas.db", ios::app);
    if (out.is_open())
    {
        out << "<" << id << "><" << name << "><" << places << "><" << halls << "><" << address
            << "><" << category << "><" << state << "><";
        for (Repertoire *&a : reps)
        {
            out << a->id << " ";
        }
        out << ">" << endl;
    }
    out.close();
    print("��������� ��������");
}
void Cinema::input()
{
    int i;
    vector<int> str;
    set_id();
    print("������� �������� ����������:");
    push_line(name);
    print("������� ����� ����������:");
    push_line(address);
    print("������� ��������� ����������:");
    push_line(category);
    print("������� ���-�� ����:");
    r_cin(places);
    print("������� ���-�� �����:");
    r_cin(halls);
    print("������� 1, ���� ��������� ��������, 0 ���� ���:");
    r_cin(i);
    state = (i == 1);
    print("������� ID ����������� ����� Enter ��� -1 ��� ������:");
    push_vector(reps);
    print("�����");
}

bool Cinema::operator<(const Cinema &a) const

    {
        if ((this->id == a.id) && (this->name == a.name) && (this->halls == a.halls) &&
            (this->places == a.places) && (this->state == a.state) &&
            (this->address == a.address) && (this->category == a.category) && (this->reps == a.reps))
            return false;
        return true;
    }