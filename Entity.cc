#include "Entity.h"
#include <iostream>
using namespace std;

Entity::Entity(char type, int id, std::string name, Location location) {
    this->id = type +to_string(id);
    this->name = name;
    this->location = location;
    this->orders = new Queue();
    }
Entity::~Entity(){
	delete orders;
}
void Entity::setLocation(Location location) {
    this->location = location;
}

void Entity::addOrder(Order* order) {
    orders->addLast(order);
}

Order* Entity::getNextOrder() {
    return orders->popFirst();
}

int Entity::getNumOrders() const {
    return orders->size();
}

void Entity::print() const {
    cout << "ID: " << id << ", Location: ";
    location.print();
    cout << ", Number of Orders: " << getNumOrders() << endl;
}

bool Entity::equals(string id) const {
    return this->id == id;
}

Location Entity::getLocation(){
    return this->location;
}

string Entity::getId() const{
    return this->id;
}
string Entity::getName() const{
    return this->name;
}
