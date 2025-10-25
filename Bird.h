#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

//define class bird here 

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





#endif
