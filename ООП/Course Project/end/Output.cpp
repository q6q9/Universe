#include "Output.h"
#include <iostream>

Output::Output(std::string &a) : out(a) { put(); }
Output::~Output() {}
void Output::put() { std::cout << out << std::endl; }
