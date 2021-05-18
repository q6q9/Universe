#include "Output.h"
#include <iostream>

Output::Output(std::string a) : out(a) { print(); }
Output::Output() {}
Output::~Output() {}
void Output::put(std::string a) { std::cout << a << std::endl; }
void Output::print() { std::cout << out<<std::endl; }
