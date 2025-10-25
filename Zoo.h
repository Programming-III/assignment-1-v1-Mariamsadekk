#ifndef ZOO_H
#define ZOO_H

#include "Enclosure.h"
#include "Visitor.h"

class Zoo {
private:
    Enclosure* enclosure;
    Visitor* visitor;

public:
    Zoo();
    ~Zoo();

    void initializeZoo();
    void showZooStatus() const;
};

#endif
