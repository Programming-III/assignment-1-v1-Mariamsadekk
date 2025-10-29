#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string name;
    int age;
    bool isHungry;
//edit
public:
    Animal();
    Animal(string n, int a, bool h);
    virtual ~Animal();

    void setName(string n);
    string getName() const;

    void setAge(int a);
    int getAge() const;

    void setIsHungry(bool h);
    bool getIsHungry() const;

    virtual void display() const;
    virtual void feed();
};

// Mammal subclass


// Bird subclass


// Reptile subclass


#endif
