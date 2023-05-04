#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int count=0;
    char inp[6];
    char ans[6]={"abcda"};
    cout << "Enter your answers: ";
    for(int i=0;i<5;i++){
        cin >> inp[i];
        }
    
    for(int i=0;i<5;i++){
        if (inp[i]==ans[i]){
            cout << "Question " << i+1 << " is correct." <<endl;
            count++;
        }
        else{
            cout << "Question " << i+1 << " is wrong." <<endl;
        }
    }
    cout << endl << "Your result is: " << count <<endl;
    return 0;

}