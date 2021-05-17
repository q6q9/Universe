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

#define rand(x) engine() % x
#define ctoi(j) atoi(string({j[0]}).c_str())
using namespace std;

class Cinema;
class Film;
class Repertoire;

vector<Film> films;
vector<Cinema> cinemas;
vector<Repertoire> repertoires;

void to_lower(char *c)
{
    if (*c >= 'A' && *c <= 'Z')
    {
        *c = *c + 'a' - 'A';
    }
    if (*c >= '�' && *c <= '�')
    {
        *c = *c + 'a' - 'A';
    }
}
string low(string s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        to_lower(&s[i]);
    }
    return s;
}
vector<string> low(vector<string> x)
{
    for (string &s : x)
        for (size_t i = 0; i < s.size(); i++)
            s[i] = tolower(s[i], locale("ru"));

    for (string &s : x)
        cout << s << endl;
    return x;
}
void reverseStr(string &str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
vector<string> e_parse(string str)
{
    int i = 0, j, y;
    string word;
    vector<string> a;
    while (i < str.size())
    {
        word = "";
        while (str[i] != ',' && i < str.size())
        {
            // cout << "1 " << str[i] << endl;
            word += str[i];
            i++;
        }
        j = 0;
        // cout << "1.5 " << word[j] << endl;
        if (word[j] == ' ')
        {
            for (j = 0; j < word.size(); j++)
            {
                // cout << "2 " << word[j] << endl;
                if (word[j] != ' ')
                {
                    j += word.size();
                }
            };
            // cout << "2.5 " << word[j] << endl;
            word = word.substr(j - word.size() - 1);
        }
        for (j = 0; j < word.size(); j++)
        {
            // cout << "3 " << word[j] << endl;
            if (word[j] == ' ')
            {
                break;
            }
        };
        for (y = j; y < word.size(); y++)
        {
            // cout << "4 " << word[y] << endl;
            if (word[y] != ' ')
            {
                break;
            }
        };
        word = word.substr(0, j + 1) + word.substr(y);

        reverseStr(word);
        j = 0;
        // cout << "3.5 " << word[j] << endl;
        if (word[j] == ' ')
        {
            for (j = 0; j < word.size(); j++)
            {
                // cout << "2 " << word[j] << endl;
                if (word[j] != ' ')
                {
                    j += word.size();
                }
            };
            // cout << "2.5 " << word[j] << endl;
            word = word.substr(j - word.size() - 1);
        }
        reverseStr(word);
        a.push_back(word);
        i++;
    }
    // for(string b:a)cout<<b<<endl;
    return a;
}
void get_films(vector<Film> &films);
void get_all(vector<Cinema> &cinemas, vector<Film> &films, vector<Repertoire> &repertoires);
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
void cinx(int &x, string text)
{
    print(text);
    cin >> x;
    while (cin.fail())
    {
        cc();
        cout << "�������� �������� (������� �����)" << endl;
        cin >> x;
    }
}
void cinx(string &x, string text, int i, ...) //���� x
{

    print(text);
    va_list t;
    va_start(t, i);
    for (size_t j = 0; j <= i; j++)
        printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "��������� (�����)"));
    // getline(cin, x);

    // while ((ctoi(x) < 0) || (ctoi(x) > i) || (x[1] != ' '))
    // {

    //     cout << "�������� �������� (������� ����� �� 1 �� " << i << " � �������)" << endl;
    //     getline(cin, x);
    // }
    // cc();
    // cls();
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
        if (a == "")
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

        // cout << "_" << b << "_" << endl;
        if (x == "")
        {
            print("Err: empty line");
            continue;
        }
        if (b == "-1" && a.size() > 0)
            break;
        a.push_back(b);
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
void r_cin(int &j)
{
    for (;;)
    {
        cin >> j;
        if (cin.fail())
            cc();
        else
            break;
        print("�������� ����, ���������� ������ �����:");
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
    string date; //01.07.2021
    Film *film; 
    Repertoire(int id, int price, int free_places,
               string date, Film *film);
    Repertoire(Repertoire &a):Repertoire(a.id, a.price, a.free_places, a.date, a.film){}
    
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
        print("������� ��� �����������:");

        getchar();
        cls();
    }

    void show()
    {
        cout << "ID : " << id << ". �������� : " << name << ". ����(�) : " << unvector(genres)
             << ". ������ : " << studio << ".\n���������(�) : " << unvector(producers)
             << ". ��������(�) : " << unvector(opers)
             << ".\n�����(�) : " << unvector(actors) << endl
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
        print("����� ��������");
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
Film::Film(int a) {}
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
void get_films()
{
    films.clear();
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
}
void get_all(/*vector<Cinema> &cinemas, vector<Film> &films, vector<Repertoire> &repertoires*/) //�������� ������
{
    get_films();
    print("���������� ��������� �������");
}
void set_all(/*vector<Cinema> &cinemas, vector<Film> &films, vector<Repertoire> &repertoires*/) //���������� ������
{
    ofstream out;              // ����� ��� ������
    out.open("data/films.db"); // �������� ���� ��� ������
    out.close();
    out.open("data/films.db");

    if (out.is_open())
    {
        for (Film &a : films)
        {
            a.save();
        }
        out.close();
    }
    print("���������� ��������� �������");
}

int main()
{
    std::mt19937 engine; // mt19937 ��� ���� �� ���������
    engine.seed(std::time(nullptr));
    system("chcp 1251");
    cls();

    //cout << low("������ ���");
    //e_parse(" ������� �����,��������� ������,������ ���� ");
    int x, y;

    get_all();

    // for (Film &x : films)
    // {
    //     x.show();
    // }
    for (;;)
    {
        print("��� ���������� ��������� �������� �� ��������� � ������� ����!");
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
                    //cout << -12356889;
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
                cinx(x, "�������� ��������:", 4, "���������� ������� ������", "���������� �������� ������ �� �����",
                     "����� ������", "�������������� �������");
                switch (x)
                {
                case 1:
                {
                    print("������ ������� �������:");
                    for (Film &a : films)
                        a.show();
                    //cout << "ID : " << a.id << ". �������� : " << a.name << ". ���� : " << unvector(a.genres) << "." << endl;
                    print("������� ��� �����������");
                    getchar();
                    cls();
                    break;
                }
                case 2:
                {
                    int j;
                    print("������� ���� ������� ��� ������ ��� -1 ��� ������");
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
                            print("������� ��� �����������:");
                            cc();
                            getchar();
                            cls();
                            j = -1;
                        }
                    }

                    if (j != -1)
                    {
                        print("������ � ������ ������ �� ����������");
                        print("������� ��� �����������:");
                        cc();
                        getchar();
                        cls();
                    }
                    break;
                    //case 4:
                    // print("������ 4");
                    // cinx(x, "�������� ��������:", 3, "�������� �����", "������� �����", "�������� �����");
                }
                case 3:
                {
                    int j;
                    string b;
                    Film a(0);

                    cinx(j, "�������� ��������, ������� �� �������, � �� �������� ����� ����������� �����:",
                         7, "ID",
                         "�������� ������", "�������� ������", "���������", "���������", "�����", "������");

                    // getline(cin, j);
                    // while ((ctoi(j) < 0) || (ctoi(j) > 7)) //|| ((j[1] != ' ') && (j[0] != '7')))
                    // {
                    //     cout << "�������� �������� (������� ����� �� 1 �� " << 7 << ")" << endl;
                    //     getline(cin, j);
                    // }
                    // cout << j << endl
                    //      << "\t" << ctoi(j) << endl;
                    if (j == 0)
                    {
                        cls();
                        break;
                    }

                    if (j == 1)
                    {
                        print("������� ID:");
                        cin >> a.id;
                    }

                    if (j == 2)
                    {
                        print("������� �������� ������:");
                        getline(cin, a.name);
                    }

                    if (j == 3)
                    {
                        print("������� �������� ������:");
                        getline(cin, a.studio);
                    }

                    if (j == 4)
                    {
                        print("������� ���������� ����� �������:");
                        getline(cin, b);

                        a.producers = (e_parse(b));
                    }
                    if (j == 5)
                    {
                        print("������� ���������� ����� �������:");
                        getline(cin, b);
                        a.opers = (e_parse(b));
                    }
                    if (j == 6)
                    {
                        print("������� ����� ����� �������:");
                        getline(cin, b);
                        a.genres = (e_parse(b));
                    }
                    if (j == 7)
                    {
                        print("������� ������� ����� �������:");
                        getline(cin, b);
                        a.actors = (e_parse(b));
                    }

                    // cout << j << endl;
                    // cout << j.substr(2) << endl
                    //      << "\t" << ctoi(j) << endl;

                    // cout << -1;
                    // a.show();
                    cout << endl;
                    a.find();
                    // print("������� ��� �����������:");
                    // cc();
                    // getchar();
                    // cls();
                    //int id, int places, int halls, string name,
                    //string address, string category, bool state
                    // int j;
                    // Film a;
                    // string str;
                    // for (;;)
                    // {
                    //     map<string, string>dict;
                    //     map<string, vector<string>>v_dict;
                    //     dict["2"]=a.name;
                    //     dict["3"]=a.studio;
                    //     v_dict["4"]=a.producers;
                    //     v_dict[]

                    //     cin>>str;
                    //     if (str[0]!='1')
                    //     {
                    //         if
                    //     }else a.id = atoi(str.substr(2).c_str());

                    //     // switch (j)
                    //     // {
                    //     // case 1:
                    //     // {
                    //     //     print("������� ID ��� -1 ��� ������� � ������");
                    //     //     int i;
                    //     //     r_cin(i);
                    //     //     break;
                    //     // }

                    //     default:
                    //         break;
                    //     }
                    //     break;
                    // }
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

                        films.push_back(Film());
                        //films[films.size() - 1].save(); //
                        print("������� ��������");
                        print("������� ��� �����������:");
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
                            cinx(j, "������� ���� ������, ������� �� ������ ������� ��� -1 ��� ������:");
                            if (j == -1)
                                cls();
                                break;

                            for (auto it = films.begin(); it < films.end(); it++)
                            {
                                if ((*it).id == j)
                                {

                                    print("����� ������� �� ������ �������:");
                                    (*it).show();
                                    cout << "��� ������������� �������� ������� " << x << " :";
                                    cinx(j, "");
                                    if (j == x)
                                    {
                                        films.erase(it);
                                        print("�����");
                                        j = -1337;
                                    }
                                    else
                                    {
                                        print("������");
                                        j = -1337;
                                    }
                                    break;
                                }
                            }
                            if (j != -1337)
                            {
                                print("����� �� ��� ������");
                            }
                        }

                        break;
                    }
                    case 3:
                    {
                        int j;
                        int x;
                        cinx(j, "������� ID ������, ������� ����� ��������:");
                        for (size_t i = 0; i < films.size(); i++)
                        {
                            {
                                if (films[i].id == j)
                                {
                                    print("����� ������� �� ������ ��������:");
                                    films[i].show();
                                    for (;;)
                                    {
                                        cinx(x, "�������� �������� ��� ��� ������:", 6, "�������� ������",
                                             "�������� ������", "���������", "���������", "�����", "������");
                                        if (x == 0)
                                            break;
                                        if (x == 1)
                                        {
                                            print("������� ��������:");
                                            films[i].name.clear();
                                            push_line(films[i].name);
                                        }
                                        if (x == 2)
                                        {
                                            print("������� �������� ����������");
                                            films[i].studio.clear();
                                            push_line(films[i].studio);
                                        }
                                        if (x == 3)
                                        {
                                            print("������� ���������� ����� Enter (-1 ��� ����������� �����)");
                                            films[i].producers.clear();
                                            push_vector(films[i].producers);
                                        }
                                        if (x == 4)
                                        {
                                            print("������� ���������� ����� Enter (-1 ��� ����������� �����)");
                                            films[i].opers.clear();
                                            push_vector(films[i].opers);
                                        }
                                        if (x == 5)
                                        {
                                            print("������� ����� ���� Enter (-1 ��� ����������� �����)");
                                            films[i].genres.clear();
                                            push_vector(films[i].genres);
                                        }
                                        if (x == 6)
                                        {
                                            print("������� ������� ���� Enter (-1 ��� ����������� �����)");
                                            films[i].actors.clear();
                                            push_vector(films[i].actors);
                                        }
                                        print("�����");
                                    }
                                    print("���������� �����:");
                                    films[i].show();
                                    cc();
                                    print("������� ��� �����������");
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
            set_all();
            return 0;
        }
    }
}
