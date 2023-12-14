#ifndef PIERRES_H
#define PIERRES_H
#include <iostream>
#include <string>
#include <vector>
#include "Queue.h"
#include "Entity.h"
#include "Driver.h"
#include "Franchise.h"

using namespace std;

class Pierres{
  public:
  
    Pierres();
    ~Pierres();
    void addDriver(const string& name, Location);
    void addFranchise(const string& name, Location);
    void takeOrder(const string& customerName, int menuItem, Location custLocation);
    void driverPickup(const string& franchiseId, int numOrders);
    void driverDeliver(const string& driverId, int numOrders);
    void printFranchises() const;
    void printDrivers() const;
    int findClosestFranchise(Location custLocation);
    
  private:
    vector<Driver*> driverArr;
    vector<Franchise*> franchiseArr;  
};

#endif

