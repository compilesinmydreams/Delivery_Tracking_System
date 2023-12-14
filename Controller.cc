
#include "Controller.h"
#include <sstream>

#define ARR 5


void Controller::launch(){
    // add some drivers and franchises
    initPierres();

    //write the menu and get user input
    int choice = -1;

    // This is the code being run in View
    // cout << "What would you like to do?"<< endl;
    // cout << "  (1) Print all drivers." << endl;
    // cout << "  (2) Print all franchises." << endl;
    // cout << "  (3) Take a customer order." << endl;
    // cout << "  (4) Have a driver pick up orders from franchise." << endl;
    // cout << "  (5) Have a driver deliver orders to customers." << endl;
    // cout << endl<<"Tests (from the tutorials, for convenience):"<<endl;
    // TO BE ADDED LATER


    while(choice!=0){
        int temp = 0;
        view.displayMenu(choice);
        switch(choice){
            case 1: pierres.printDrivers(); break;
            case 2: pierres.printFranchises(); break;
            case 3: takeOrder(); break;
            case 4: driverPickup(); break;
            case 5: driverDeliver(); break;
            
        }
    }

    cout<<"Bye!"<<endl;

    
}




void Controller::initPierres(){
    

    pierres.addDriver("Elsa", Location(3,4));
    pierres.addDriver("Densel", Location(1,1));
    pierres.addDriver("Carter", Location(5,4));
    pierres.addDriver("Bob",  Location(2, 2));
    pierres.addDriver("Alice", Location(7, 7));

    pierres.addFranchise("Sally", Location(5, 5));
    pierres.addFranchise("Jesse", Location(3, 7));
    pierres.addFranchise("Isabelle", Location(4, 5));
    pierres.addFranchise("Philip", Location(1, 7));

    // You may uncomment when these functions are working if you wish
    pierres.takeOrder("alice", 1, Location(7,4));
    pierres.takeOrder("bob", 2, Location(4,1));
    pierres.takeOrder("charlie", 0, Location(6,6));

    pierres.driverPickup("F1", 2);

}

void Controller::takeOrder(){
  string name;
  int menuItem = 0;
  Location loc;

  view.getOrderInfo(name, menuItem, loc);
  pierres.takeOrder(name, menuItem, loc);
    
}

void Controller::driverPickup(){
  string id;
  int numDel = 0;

  view.driverPickup(id, numDel);
  pierres.driverPickup(id, numDel);
}

void Controller::driverDeliver(){
  string id;
  int numDel = 0;

  view.driverDeliver(id, numDel);
  pierres.driverDeliver(id, numDel);
}

