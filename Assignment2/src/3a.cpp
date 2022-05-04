#include <iostream>
#include <vector>

using namespace std;

int selectVector(vector<int>& v, int partition){
  int max = partition + 1;
  for(int i = partition + 1; i < v.size(); i++){
    if(v.at(i) <= v.at(max)){
      max = i;
    }
  }
  return max;
}

int main() {
  vector<int> v;
  for(int i = 150; i < 449; i+=2){
    v.push_back(i);
  }
  for(int i = 449; i > 150; i-=2){
    v.push_back(i);
  }
  for(int i = 0; i < v.size() - 1; i++){
    int max = selectVector(v, i);
    int element = v.at(max);
    v.erase(v.begin() + max);
    v.emplace(v.begin(), element);
  }
  for(int i = 0; i < v.size(); i++){
    cout << v.at(i) << " ";
  }
  
}