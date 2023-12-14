#include "Order.h"
#include <iostream>

using namespace std;

Order::Order(string customerName, int menuItem, Location deliveryLocation)
    : customerName(customerName), menuItem(menuItem), deliveryLocation(deliveryLocation) {
}

Location Order::getLocation() const {
    return deliveryLocation;
}

void Order::print() const {
    cout << "Customer: " << customerName << ", Order: " << menuItem;
}

