#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include "Entity.h"
using namespace std;

class Driver: public Entity{
public:
    Driver(const string& name = "Charles Leclerc", Location driverLocation = Location());
    bool isFree() const;
    void print() const;
private:
    static const char code;
    static int nextId;
};

#endif

