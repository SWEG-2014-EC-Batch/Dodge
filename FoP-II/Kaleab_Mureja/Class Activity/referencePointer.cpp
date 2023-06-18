#include <iostream>
using namespace std;
void work(int &x)
{
    x++; // can change data within function
    cout << x << endl;
}
void print(string &u)
{
    u = "kaleab mureja "; // can also change the string
    cout  << u << endl;
}
void swap ( int &x , int &y) 
{
   int  temp = x;
   x = y;
   y = temp ; 
   cout << " x = " << x << " and " << " y = " << y << endl;
}
int main()
{
    int a = 5;
    int &b = a;
    int c = 0 ;
    int d = 10 ;
    swap ( c , d );
    string name = "dawit mureja";
    work(a);
    cout << b + 5 << endl; // return 10 because a and b are equal under this reference declaretion
    print(name); // we write the function name with specific reference point(which is the declared pointer).
    return 0;
}