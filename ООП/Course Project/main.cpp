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



#define d(a) a[0] << a[1] << "." << a[2] << a[3] << "." << a.substr(4, 4)
#define rand(x) engine() % x
#define ctoi(j) atoi(string({j[0]}).c_str())
using namespace std;
class Output;
class Cinema;
class Film;
class Repertoire;

class Output{
    public:
    string out;
    Output(string &str);
    void out();
    ~Output();
};

vector<Film> films;
vector<Cinema> cinemas;
vector<Repertoire> repertoires;
void cc();
void print(string text) { cout << text << endl; } //����� ������
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
void cls() { printf("\e[1;1H\e[2J"); } //������� �������
void menu(int i, ...)                  //����������� ����
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
    // int i == 0;
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
    if (a.size() == 7)
        a.push_back("0");
    return a;
}
vector<string> parsing(regex &reg, string &str)
{
    string s;
    vector<string> a;
    sregex_iterator currentMatch(str.begin(), str.end(), reg);
    sregex_iterator lastMatch;
    while (currentMatch != lastMatch)
    {
        smatch match = *currentMatch;
        a.push_back(match.str());
        currentMatch++;
    }
    return a;
}

class Cinema
{

public:
    int id, places, halls;
    string name, address, category;
    bool state;
    vector<Repertoire *> reps;
    Cinema(Cinema const &a) : Cinema(a.id, a.places, a.halls, a.name, a.address, a.category, a.state, a.reps) {}
    Cinema(int a) {}
    Cinema() { input(); }
    Cinema(string str);
    Cinema(int id, int places, int halls, string name,
           string address, string category, bool state, vector<Repertoire *> reps);

    ~Cinema();

    void set_id()
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
    void input();

    void find()
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

    void show();

    void save();

    bool operator<(const Cinema &a) const
    {
        if ((this->id == a.id) && (this->name == a.name) && (this->halls == a.halls) &&
            (this->places == a.places) && (this->state == a.state) &&
            (this->address == a.address) && (this->category == a.category) && (this->reps == a.reps))
            return false;
        return true;
    }
};

Cinema::~Cinema()
{
}

class Film
{
private:
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
    void set_id()
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

