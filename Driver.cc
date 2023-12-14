#include "Driver.h"

const char Driver::code = 'D';
int Driver::nextId = 1;

Driver::Driver(const string& name, Location driverLocation)
    : Entity(code, nextId, name, driverLocation){
    nextId++;
}

bool Driver::isFree() const{
    return orders->empty();
}

void Driver::print() const{
    cout << "Driver name: " << name<<" ";
    Entity::print();
}

