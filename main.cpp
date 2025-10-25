#include "Animal.h"
#include "Bird.h"
#include "Mammal.h"
#include "Reptile.h"
#include "Enclosure.h"
#include "Visitor.h"
#include "Zoo.h"

using namespace std;

// ------------------ Animal Implementations ------------------

Animal::Animal() : name("Unknown"), age(0), isHungry(true) {}
Animal::Animal(string n, int a, bool h) : name(n), age(a), isHungry(h) {}
Animal::~Animal() {}

void Animal::setName(string n) { name = n; }
string Animal::getName() const { return name; }

void Animal::setAge(int a) { age = a; }
int Animal::getAge() const { return age; }

void Animal::setIsHungry(bool h) { isHungry = h; }
bool Animal::getIsHungry() const { return isHungry; }

void Animal::display() const {
    cout << "- " << name << " (Age: " << age << ", "
         << (isHungry ? "Hungry" : "Not Hungry") << ")" << endl;
}

void Animal::feed() { isHungry = false; }

// Mammal
Mammal::Mammal() : Animal(), furColor("Unknown") {}
Mammal::Mammal(string n, int a, bool h, string color)
    : Animal(n, a, h), furColor(color) {}
Mammal::~Mammal() {}

void Mammal::setFurColor(string color) { furColor = color; }
string Mammal::getFurColor() const { return furColor; }

void Mammal::display() const {
    cout << "- " << getName() << " (Age: " << getAge()
         << ", Fur Color: " << furColor << ", "
         << (getIsHungry() ? "Hungry" : "Not Hungry") << ")" << endl;
}

// Bird
Bird::Bird() : Animal(), wingSpan(0.0f) {}
Bird::Bird(string n, int a, bool h, float span)
    : Animal(n, a, h), wingSpan(span) {}
Bird::~Bird() {}

void Bird::setWingSpan(float span) { wingSpan = span; }
float Bird::getWingSpan() const { return wingSpan; }

void Bird::display() const {
    cout << "- " << getName() << " (Age: " << getAge()
         << ", Wing Span: " << wingSpan << "m, "
         << (getIsHungry() ? "Hungry" : "Not Hungry") << ")" << endl;
}

// Reptile
Reptile::Reptile() : Animal(), isVenomous(false) {}
Reptile::Reptile(string n, int a, bool h, bool venom)
    : Animal(n, a, h), isVenomous(venom) {}
Reptile::~Reptile() {}

void Reptile::setIsVenomous(bool venom) { isVenomous = venom; }
bool Reptile::getIsVenomous() const { return isVenomous; }

void Reptile::display() const {
    cout << "- " << getName() << " (Age: " << getAge()
         << ", " << (isVenomous ? "Venomous" : "Non-Venomous")
         << ", " << (getIsHungry() ? "Hungry" : "Not Hungry") << ")" << endl;
}

// ------------------ Enclosure ------------------

Enclosure::Enclosure(int cap) : capacity(cap), currentCount(0) {
    animals = new Animal*[capacity];
}
Enclosure::~Enclosure() {
    for (int i = 0; i < currentCount; i++)
        delete animals[i];
    delete[] animals;
}

bool Enclosure::addAnimal(Animal* a) {
    if (currentCount < capacity) {
        animals[currentCount++] = a;
        return true;
    }
    return false;
}
//display all animals
void Enclosure::displayAnimals() const {
    cout << "Enclosure Animals:" << endl;
    for (int i = 0; i < currentCount; i++) {
        animals[i]->display();
    }
}

// ------------------ Visitor ------------------

Visitor::Visitor() : visitorName("Unknown"), ticketsBought(0) {}
Visitor::Visitor(string name, int tickets) : visitorName(name), ticketsBought(tickets) {}
Visitor::~Visitor() {}

void Visitor::setVisitorName(string name) { visitorName = name; }
string Visitor::getVisitorName() const { return visitorName; }

void Visitor::setTicketsBought(int t) { ticketsBought = t; }
int Visitor::getTicketsBought() const { return ticketsBought; }

void Visitor::displayInfo() const {
    cout << "Visitor Info:" << endl;
    cout << "Name: " << visitorName << endl;
    cout << "Tickets Bought: " << ticketsBought << endl;
}

// ------------------ Zoo ------------------

Zoo::Zoo() {
    enclosure = nullptr;
    visitor = nullptr;
}

Zoo::~Zoo() {
    delete enclosure;
    delete visitor;
}

void Zoo::initializeZoo() {
    enclosure = new Enclosure(5);
    enclosure->addAnimal(new Mammal("Lion", 5, true, "Golden"));
    enclosure->addAnimal(new Bird("Parrot", 2, false, 0.25f));
    enclosure->addAnimal(new Reptile("Snake", 3, true, true));

    visitor = new Visitor("Sarah Ali", 3);
    cout << "Zoo initialized successfully.\n" << endl;
}

void Zoo::showZooStatus() const {
    enclosure->displayAnimals();
    cout << endl;
    visitor->displayInfo();
}

// ------------------ Main ------------------

int main() {
    Zoo myZoo;
    myZoo.initializeZoo();
    myZoo.showZooStatus();
    return 0;
}
