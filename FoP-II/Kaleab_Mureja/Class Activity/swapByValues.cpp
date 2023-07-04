#include <iostream>
using namespace std;

void swap(int x , int y);

int main (){
  int x , y ;
  cout << "Enter x and y respectively" <<endl;
  cin >> x >> y ;
  cout << "Before swapping the values: x = " << x << " and y = " << y << endl;
  swap (x,y);
}

void swap(int x , int y){
  int temp = x;
  x = y, y = temp;
  cout << "After swapping the value x = " << x << " y = " << y << endl;
}