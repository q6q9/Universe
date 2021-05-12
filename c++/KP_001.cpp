#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
using namespace std;

class Animal {

    string name;
    string gender;
    int age;

public:

    // Default constructor
    Animal() {
        name = "";
        gender = "";
        age = 0;
    }
    Animal(string n, string g, int a) {
        name = n;
        gender = g;
        age = a;
    }
    string getName() const {
        return name;
    }

    void set(string n, string g, int a) {
        name = n;
        gender = g;
        age = a;
    }

    void const print() {
        cout << "Животное: " << name << endl << "Пол: " << gender << endl << "Возраст: " << age << endl;
    }
};

class Address {
    string city, street;
    int number;
public:
    Address(){}
    Address(string c, string s,int x):city(c),street(s),number(x){}
    string getAdr()const 
    {
        return ("\t{Город - " + city + "\n\t Улица - " + street + "\n\t Номер -" + to_string(number)+"\n\t}");
    }
};

class Aviary {
    int pos;
    int quantity_animals;
    Animal animal;
public:
    Aviary(){}
    Aviary(int p, int q, Animal a):pos(p),quantity_animals(q),animal(a) {}
    // Animal cat

    void print() const 
    {
        cout << "Вальер номер " << pos << "Имеющий " << quantity_animals << "животных вида " << animal.getName();
    }
};

class Zoo {
    string name;
    vector <Aviary> aviarys;
    Address address;
public:
    Zoo(){}
    Zoo(string n, int i, string c, string s, int x=0) :name(n), address(c, s, x) { aviarys.resize(i); }

    void add_aviary(Aviary aviary) {
        aviarys.push_back(aviary);
    }

    void print() const 
    {
        cout << "Зоопарк " << name << endl << "Адрес:" << address.getAdr() << endl << "Количество вальеров: " << aviarys.size() << endl;
    }
    //Address
    //Aviary
};




int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    vector <Animal> animals(3);
    animals[0].set("dog", "male", 3);
    animals[1].set("cat", "male", 1);
    animals[2].set("pig", "female", 5);
    Animal mouse("mouse", "male", 2);
    animals.push_back(mouse);


    for (auto animal : animals) {
        animal.print();
        cout << endl;
    }

    Zoo zoo1("Джуманджи", 7, "Донецк", "улица Ленина");
    zoo1.print();
    Aviary a(1,3,animals[2)
    zoo1.add_aviary()

    return 0;
}