
#include "functions.h"
#include "Film.h"

vector<Film> films;
vector<Cinema> cinemas;
vector<Repertoire> repertoires;

int main()
{
    std::mt19937 engine; // mt19937 как один из вариантов
    engine.seed(std::time(nullptr));
    system("chcp 1251");
    cls();

    //cout << low("Привет мир");
    //e_parse(" Антонио Ваден,Вильдоний Гласен,Чиндер Смыр ");
    int x, y;

    get_all();

    // for (Film &x : films)
    // {
    //     x.show();
    // }
    for (;;)
    {
        print("Для СОХРАНЕНИЯ ИЗМЕНЕНИЙ выходите из программы с помощью меню!");
        cinx(y, "Выберите область, с которой вы будете работать:", 3, "Кинотеатры", "Фильмы", "Репертуары");

        switch (y)
        {
        case 1:
        {
            for (;;)
            {

                print("Нажата 1");
                cinx(x, "Выберите действие:", 4, "Отобразить текущие кинотеатры", "Отобразить сведения кинотеатра по ключу",
                     "Поиск кинотеатров", "Редактирование кинотеатров");
                switch (x)
                {
                case 1:
                {
                    print("Список текущих кинотетров:");
                    for (Cinema const &a : cinemas)
                        cout << "ID : " << a.id << "| Название : " << a.name << endl;
                    print("Введите для продолжения");
                    getchar();
                    break;
                }
                case 2:
                {
                    print("Введите ключ нужного вам кинотеатра или -1 для выхода");

                    break;
                    //case 4:
                    // print("Нажата 4");
                    // cinx(x, "Выберите действие:", 3, "Добавить фильм", "Удалить фильм", "Изменить фильм");
                }
                case 3:
                { //int id, int places, int halls, string name,
                    //string address, string category, bool state
                    cinx(x, "Установите нужные вам значения некоторым свойствам:", 7, "ID",
                         "Название кинотеатра", "Кол-во залов", "Кол-во мест", "Адрес", "Категория", "Состояние");
                    break;
                }

                case 4:
                {
                    print("Нажата 4");
                    cinx(x, "Выберите действие:", 3, "Добавить кинотеатр", "Удалить кинотеатр", "Изменить кинотеатр");

                    switch (x)
                    {
                    case 1:
                    {
                        print("1) добавить фильм");
                        Film a;
                        a.input();
                        a.save();
                        print("добавлен");
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
                cinx(x, "Выберите действие:", 4, "Отобразить текущие фильмы", "Отобразить сведения фильма по ключу",
                     "Поиск фильма", "Редактирование фильмов");
                switch (x)
                {
                case 1:
                {
                    print("Список текущих фильмов:");
                    for (Film &a : films)
                        a.show();
                    //cout << "ID : " << a.id << ". Название : " << a.name << ". Жанр : " << unvector(a.genres) << "." << endl;
                    print("Введите для продолжения");
                    getchar();
                    cls();
                    break;
                }
                case 2:
                {
                    int j;
                    print("Введите ключ нужного вам фильма или -1 для выхода");
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
                            print("Введите для продолжения:");
                            cc();
                            getchar();
                            cls();
                            j = -1;
                        }
                    }

                    if (j != -1)
                    {
                        print("Фильма с данным ключом не существует");
                        print("Введите для продолжения:");
                        cc();
                        getchar();
                        cls();
                    }
                    break;
                    //case 4:
                    // print("Нажата 4");
                    // cinx(x, "Выберите действие:", 3, "Добавить фильм", "Удалить фильм", "Изменить фильм");
                }
                case 3:
                {
                    int j;
                    string b;
                    Film a(0);

                    cinx(j, "Выберите свойство, которое вы введете, и по которому будет происходить поиск:",
                         7, "ID",
                         "Название фильма", "Название студии", "Продюсеры", "Операторы", "Жанры", "Актеры");

                    // getline(cin, j);
                    // while ((ctoi(j) < 0) || (ctoi(j) > 7)) //|| ((j[1] != ' ') && (j[0] != '7')))
                    // {
                    //     cout << "Неверное значение (введите цифру от 1 до " << 7 << ")" << endl;
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
                        print("Введите ID:");
                        cin >> a.id;
                    }

                    if (j == 2)
                    {
                        print("Введите Название фильма:");
                        getline(cin, a.name);
                    }

                    if (j == 3)
                    {
                        print("Введите Название студии:");
                        getline(cin, a.studio);
                    }

                    if (j == 4)
                    {
                        print("Введите продюсеров через запятую:");
                        getline(cin, b);

                        a.producers = (e_parse(b));
                    }
                    if (j == 5)
                    {
                        print("Введите операторов через запятую:");
                        getline(cin, b);
                        a.opers = (e_parse(b));
                    }
                    if (j == 6)
                    {
                        print("Введите жанры через запятую:");
                        getline(cin, b);
                        a.genres = (e_parse(b));
                    }
                    if (j == 7)
                    {
                        print("Введите актеров через запятую:");
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
                    // print("Введите для продолжения:");
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
                    //     //     print("Введите ID или -1 для очистки и выхода");
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
                    print("Нажата 4");
                    cinx(x, "Выберите действие:", 3, "Добавить фильм", "Удалить фильм", "Изменить фильм");

                    switch (x)
                    {
                    case 1:
                    {

                        films.push_back(Film());
                        //films[films.size() - 1].save(); //
                        print("Успешно добавлен");
                        print("Введите для продолжения:");
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
                            cinx(j, "Введите ключ фильма, который вы хотите удалить или -1 для выхода:");
                            if (j == -1)
                                cls();
                                break;

                            for (auto it = films.begin(); it < films.end(); it++)
                            {
                                if ((*it).id == j)
                                {

                                    print("Фильм который вы хотите удалить:");
                                    (*it).show();
                                    cout << "Для подтверждения удаления введите " << x << " :";
                                    cinx(j, "");
                                    if (j == x)
                                    {
                                        films.erase(it);
                                        print("Успех");
                                        j = -1337;
                                    }
                                    else
                                    {
                                        print("Отмена");
                                        j = -1337;
                                    }
                                    break;
                                }
                            }
                            if (j != -1337)
                            {
                                print("Фильм не был найден");
                            }
                        }

                        break;
                    }
                    case 3:
                    {
                        int j;
                        int x;
                        cinx(j, "Введите ID фильма, который нужно изменить:");
                        for (size_t i = 0; i < films.size(); i++)
                        {
                            {
                                if (films[i].id == j)
                                {
                                    print("Фильм который вы хотите изменить:");
                                    films[i].show();
                                    for (;;)
                                    {
                                        cinx(x, "Выберите свойства для его замены:", 6, "Название фильма",
                                             "Название студии", "Продюсеры", "Операторы", "Жанры", "Актеры");
                                        if (x == 0)
                                            break;
                                        if (x == 1)
                                        {
                                            print("Введите название:");
                                            films[i].name.clear();
                                            push_line(films[i].name);
                                        }
                                        if (x == 2)
                                        {
                                            print("Введите название киностудии");
                                            films[i].studio.clear();
                                            push_line(films[i].studio);
                                        }
                                        if (x == 3)
                                        {
                                            print("Введите продюсеров через Enter (-1 для прекращения ввода)");
                                            films[i].producers.clear();
                                            push_vector(films[i].producers);
                                        }
                                        if (x == 4)
                                        {
                                            print("Введите операторов через Enter (-1 для прекращения ввода)");
                                            films[i].opers.clear();
                                            push_vector(films[i].opers);
                                        }
                                        if (x == 5)
                                        {
                                            print("Введите жанры ерез Enter (-1 для прекращения ввода)");
                                            films[i].genres.clear();
                                            push_vector(films[i].genres);
                                        }
                                        if (x == 6)
                                        {
                                            print("Введите актеров ерез Enter (-1 для прекращения ввода)");
                                            films[i].actors.clear();
                                            push_vector(films[i].actors);
                                        }
                                        print("Успех");
                                    }
                                    print("Измененный фильм:");
                                    films[i].show();
                                    cc();
                                    print("Введите для продолжения");
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

                print("Нажата 3");
                cinx(x, "Выберите действие:", 4, "Отобразить текущие репертуары", "Отобразить сведения репертуара по ключу",
                     "Поиск репертуаров", "Редактирование репертуаров");
                switch (x)
                {
                case 1:
                {
                    print("Список текущих репертуаров:");
                    for (Cinema const &a : cinemas)
                        cout << "ID : " << a.id << "| Название : " << a.name << endl;
                    print("Введите для продолжения");
                    getchar();
                    break;
                }
                case 2:
                {
                    print("Введите ключ нужного вам репертуара или -1 для выхода");

                    break;
                    //case 4:
                    // print("Нажата 4");
                    // cinx(x, "Выберите действие:", 3, "Добавить фильм", "Удалить фильм", "Изменить фильм");
                }
                case 3:
                { //int id, int places, int halls, string name,
                    //string address, string category, bool state
                    cinx(x, "Установите нужные вам значения некоторым свойствам:", 5, "ID",
                         "Фильм", "Дата", "Цена", "Свободные места");
                    break;
                }

                case 4:
                {
                    print("Нажата 4");
                    cinx(x, "Выберите действие:", 3, "Добавить репертуар", "Удалить репертуар", "Изменить репертуар");

                    switch (x)
                    {
                    case 1:
                    {
                        print("1) добавить репертуар");

                        print("добавлен");
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
