#include <iostream>
#include <vector>

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
}

int main() {
  int* pointer = new int[300];
  for(int i = 0; i < 300; i++){
    pointer[i] = 150 + i;
  }
  
  vector<int> v;
  for(int i = 150; i < 449; i++){
    v.push_back(i);
  }

  LinkedList list;
  for(int i = 150; i < 449; i++){
    list.append(i);
  }
  
  for(int i = 0; i < 300; i++){
    if(pointer[i] == 279){
      cout << pointer + i*sizeof(int) << " " << i << endl;
      break;
    }
  }

  for(int i = 0; i < v.size(); i++){
    if(v.at(i) == 279){
      cout << &v.at(i) << " " << i << endl;
      break;
    }
  }
  Node* node = new Node();
  node = list.head();
  while(node != nullptr){
    if(node -> data == 279){
      cout << node << endl;
      break;
    }
    node = node -> next;
  }
}