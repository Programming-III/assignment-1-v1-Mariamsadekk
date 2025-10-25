#ifndef REPTILE_H
#define REPTILE_H

#include "Animal.h"

//define reptile class here
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
