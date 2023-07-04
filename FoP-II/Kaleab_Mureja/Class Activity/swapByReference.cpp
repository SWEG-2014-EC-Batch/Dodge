#include <iostream>
using namespace std;

void swap (int& x , int& y);

int main (){
int x , y ;
cout << "Enter x and y respectively: " << endl;
cin >> x >> y ;
cout << "Before swapping the value by reference x = " << x << " and y = " << y << endl;
swap (x,y);
cout << "After calling the swap function x and y value in the main function  x = " << x << " and y = " << y << endl;
}

void swap (int& x , int& y){
  int temp = x;
  x = y , y = temp;
  cout << "After swapping the value by reference x = " << x << " and y = " << y << endl;
}