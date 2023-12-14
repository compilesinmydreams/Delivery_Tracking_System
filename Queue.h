#ifndef QUEUE_H
#define QUEUE_H

#include "Order.h"

class Queue {
	class Node {
    	public:
        Order* data;
        Node* next;
    };
private:
        
    Node* head;
    Node* tail;
    int count;
    
public:
    Queue();
    ~Queue();
    bool empty() const;
    int size() const;
    Order* peekFirst() const;
    Order* popFirst();
    void addLast(Order* order);
};

#endif 

