#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <random>
#define low(s) std::transform(s.begin(), s.end(), s.begin(), tolower)


int main() {
  std::mt19937 engine; // mt19937 ��� ���� �� ���������
engine.seed(std::time(nullptr));

int val = engine(); // ��� �������� ������
std::cout<<engine()%100;
std::getchar();
}