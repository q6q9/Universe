#include <iostream>
#include <vector>

using namespace std;


int main(){
        vector<string> a;
        a.push_back("hi");
        a.push_back("world");
         string str(a.begin(),a.end());
         cout<< str;
        getchar();
}