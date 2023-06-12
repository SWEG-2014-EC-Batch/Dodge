#include <iostream>
using namespace std;

int main()
{
    /*the pointer helps to know the address which is in which memory does the variable stores 
        int a = 10;
        int *b = &a;
        cout << b << endl;  // *b is pointer to find the address of a
        cout << *b << endl; // *b in this line address the value found in a ( and this different from the previous *b which is pointer)
        int **c = &b;       // *c is pointer of pointer to find the address of a pointer b
        cout << c << endl;
        **c = 5;
        cout << a << endl;
    int num[] = {10, 20, 30, 40, 5}; // all values found in the array have diffrent adress value
    int *ptr = num;
    cout << num << endl;
    cout << num[0] << endl;
    cout << *(num +1)<< endl;
    cout << * (ptr++) << endl;
    cout << ptr << endl;
    cout << &num[0] << endl;
    cout << &num[1] << endl;
    cout << &num[2] << endl;
    int x = 5;
    int *y = &x;
    cout << y << endl;
    cout << *y << endl; // in this pointer the *y stands for x because we are decrementing to the previous step from address of x which is the value of x (5)
    int **z = &y;
    cout << z << endl;
    **z = 377; // in this pointer of pointer the **z is represent the fist diclare value or x and this means x=377 and it dispaly 377 when we try to print x after this 
    cout << x << endl;

}