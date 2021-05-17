
#include "functions.h"
#include "Film.h"

vector<Film> films;
vector<Cinema> cinemas;
vector<Repertoire> repertoires;

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
