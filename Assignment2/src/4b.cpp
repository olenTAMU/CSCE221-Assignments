#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#define DEBUG 0

using namespace std;

struct Node {
  int data;
  Node* prev;
  Node* next;
  Node();
  ~Node();
};

Node::Node() : data{INT32_MAX}, next{nullptr}, prev{nullptr} { }

Node::~Node(){
  data = 0;
}


class LinkedList {
  int _size; //the number of nodes in the list
  Node* _head; //the address of the first node
  Node* _tail; //the address of the last node
    
 public:
    LinkedList(); //constructor
    ~LinkedList(); //destructor
    int size() const; //gives the number of nodes
    bool empty() const; //if the list is empty or not
    Node* head() const; //gives the address of the first node
    Node* tail() const;
    void append(int data);
    void clear(); //deletes all elements in the list
};

LinkedList::LinkedList() 
  : _size(0), _head(nullptr), _tail(nullptr) { }

LinkedList::~LinkedList() {
    clear();
}

Node* LinkedList::head() const{
  return _head;
}

Node* LinkedList::tail() const{
  return _tail;
}

int LinkedList::size() const{
  return _size;
}

bool LinkedList::empty() const{
  return _head == nullptr;
}

void LinkedList::clear(){
  Node* curr = _head;
  while(_head != nullptr){
    curr = _head;
    _head = _head -> next;
    delete curr;
  }
  _size = 0;
  _head = nullptr;
  _tail = nullptr;
  return;
}


void LinkedList::append(int data){
  Node* new_node = new Node();
  new_node -> data = data;
  new_node -> next = nullptr;
  new_node -> prev = nullptr;
  if(empty()){
    _head = new_node;
    _tail = new_node;
    _size = 1;
    return;
  }
  _tail -> next = new_node;
  new_node -> prev = _tail;
  _tail = new_node;
  _size++;
}

void printList(LinkedList& list) {
    Node* curr = list.head();
    cout << curr -> data <<  " ";
    curr = curr -> next;
    while (curr != nullptr) {
        cout <<  curr -> data <<  " ";
        curr = curr -> next;
    }
    cout << endl;
}


int main() {
  LinkedList list1;
  
  for(int i = 150; i < 449; i+=2){
    list1.append(i);
  }
  for(int i = 449; i > 150; i-=2){
    list1.append(i);
  }
  //exchange sort
  Node* curr = new Node();
  curr = list1.head();

  for(int i = 0; i < 299; i++){
    
    Node* search = new Node();
    search = curr -> next;
    while(search != nullptr){
      if((curr -> data) >= (search -> data)){
        int temp = curr -> data;
        curr -> data = search -> data;
        search -> data = temp;
      }
      search = search -> next;
    }
    curr = curr -> next;
  }
  
  printList(list1);
  
}