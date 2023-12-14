#ifndef ORDER_H
#define ORDER_H

#include "Location.h"
#include <string>

using namespace std;

class Order {
public:
    Order(string customerName, int menuItem, Location deliveryLocation);
    Location getLocation() const;
    void print() const;
private:
    string customerName;
    int menuItem;
    Location deliveryLocation;


};

#endif
