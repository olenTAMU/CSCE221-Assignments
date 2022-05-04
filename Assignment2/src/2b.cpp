#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main() {
  int* pointer = new int[300];
  
  for(int i = 0; i < 150; i++){
    pointer[i] = 150 + i*2;
  }
  for(int i = 150; i >= 0; i--){
    pointer[i+150] = 449 - i*2;
  }

  for(int i = 0; i < 300; i++){
    for(int j = i; j < 300; j++){
      if(pointer[i] > pointer[j]){
        int temp = pointer[i];
        pointer[i] = pointer[j];
        pointer[j] = temp;
      }
    }
  }

  for(int i = 0; i < 300; i++){
    cout << pointer[i] << " ";
  } cout << endl;
}