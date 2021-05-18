#pragma once
#ifndef Output_h
#define Output_h
#include <iostream>
class Output
{
public:
    std::string out;
    Output(std::string &a);
    ~Output();
    void put();
};
#endif