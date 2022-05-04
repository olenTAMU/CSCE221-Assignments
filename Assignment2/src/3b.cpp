#include <iostream>
#include <vector>

using namespace std;

void swapVector(vector<int>& v, int a, int b){
  int temp = v.at(a);
  v.at(a) = v.at(b);
  v.at(b) = temp;
}

int main() {
  vector<int> v;
  for(int i = 150; i < 449; i+=2){
    v.push_back(i);
  }
  for(int i = 449; i > 150; i-=2){
    v.push_back(i);
  }
  for(int i = 0; i < 300; i++){
    bool sorted = true;
    for(int j = 0; j < 299; j++){
      if(v.at(j) < v.at(j+1)){
        swapVector(v, j, j+1);
        sorted = false;
      }
    }
    if(sorted){
      break;
    }
  }
  for(int i = 0; i < v.size(); i++){
    cout << v.at(i) << " ";
  } cout << endl;
} 