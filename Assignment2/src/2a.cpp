#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void insertPointer(int* pointer, int partition, int num){
  for(int i = 0; i <= partition; i++){
    if(num < pointer[i] && num >= pointer[i-1]){
      for(int j = partition; j >= i; j--){
        pointer[j+1] = pointer[j];
      }
      pointer[i] = num;
      return;
    }
  }
}

int main() {
  int* pointer = new int[300];
  
  for(int i = 0; i < 150; i++){
    pointer[i] = 150 + i*2;
  }
  for(int i = 150; i >= 0; i--){
    pointer[i+150] = 449 - i*2;
  }

  for(int i = 0; i < 300; i++){
    insertPointer(pointer, i-1, pointer[i]);
  }
  for(int i = 0; i < 300; i++){
    cout << pointer[i] << " ";
  }cout << endl;

}
