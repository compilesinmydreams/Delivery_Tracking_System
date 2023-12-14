
#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <sstream>
#include "defs.h"
#include "Location.h"

using namespace std;

class View {
		
  public:	
	void displayMenu(int& choice);
	void getOrderInfo(string& name, int& menuItem, Location& loc);
	void driverPickup(string& id, int& num);
	void driverDeliver(string& id, int& num);
};
#endif
