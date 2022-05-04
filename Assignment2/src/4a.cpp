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
  int index;
  Node();
  ~Node();
};

Node::Node() : data{INT32_MAX}, next{nullptr}, prev{nullptr}, index{INT32_MAX} { }

Node::~Node(){
  data = 0;
  index = 0;
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
    void insertionSort(Node*& partition);
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
  new_node -> index = _size - 1;
  new_node -> next = nullptr;
  new_node -> prev = nullptr;
  if(empty()){
    _head = new_node;
    _tail = new_node;
    _size = 1;
    new_node -> index = 0;
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

//void LinkedList::insert(){
  
//}

void LinkedList::insertionSort(Node*& partition){
  if(DEBUG) cout << "entered insertionSort" << endl;
  if(DEBUG) cout << partition -> data << endl;
  if(DEBUG) cout << partition -> next -> data << endl;
  /*
  choose the element after the partition
  store it temporarily and delink it from its prev and next
  search the nodes until the partition for the location to insert
  insert by linking into the prev and next
  */
  
  
  //maybe need to delete the old element

  //if the linked list is correct dont change it
  
  if((partition -> data) <= (partition -> next -> data)){
    if(DEBUG) cout << "partition data: " << partition -> data << " <= " << partition -> next -> data << endl;
    partition = partition -> next;
    if(DEBUG) cout << "exit with no change" << endl;
    return;
  }

  //otherwise, choose the node after the partition
  Node* element = new Node();
  element -> data = partition -> next -> data;

  if(DEBUG) cout << "1" << endl;
  partition -> next = partition -> next -> next;
  if(partition -> next != nullptr){
    partition -> next -> prev = partition;
  } else{
    _tail = partition;
  }
  if(DEBUG) cout << "element: " << element -> data << endl;
  if(DEBUG) cout << "partition: " << partition -> data << endl;
 

  if((element -> data) <= (head() -> data)){
    element -> next = head();
    element -> prev = nullptr;
    head() -> prev = element;
    _head = element;
    if(DEBUG) cout << "inserted to the front" << endl;
    return;
  }

  
  Node* curr = head();
  if(DEBUG) cout << "curr: " << curr -> next << endl;

  
  while(curr != partition){
    if(DEBUG) cout << "entered while loop" << endl;
    
    if((curr -> data) <= (element -> data) && (curr -> next -> data) > (element -> data)){
      if(DEBUG) cout << "found insertion point" << endl;
      element -> prev = curr;
      
      element -> next = curr -> next;
      curr -> next = element;
      element -> next -> prev = element;
      if(DEBUG) cout << element -> data << endl;
      if(DEBUG) cout << "INSERTED" << endl;
      return;
    }
    curr = curr -> next;
  }
  if(DEBUG) cout << "end of function" << endl;
  
}

int main() {
  LinkedList list;
  for(int i = 150; i < 449; i+=2){
    list.append(i);
  }
  for(int i = 449; i > 150; i-=2){
    list.append(i);
  }
  
  Node* node = list.head();
  
  while(node -> next != nullptr){
    list.insertionSort(node);
  }

  printList(list);
}