    void find()
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
        if (_films.empty())
        {
            print("������ �� �������");
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

    bool operator<(const Film &a) const
    {
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
}

Film::~Film()
{
}

class Repertoire
{
private:
public:
    int id, price, free_places;
    string date; //01.07.2021
    Film *film;
    Repertoire(int id, int price, int free_places,
               string date, Film *film);
    Repertoire(Repertoire const &a) : Repertoire(a.id, a.price, a.free_places, a.date, a.film) {}
    Repertoire(int a) {}
    Repertoire() { input(); }
    Repertoire(string str)
    {
        regex reg("\\w+");
        vector<string> a;
        a = parsing(reg, str);
        int d = stoi(a[1]);
        *this = Repertoire(stoi(a[0]), stoi(a[2]), stoi(a[3]), a[4], film->search(d));
    }

    Repertoire *search(int &j)
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

    void set_id()
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
    void input()
    {
        int i;
        set_id();
        print("������� ���� � ������� ������ (��������, 30052021):");
        push_line(date);
        print("������� ID ������");
        r_cin(i);
        film = film->search(i);
        print("������� ���� ������");
        r_cin(price);
        print("������� ���-�� ��������� ����");
        r_cin(free_places);

        print("�����");
        cc;
        print("������� ��� �����������:");

        getchar();
        cls();
    }

    void find()
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
        _reps.clear();
        print("������� ��� �����������:");

        getchar();
        cls();
    }
    void save()
    {
        ofstream out("data/repertoires.db", ios::app);
        if (out.is_open())
        {
            out << id << " " << film->id << " " << price << " "
                << free_places << " " << date << " ";
        }
        out.close();
        print("��������� ��������");
    }

    void show()
    {
        cout << "ID : " << id << ". ���� : " << d(date) << ". ���� : " << price
             << ".\n ���-�� ��������� ����: : " << free_places << ". ����� : " << endl;

        for (Film &a : films)
        {
            if (film == &a)
            {
                film->show();
                return;
            }
        }
        print("������ � ����� ID �� ����������");
    }

    bool
    operator<(const Repertoire &a) const
    {
        if ((this->id == a.id) && (this->date == a.date) && (this->film == a.film) &&
            (this->free_places == a.free_places) && (this->price == a.price))
            return false;
        return true;
    }

    ~Repertoire();
};

Repertoire::Repertoire(int id, int price, int free_places,
                       string date, Film *film) : id(id), price(price),
                                                  free_places(free_places), date(date), film(film)
{
}
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
        } //ERRRR
    }
    *this = Cinema(stoi(a[0]), stoi(a[2]), stoi(a[3]), a[1], a[4], a[5], (a[6] == "1"), c);
}
Repertoire::~Repertoire()
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
            films.push_back(Film(line));
        }
        in.close();
    }
}
void get_repertoires()
{
    repertoires.clear();
    string line;
    ifstream in("data/repertoires.db"); // �������� ���� ��� ������
    if (in.is_open())
    {
        while (getline(in, line))
        {
            repertoires.push_back(Repertoire(line));
        }
        in.close();
    }
}
void get_cinemas()
{
    cinemas.clear();
    string line;
    ifstream in("data/cinemas.db"); // �������� ���� ��� ������
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cinemas.push_back(Cinema(line));
        }
        in.close();
    }
}
void get_all(/*vector<Cinema> &cinemas, vector<Film> &films, vector<Repertoire> &repertoires*/) //�������� ������
{
    get_films();
    get_repertoires();
    get_cinemas();
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
    out.open("data/repertoires.db"); // �������� ���� ��� ������
    out.close();
    out.open("data/repertoires.db");

    if (out.is_open())
    {
        for (Repertoire &a : repertoires)
        {
            a.save();
        }
        out.close();
    }
    out.open("data/cinemas.db"); // �������� ���� ��� ������
    out.close();
    out.open("data/cinemas.db");

    if (out.is_open())
    {
        for (Cinema &a : cinemas)
        {
            a.save();
        }
        out.close();
    }
    print("���������� ��������� �������");
}
void Cinema::show()
{
    bool flag;
    //<id><places><halls><name><address><category><state><reps[0] reps[n] >
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
Cinema::Cinema(int id, int places, int halls, string name,
               string address, string category, bool state, vector<Repertoire *> reps) : id(id), places(places), halls(halls), name(name),
                                                                                         address(address), category(category), state(state), reps(reps)
{
}

void push_vector(vector<Repertoire *> &a)
{

    int x;
    for (;;)
    {
        r_cin(x);
        Repertoire z(0);
        // Repertoire *ptr;
        if (x != -1)
        {
            if (z.search(x) != NULL)
                a.push_back(z.search(x));
        }
        else
            return;
    }
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
                    for (Cinema &a : cinemas)
                        a.show();
                    print("������� ��� �����������");
                    getchar();
                    cls();
                    break;
                }
                case 2:
                {
                    int j;
                    print("������� ���� ������� ��� ���������� ��� -1 ��� ������");
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
                            print("������� ��� �����������:");
                            cc();
                            getchar();
                            cls();
                            j = -1;
                        }
                    }

                    if (j != -1)
                    {
                        print("���������� � ������ ������ �� ����������");
                        print("������� ��� �����������:");
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

                    cinx(j, "�������� ��������, ������� �� �������, � �� �������� ����� ����������� �����:",
                         8, "ID", "�������� ����������", "���-�� �����", "���-�� ����", "�����",
                         "���������", "���������", "ID �����������");
                    if (j == 0)
                    {
                        cls();
                        break;
                    }

                    if (j == 1)
                    {
                        print("������� ID:");
                        r_cin(a.id);
                    }

                    if (j == 2)
                    {

                        print("������� �������� ����������:");

                        push_line(a.name);
                    }

                    if (j == 3)
                    {
                        print("������� ���-�� �����:");
                        r_cin(a.halls);
                    }

                    if (j == 4)
                    {
                        print("������� ���-�� ����");
                        r_cin(a.places);
                    }
                    if (j == 5)
                    {
                        print("������� �����:");
                        push_line(a.address);
                    }
                    if (j == 6)
                    {
                        print("������� ���������:");
                        push_line(a.category);
                    }
                    if (j == 7)
                    {
                        print("������� ���������:");
                        r_cin(i);
                        a.state = (i == 1);
                    }
                    if (j == 8)
                    {
                        print("������� ID ����������� ����� Enter ��� -1 ��� ������:");
                        push_vector(a.reps);
                    }
                    cout << endl;
                    a.find();

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
                        cinemas.push_back(Cinema());
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
                            {
                                cls();
                                break;
                            }

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
                }
                case 3:
                {
                    int j;
                    string b;
                    Film a(0);

                    cinx(j, "�������� ��������, ������� �� �������, � �� �������� ����� ����������� �����:",
                         7, "ID",
                         "�������� ������", "�������� ������", "���������", "���������", "�����", "������");
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
                    cout << endl;
                    a.find();

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
                cinx(x, "�������� ��������:", 4, "���������� ������� ����������", "���������� �������� ���������� �� �����",
                     "����� ����������", "�������������� �����������");
                switch (x)
                {
                case 1:
                {
                    print("������ ������� �����������:");
                    for (Repertoire &a : repertoires)
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
                    print("������� ���� ������� ��� ���������� ��� -1 ��� ������");
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
                            print("������� ��� �����������:");
                            cc();
                            getchar();
                            cls();
                            j = -1;
                        }
                    }

                    if (j != -1)
                    {
                        print("���������� � ������ ������ �� ����������");
                        print("������� ��� �����������:");
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

                    cinx(j, "�������� ��������, ������� �� �������, � �� �������� ����� ����������� �����:",
                         5, "ID",
                         "ID ������", "����", "����", "��������� �����");
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

                        print("������� ID ������ ����� Enter ��� -1:");
                        while (i != -1)
                        {
                            r_cin(i);
                            a.film = a.film->search(i);
                        }
                    }

                    if (j == 3)
                    {
                        print("������� ���� � ������� ������ (��������, 30052021):");
                        getline(cin, a.date);
                    }

                    if (j == 4)
                    {
                        print("������� ����");
                        r_cin(i);

                        a.price = i;
                    }
                    if (j == 5)
                    {
                        print("������� ���������� ��������� ����:");
                        r_cin(i);

                        a.free_places = i;
                    }
                    cout << endl;
                    a.find();

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

                        repertoires.push_back(Repertoire());
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
                            cinx(j, "������� ���� ����������, ������� �� ������ ������� ��� -1 ��� ������:");
                            if (j == -1)
                            {
                                cls();
                                break;
                            }

                            for (auto it = repertoires.begin(); it < repertoires.end(); it++)
                            {
                                if ((*it).id == j)
                                {

                                    print("��������� ������� �� ������ �������:");
                                    (*it).show();
                                    cout << "��� ������������� �������� ������� " << x << " :";
                                    cinx(j, "");
                                    if (j == x)
                                    {
                                        repertoires.erase(it);
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
                                print("��������� �� ��� ������");
                            }
                        }

                        break;
                    }
                    case 3:
                    {
                        int j;
                        int x;
                        cinx(j, "������� ID ����������, ������� ����� ��������:");
                        for (size_t i = 0; i < repertoires.size(); i++)
                        {
                            {
                                if (repertoires[i].id == j)
                                {
                                    print("��������� ������� �� ������ ��������:");
                                    repertoires[i].show();
                                    for (;;)
                                    {
                                        cinx(x, "�������� �������� ��� ��� ������:", 4, "����",
                                             "ID ������", "����", "���-�� ��������� ����");
                                        if (x == 0)
                                            break;
                                        if (x == 1)
                                        {
                                            print("������� ���� � ������� ������ (��������, 30052021):");
                                            repertoires[i].date.clear();
                                            push_line(repertoires[i].date);
                                        }
                                        if (x == 2)
                                        {
                                            print("������� ID ������");
                                            r_cin(j);
                                            repertoires[i].film = repertoires[i].film->search(j);
                                        }
                                        if (x == 3)
                                        {
                                            print("������� ����");
                                            r_cin(repertoires[i].price);
                                        }
                                        if (x == 4)
                                        {
                                            print("������� ���-�� ��������� ����");
                                            r_cin(repertoires[i].free_places);
                                        }

                                        print("�����");
                                    }
                                    print("���������� ���������:");
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
        default:
            set_all();
            return 0;
        }
    }
}
