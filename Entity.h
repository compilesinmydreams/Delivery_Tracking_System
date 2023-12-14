#ifndef ENTITY_H
#define ENTITY_H

#include "Location.h"
#include "Queue.h"
#include "Order.h"
#include <string>
using namespace std;
class Entity {
protected:
    string id;
    string name;
    Location location;
    Queue* orders;
public:
    Entity(char type, int id, string name, Location location);
    ~Entity();
    void setLocation(Location location);
    void addOrder(Order* order);
    Order* getNextOrder();
    int getNumOrders() const;
    void print() const;
    bool equals(std::string id) const;
    Location getLocation();
    string getId()const;
    string getName() const;
};

#endif

