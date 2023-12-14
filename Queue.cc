#include "Queue.h"

Queue::Queue() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

Queue::~Queue() {
    Node* curr= head;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr->data;
        delete curr;
        curr = next;
    }
}

bool Queue::empty() const {
    if(head==nullptr&&tail==nullptr){
    	return true;
    }
    return false;
}

int Queue::size() const {
    return count;
}

Order* Queue::peekFirst() const {
    if (empty()) {
        return nullptr;
    }
    return head->data;
}

Order* Queue::popFirst() {
    if (empty()==true) {
        return nullptr;
    }
    if (count==1) {
    	Order* order=head->data;
    	Node* remove = head;
    	head = nullptr;
        tail = nullptr;
        count--;
        delete remove;
        return order;
    }
    Order* order = head->data;
    Node* remove = head;
    head = head->next;
    count--;
    delete remove;
    return order;
}

void Queue::addLast(Order* order) {
    Node* newNode = new Node();
    newNode->data = order;
    newNode->next = nullptr;
    count++;
    if (!empty()) {
    	tail->next = newNode;
       
    } else {
         head = newNode;
    }
    tail = newNode;
}

