
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include "Pierres.h"
#include "View.h"






using namespace std;

class Controller {
		
	public:
		
		void launch();

	
	private:
		void initPierres();
		void takeOrder();
		void driverPickup();
		void driverDeliver();
		// void removeDriver();
		
		// these are tutorial tests, here for your convenience
		// int findRideTest();
		// int customerIdTest();
		// int driverIdTest();
		// int driverMatchTest();
		// const string names[5] = {"Abe","Bae","Cedric","Deb","Elise"};
		// const string numbers[5] = {"000","111","222","333","444"};
		
		Pierres pierres;
		View view;

};
#endif