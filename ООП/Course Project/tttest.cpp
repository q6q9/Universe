#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#define low(s) std::transform(s.begin(), s.end(), s.begin(), tolower)
int main() {
    std::string s = "IaFFSjndsUFfE";
  std::cout <<  ( std::transform(s.begin(), s.end(), s.begin(), tolower)==low("iaFFSjndsUFfE"));
    
    std::getchar();
}