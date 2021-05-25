#pragma once
#ifndef Output_h
#define Output_h
#include <iostream>
class Output
{
public:
    std::string out;
    Output(std::string const a);
    Output();
    ~Output();
    void put(std::string a);
    void print();
};
#endif