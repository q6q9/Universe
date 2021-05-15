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
void push_line(string &str) //���� �� ������ �����
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
    Film(string str);
    Film();
    Film(Film const &a);
    Film(int id, string name, string studio,
         vector<string> producers, vector<string> opers,
         vector<string> genres, vector<string> actors);
    ~Film();

    void input()
    {
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

    void save()
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

    void upload();
};

Film::Film(Film const &a) : id(a.id), name(a.name), studio(a.studio), producers(a.producers),
                            opers(a.opers), genres(a.genres), actors(a.actors)
{
    // print("����������� ����������� ������������");
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
    //  print("������������ �������� ������ ��� �����������!\n");
}

Film::~Film()
{
}

void get_all(vector<Cinema> &cinemas, vector<Film> &films, vector<Repertoire> &repertoires)
{
    string line;
    ifstream in("data/films.db"); // �������� ���� ��� ������
    if (in.is_open())
    {
        while (getline(in, line))
        {
            //cout << line << endl;
            films.push_back(Film(line));
        }
    }
    print("���������� ��������� �������");
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

        cinx(y, "�������� �������, � ������� �� ������ ��������:", 3, "����������", "������", "����������");

        switch (y)
        {
        case 1:
        {
            for (;;)
            {

                print("������ 1");
                cinx(x, "�������� ��������:", 4, "���������� ������� ����������", "���������� �������� ���������� �� �����",
                     "����� �����������", "�������������� �����������");
                switch (x)
                {
                case 1:
                {
                    print("������ ������� ����������:");
                    for (Cinema const &a : cinemas)
                        cout << "ID : " << a.id << "| �������� : " << a.name << endl;
                    print("������� ��� �����������");
                    getchar();
                    break;
                }
                case 2:
                {
                    print("������� ���� ������� ��� ���������� ��� -1 ��� ������");

                    break;
                    //case 4:
                    // print("������ 4");
                    // cinx(x, "�������� ��������:", 3, "�������� �����", "������� �����", "�������� �����");
                }
                case 3:
                { //int id, int places, int halls, string name,
                    //string address, string category, bool state
                    cinx(x, "���������� ������ ��� �������� ��������� ���������:", 7, "ID",
                         "�������� ����������", "���-�� �����", "���-�� ����", "�����", "���������", "���������");
                    break;
                }

                case 4:
                {
                    print("������ 4");
                    cinx(x, "�������� ��������:", 3, "�������� ���������", "������� ���������", "�������� ���������");

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

                print("������ 1");
                cinx(x, "�������� ��������:", 4, "���������� ������� ������", "���������� �������� ������ �� �����",
                     "����� ������", "�������������� �������");
                switch (x)
                {
                case 1:
                {
                    print("������ ������� �������:");
                    for (Film const &a : films)
                        cout << "ID : " << a.id << ". �������� : " << a.name << ". ���� : " << unvector(a.genres)<<"."<< endl;
                    print("������� ��� �����������");
                    getchar();
                    break;
                }
                case 2:
                {
                    print("������� ���� ������� ��� ������ ��� -1 ��� ������");

                    break;
                    //case 4:
                    // print("������ 4");
                    // cinx(x, "�������� ��������:", 3, "�������� �����", "������� �����", "�������� �����");
                }
                case 3:
                { //int id, int places, int halls, string name,
                    //string address, string category, bool state
                    cinx(x, "���������� ������ ��� �������� ��������� ���������:", 7, "ID",
                         "�������� ������", "�������� ������", "���������", "���������", "�����", "������");
                    break;
                }

                case 4:
                {
                    print("������ 4");
                    cinx(x, "�������� ��������:", 3, "�������� �����", "������� �����", "�������� �����");

                    switch (x)
                    {
                    case 1:
                    {
                        //print("1) �������� �����");
                        films.push_back(Film());
                        print("��������");
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

                print("������ 3");
                cinx(x, "�������� ��������:", 4, "���������� ������� ����������", "���������� �������� ���������� �� �����",
                     "����� �����������", "�������������� �����������");
                switch (x)
                {
                case 1:
                {
                    print("������ ������� �����������:");
                    for (Cinema const &a : cinemas)
                        cout << "ID : " << a.id << "| �������� : " << a.name << endl;
                    print("������� ��� �����������");
                    getchar();
                    break;
                }
                case 2:
                {
                    print("������� ���� ������� ��� ���������� ��� -1 ��� ������");

                    break;
                    //case 4:
                    // print("������ 4");
                    // cinx(x, "�������� ��������:", 3, "�������� �����", "������� �����", "�������� �����");
                }
                case 3:
                { //int id, int places, int halls, string name,
                    //string address, string category, bool state
                    cinx(x, "���������� ������ ��� �������� ��������� ���������:", 5, "ID",
                         "�����", "����", "����", "��������� �����");
                    break;
                }

                case 4:
                {
                    print("������ 4");
                    cinx(x, "�������� ��������:", 3, "�������� ���������", "������� ���������", "�������� ���������");

                    switch (x)
                    {
                    case 1:
                    {
                        print("1) �������� ���������");

                        print("��������");
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