#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>


using namespace std;

int GetNumFromChar(char a){
    return a - 48;
}

struct ShopWorkSchedule{
    string Open;
    string Closed;
public:
    friend ostream & operator<<(ostream & out, const ShopWorkSchedule & item){
        out << item.Open << " - " << item.Closed;
        return out;
    }

    int GetTime(const string & item ) const{
        int time_hours = GetNumFromChar(item[0]) * 10 + GetNumFromChar(item[1]);
        int time_minutes = GetNumFromChar(item[3]) * 10 + GetNumFromChar(item[4]) * 10;
        return time_hours * 60 + time_minutes;
    }

    int GetWorkTime() const{
        return GetTime(Closed) - GetTime(Open);
    }

    bool operator<(const ShopWorkSchedule & second)const {
        return GetWorkTime()  < second.GetWorkTime();
    }

    bool operator!=(const ShopWorkSchedule & second)const{
        return GetWorkTime() != second.GetWorkTime();
    }

    bool operator==(const ShopWorkSchedule & second) const{
        return GetWorkTime() == second.GetWorkTime();
    }

    friend int operator+(int first, const ShopWorkSchedule & item ){
        return item.GetWorkTime() + first;
    }

    int operator+(int second){
        ++second;
        return second;
    }
    bool operator>(const ShopWorkSchedule & second) const {
        return GetWorkTime() > second.GetWorkTime();
    }
};


string GetCorrectTime(int num){
    return to_string(num / 10) + to_string(num % 10);
}

const ShopWorkSchedule RandomWorkSchedule(){
    string opened = GetCorrectTime(rand() % 12) + ':' + GetCorrectTime(rand() % 60);
    int closed_hours = rand()  % 24;
    string closed = GetCorrectTime((closed_hours % 24 > 12)? closed_hours: closed_hours + 12)
            + ':' + GetCorrectTime(rand() % 60);
    return {opened, closed};
}


int main(){
    vector<ShopWorkSchedule> Shops;

    for(int i = 0; i < 5; ++i){
        Shops.push_back(RandomWorkSchedule());
    }

    {
        cout << "Initialize Shops:\n";
        for (const auto item: Shops){
            cout << item << endl;
        }
    }

    cout << endl;

    {
        vector<ShopWorkSchedule> ShopsCopy = Shops;
        cout << "Copy to the ShopsCopy: ";
        for (const auto & item: ShopsCopy){
            cout << item << endl;
        }
    }

    cout << endl;

    {
        less<ShopWorkSchedule> a;
        cout << "less: " <<  Shops[0]<< Shops[2] << endl;
    }

    cout << endl;

    {
        equal_to<ShopWorkSchedule> a;
        cout << "equal_to: " << a(Shops[0], Shops[1]) << endl;
    }
    cout << endl;

    {
        cout  << "count: " << count(Shops.begin(), Shops.end(), RandomWorkSchedule()) << endl;
    }

    cout << endl;

    {
        cout << "for_each: \n";
        for_each(Shops.begin(), Shops.end(), [](const auto & item){
            cout << item << endl;
        });
    }

    cout << endl;

    {
        rotate(Shops.begin(), Shops.begin() + 3,Shops.end());
        cout << "rotate: \n";
        for (const auto & item: Shops){
            cout << item << endl;
        }
    }

    cout << endl;

    {
        reverse(Shops.begin(), Shops.end());
        cout << "reverse: \n";
        for (const auto & item: Shops){
            cout << item << endl;
        }
    }

    cout << endl;

    {
        sort(Shops.begin(), Shops.end());
        cout << "sort: \n";
        for (const auto & item: Shops){
            cout << item<< endl;
        }
    }

    cout << endl;

    {
        auto copy = Shops;
        vector<ShopWorkSchedule> result;
        cout << "binary_search: " << binary_search(Shops.begin(), Shops.end(), Shops[0]) << endl;
        cout << "binary_search: " << binary_search(Shops.begin(), Shops.end(), RandomWorkSchedule()) << endl;
    }

    cout << endl;

    {
        auto copy = Shops;
        cout << "accumulate: " << accumulate(Shops.begin(), Shops.end(), 0) << " minutes";
    }
    cout << endl;

    getchar();
    return 0;
}
