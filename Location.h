#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>

using namespace std;

class Location {
    public:
        Location(int x=0, int y=0);
        void setLocation(int x, int y);
        int getX(){return x;}
        int getY(){return y;}
        int getDistance(const Location& l);
        void print() const;
        int x, y;
    private:
        string street(int) const;
        
};

#endif