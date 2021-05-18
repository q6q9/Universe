#pragma once
#ifndef Film_h
#define Film_h
#include <iostream>
#include <vector>
using namespace std;
class Film
{
public:
    int id;
    string name, studio;
    vector<string> producers;
    vector<string> opers;
    vector<string> genres;
    vector<string> actors;
    Film(string str);
    Film();
    Film(int a);
    Film(Film const &a);
    Film(int id, string name, string studio,
         vector<string> producers, vector<string> opers,
         vector<string> genres, vector<string> actors);
    ~Film();

    Film *search(int &j);
    void set_id();
    void input();
    void find();
    void show();
    void save();
    bool operator<(const Film &a) const;
};

#endif