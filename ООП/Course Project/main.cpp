#include <iostream>
#include <vector>
#include <stdarg.h>
#include <fstream>
#include <string>
#include <numeric>
//#include <windows.h>
//#include <clocale>

using namespace std;
class Cinema;
class Film;
class Repertoire;
void print(string text) { cout << text << endl; } //����� ������
void cls() { printf("\e[1;1H\e[2J"); }            //������� �������
void menu(int i, ...)                             //����������� ����
{
    va_list t;
    va_start(t, i);
    print("�������� ��������:");
    for (size_t j = 0; j <= i; j++)
        printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "��������� (�����)"));
}
void cc() //������� ������ �����
{
    cin.clear();
    cin.ignore(32767, '\n');
}
void cinx(int &x, string text, int i, ...) //���� x
{

    print(text);
    va_list t;
    va_start(t, i);
    for (size_t j = 0; j <= i; j++)
        printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "��������� (�����)"));
    cin >> x;
    while (cin.fail() || (x < 0 || x > i))
    {
        cc();
        cout << "�������� �������� (������� ����� �� 1 �� " << i << ")" << endl;
        cin >> x;
    }
    cc();
    cls();
}
void get_all(vector<Cinema> &cinemas, vector<Film> &films, vector<Repertoire> &repertoires)
{
    string line;
    ifstream in("/data/cinemas.db"); // �������� ���� ��� ������
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
}
string str(vector<string> &b)
{
    string a = "<";
    for (string &x : b)
        a += "'" + x + "'";

    return a + ">";
}
string str(string &b)
{
    return "<" + b + ">";
}
void push_vector(vector<string>&a){
    string b;
    for (;;)
        {
            getline(cin, b);
            if (b == "-1")
                break;
            if (b != "")
                a.push_back(b);
        }
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

    // �������� ����� .db:
    // id <name> <studio> <producers> <opers> <genres> <actors>
    // <.. , .. , ..>
public:
    int id;
    string name, studio;
    vector<string> producers;
    vector<string> opers;
    vector<string> genres;
    vector<string> actors;
    Film(string name, string genre);
    Film() { print("������ ������ �����"); }
    ~Film();

    void input()
    {

        // string const a[] = {"��������", "����������",
        //                     "���������� ����� Enter (-1 ��� ����������� �����)",
        //                     "���������� ����� Enter (-1 ��� ����������� �����)",
        //                     "����� ���� Enter (-1 ��� ����������� �����)",
        //                     "������� ���� Enter (-1 ��� ����������� �����)"};
        //string *const a[] = {&name, &studio};

        print("������� ��������:");
        getline(cin, name);
        print("������� �������� ����������");
        getline(cin, studio);
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

    void save()
    {
        ofstream out("data/films.db", ios::app);
        if (out.is_open())
        {
            out << id << str(name) << str(studio) << str(producers)
                << str(opers) << str(genres) << str(actors) << endl;
        }
        out.close();
    }
};

// Film::Film(string name, string genre) : name(name), genre(genre)
// {
//     print("Create new film!");
//     cout << "�������� - " << name << ", ���� - " << genre << endl;
// }

Film::~Film()
{
}

int main()
{
    system("chcp 1251");
    cls();

    int x;
    bool flag = true;
    vector<Film> films;
    vector<Cinema> cinemas;
    vector<Repertoire> repertoires;
    get_all(cinemas, films, repertoires);

    cinx(x, "�������� �������, � ������� �� ������ ��������:", 3, "����������", "������", "����������");

    switch (x)
    {
    case 1:
        print("������ 1");

        cinx(x, "�������� ��������:", 4, "���������� ������� ����������", "���������� �������� ���������� �� �����",
             "����� �����������", "�������������� �����������");
        switch (x)
        {
        case 1:
            print("������ ������� ����������:");
            break;
        case 4:
            print("������ 4");
            cinx(x, "�������� ��������:", 3, "�������� �����", "������� �����", "�������� �����");

            switch (x)
            {
            case 1:
            {
                print("1) �������� �����");
                Film a;
                a.input();
                a.save();
                print("��������");
                break;
            }
            default:
                break;
            }

            break;

        case 2:
            print("������ 2");
            flag = false;
            break;

        case 3:
            print("������ 3");
            flag = false;
            break;

        default:
            break;
        }
        break;
    // case 0:
    //     return 0;
    default:
        // print("�������� �������� (������� ����� �� 1 �� 3)");
        return 0;
    }

    getchar();
    return 0;
}