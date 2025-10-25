#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"

//define mammal class here
class Mammal : public Animal {
private:
    string furColor;

public:
    Mammal();
    Mammal(string n, int a, bool h, string color);
    ~Mammal();

    void setFurColor(string color);
    string getFurColor() const;

    void display() const override;
};





#endif
