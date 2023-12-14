
#include "Location.h"

Location::Location(int x, int y){
    this->x = x;
    this->y = y;
}

void Location::setLocation(int x, int y){
    this->x = x;
    this->y = y;
}

int Location::getDistance(const Location& l){
    return abs(l.x-x)+abs(l.y-y);
}


void Location::print() const{  
    cout<<street(x)<<" and "<<street(y);
}

string Location::street(int s)const{
    switch(s%10){
        case 1: return to_string(s)+"st Ave"; 
        case 2: return to_string(s)+"nd Ave"; 
        case 3: return to_string(s)+"rd Ave";
        default: return to_string(s)+"th Ave";
    }
}

