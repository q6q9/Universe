#pragma once
#ifndef Repertoire_h
#define Repertoire_h
#include <iostream>
#include <vector>
#include "Film.h"
using namespace std;


class Repertoire
{
public:
    int id, price, free_places;
    string date;
    Film *film;
    Repertoire(int id, int price, int free_places,
               string date, Film *film);
    Repertoire(Repertoire const &a);
    Repertoire(int a);
    Repertoire();
    Repertoire(string str);
    ~Repertoire();
    Repertoire *search(int &j);
    void set_id();
    void input();
    void find();
    void save();
    void show(string tab="");
    bool    operator<(const Repertoire &a) const;
};
#endif