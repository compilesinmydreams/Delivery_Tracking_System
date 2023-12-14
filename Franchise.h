#ifndef FRANCHISE_H
#define FRANCHISE_H

#include <iostream>
#include <string>
#include "Entity.h"
#include "defs.h"
using namespace std;

class Franchise:public Entity{

  public:
    Franchise(const string& name, Location franchiseLocation = Location());
    void print() const;
    static void printMenu();
    static string getMenu(int index);
  private:
    static const char code;
    static int nextId;
    static const string menu[MENU_ITEMS];

};

#endif
