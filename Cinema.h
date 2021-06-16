#pragma once
#ifndef Cinema_h
#define Cinema_h
#include "funcs.h"
#include<iostream>
#include<regex>
using namespace std;
class Cinema
{
public:
    int id, places, halls;
    string name, address, category;
    bool state;
    vector<Repertoire *> reps;
    Cinema(Cinema const &a);
    Cinema(int a);
    Cinema();
    Cinema(string str);
    Cinema(int id, int places, int halls, string name,
           string address, string category, bool state, vector<Repertoire *> reps);
    ~Cinema();
    void set_id();
    void input();
    void find();
    void show();
    void save();
    bool operator<(const Cinema &a) const;
};
#endif