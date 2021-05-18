#include "funcs.h"
#include "Film.h"
#include "Cinema.h"
#include "Repertoire.h"
#include <stdarg.h>
#include <fstream>
using namespace std;

extern vector<Film> films;
extern vector<Cinema> cinemas;
extern vector<Repertoire> repertoires;

void cc();
void print(string text) { cout << text << endl; } //вывод текста
void r_cin(int &j)
{
    for (;;)
    {
        cin >> j;
        if (cin.fail())
            cc();
        else
            break;
        print("Неверный ввод, попробуйте ввести число:");
    }
}
void to_lower(char *c)
{
    if (*c >= 'A' && *c <= 'Z')
    {
        *c = *c + 'a' - 'A';
    }
    if (*c >= 'А' && *c <= 'Я')
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
void cls() { printf("\e[1;1H\e[2J"); } //очистка консоли
void menu(int i, ...)                  //контекстное меню
{
    va_list t;
    va_start(t, i);
    print("Выберите действие:");
    for (size_t j = 0; j <= i; j++)
        printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "Вернуться (выход)"));
}
void cc() //очистка потока ввода
{
    cin.clear();
    cin.ignore(32767, '\n');
}
void cinx(int &x, string text, int i, ...) //ввод x
{

    print(text);
    va_list t;
    va_start(t, i);
    for (size_t j = 0; j <= i; j++)
        printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "Вернуться (выход)"));
    cin >> x;
    while (cin.fail() || (x < 0 || x > i))
    {
        cc();
        cout << "Неверное значение (введите цифру от 1 до " << i << ")" << endl;
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
        cout << "Неверное значение (введите число)" << endl;
        cin >> x;
    }
}
void cinx(string &x, string text, int i, ...) //ввод x
{

    print(text);
    va_list t;
    va_start(t, i);
    for (size_t j = 0; j <= i; j++)
        printf("[%d] - %s\n", j, (j ? va_arg(t, char *) : "Вернуться (выход)"));
    // getline(cin, x);

    // while ((ctoi(x) < 0) || (ctoi(x) > i) || (x[1] != ' '))
    // {

    //     cout << "Неверное значение (введите цифру от 1 до " << i << " и команду)" << endl;
    //     getline(cin, x);
    // }
    // cc();
    // cls();
}
void push_line(string &str) //ввод не пустых строк
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
void get_films()
{
    films.clear();
    string line;
    ifstream in("data/films.db"); // окрываем файл для чтения
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
    ifstream in("data/repertoires.db"); // окрываем файл для чтения
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
    ifstream in("data/cinemas.db"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cinemas.push_back(Cinema(line));
        }
        in.close();
    }
}
void get_all(/*vector<Cinema> &cinemas, vector<Film> &films, vector<Repertoire> &repertoires*/) //выгрузка данных
{
    get_films();
    get_repertoires();
    get_cinemas();
    print("Данные успешно были загружены");
}
void set_all(/*vector<Cinema> &cinemas, vector<Film> &films, vector<Repertoire> &repertoires*/) //сохранение данных
{
    ofstream out;              // поток для записи
    out.open("data/films.db"); // окрываем файл для записи
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
    out.open("data/repertoires.db"); // окрываем файл для записи
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
    out.open("data/cinemas.db"); // окрываем файл для записи
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
    print("Соединение проозшоло успешно");
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

