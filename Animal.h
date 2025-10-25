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
class Bird : public Animal {
private:
    float wingSpan;

public:
    Bird();
    Bird(string n, int a, bool h, float span);
    ~Bird();

    void setWingSpan(float span);
    float getWingSpan() const;

    void display() const override;
};

// Reptile subclass
class Reptile : public Animal {
private:
    bool isVenomous;

public:
    Reptile();
    Reptile(string n, int a, bool h, bool venom);
    ~Reptile();

    void setIsVenomous(bool venom);
    bool getIsVenomous() const;

    void display() const override;
};

#endif
