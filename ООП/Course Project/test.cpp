#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;
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
                        word += str[i];
                        i++;
                }
                j = 0;
                if (word[j] == ' ')
                        for (j = 0; j < word.size(); j++)
                        {
                                if (word[j] != ' ')
                                {
                                        j += word.size();
                                }
                        };

                word = word.substr(j - word.size() - 1);
                for (j = 0; j < word.size(); j++)
                {
                        if (word[j] == ' ')
                        {
                                break;
                        }
                };
                for (y = j; y < word.size(); y++)
                {
                        if (word[y] != ' ')
                        {
                                break;
                        }
                };
                word = word.substr(0, j + 1) + word.substr(y);

                reverseStr(word);
                j = 0;
                        for (j = 0; j < word.size(); j++)
                        {
                                if (word[j] != ' ')
                                {
                                        j += word.size();
                                }
                        }
                word = word.substr(j - word.size() - 1);
                reverseStr(word);
                a.push_back(word);
                i++;
        }
        return a;
}

int main()
{
        system("chcp 1251");
        vector<int> a;
        e_parse(" Антонио Ваден,  Вильдоний  Гласен,  Чиндер  Смыр ");
        getchar();
}