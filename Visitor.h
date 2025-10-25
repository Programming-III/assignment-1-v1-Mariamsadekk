#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>
#include <string>
using namespace std;

class Visitor {
private:
    string visitorName;
    int ticketsBought;

public:
    Visitor();
    Visitor(string name, int tickets);
    ~Visitor();

    void setVisitorName(string name);
    string getVisitorName() const;

    void setTicketsBought(int t);
    int getTicketsBought() const;

    void displayInfo() const;
};

#endif
