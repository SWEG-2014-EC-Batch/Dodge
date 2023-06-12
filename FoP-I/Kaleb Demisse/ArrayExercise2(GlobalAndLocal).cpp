#include <iostream>
using namespace std;

int k[6];

int main(){
    int m[2];

    for(int i=0; i<=((sizeof(k)/sizeof(k[0]))-1);i++){
        cout << k[i]<< endl;
    }
    cout << endl;
    for(int i=0; i<=((sizeof(m)/sizeof(m[0]))-1);i++){
        cout << m[i]<< endl;
    }
}