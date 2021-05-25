#pragma once
#ifndef funcs_h
#define funcs_h
#include <iostream>
#include "Repertoire.h"
#include <regex>
#include <string>
using namespace std;
void cc();
void print(string text);
void r_cin(int &j);
void to_lower(char *c);
string low(string s);
vector<string> low(vector<string> x);
void reverseStr(string &str);
vector<string> e_parse(string str);
void get_films(vector<Film> &films);
void get_all();
string unvector(const vector<string> &a);
void cls();
void menu(int i, ...);
void cc();
void cinx(int &x, string text, int i, ...);
void cinx(int &x, string text);
void cinx(string &x, string text, int i, ...);
void push_line(string &str);
string str(vector<string> &b);
string str(string &b);
void push_vector(vector<string> &a);
vector<string> parsing(string &str, regex &reg);
vector<string> parsing(regex &reg, string &str);
void get_films();
void get_repertoires();
void get_cinemas();
void get_all();
void set_all();
void push_vector(vector<Repertoire *> &a);
#endif