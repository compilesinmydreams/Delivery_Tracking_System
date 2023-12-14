
#include "View.h"
#include <sstream>
#include "Driver.h"
#include "Franchise.h"

using namespace std;


void View::displayMenu(int& choice){
    int numOptions = 5;

    cout << endl;
    cout << "What would you like to do?"<< endl;
    cout << "  (1) Print all drivers." << endl;
    cout << "  (2) Print all franchises." << endl;
    cout << "  (3) Take a customer order." << endl;
    cout << "  (4) Have a driver pick up orders from franchise." << endl;
    cout << "  (5) Have a driver deliver orders to customers." << endl;
    cout << endl<<"Tests (from the tutorials, for convenience, to be added later):"<<endl;

    cout << "Enter your selection: ";
    cin >> choice;
    if (choice == 0)
        return;

    while (choice < 0 || choice > numOptions) {
        cout << "Enter your selection: ";
        cin >> choice;
    }
}

void View::getOrderInfo(string& name, int& menuItem, Location& loc){
    cout<<"Enter customer name: ";
    cin >> name;
    cout << endl;
    cout<<"Enter choice: "<<endl;
    Franchise::printMenu();
    cin>>menuItem;
    cout<<endl<<"Enter location (two integers: x y): ";
    cin >> loc.x >> loc.y;
}

void View::driverPickup(string& id, int& num){
    cout<<"Enter franchise id: ";
    cin >> id;
    cout<<endl<<"Enter number of orders to pick up: ";
    cin >> num;
    cout << endl;
}

void View::driverDeliver(string& id, int& num){
    cout<<"Enter driver id: ";
    cin >> id;
    cout<<endl<<"Enter number of orders to deliver: ";
    cin >> num;
    cout << endl;
}



