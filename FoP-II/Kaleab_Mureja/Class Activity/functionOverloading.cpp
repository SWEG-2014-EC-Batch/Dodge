#include <iostream>
using namespace std;

void display (int x);
void display (double x);
void display (int x , int y);

int main (){
  int a = 5;
  display(a);
  int b = 6;
  display (a , b);
  double c = 3.0;
  display (c);
}

void display (int x ){
  cout << "Your int argument Num: " << x << endl;
}
void display (int x , int y){
  cout << "Your int arguments are Num1: " << x << " and Num2: " << y << endl;
  int sum = x + y;
  cout << "Their sum = " << sum << endl;
}
void display (double x){
  cout << "Your double argument Num: " << x << endl;
}