//Symbol Checker

#include <iostream>
using namespace std;

int main () {
    char symbol;

    cout << "Enter a symbol: ";
    cin >> symbol;

    if (symbol >='a' && symbol <= 'z'){
        if (symbol == 'a'||symbol =='e'||symbol == 'i'||symbol == 'o'||symbol == 'u'){
            cout << "It's a vowel lowercase letter." <<endl;
        }
        else {
            cout <<  "It's a consonant lowercase letter." <<endl;
        }
    }
    else if (symbol >='A' && symbol <= 'Z'){
        if (symbol == 'A'||symbol =='E'||symbol == 'I'||symbol == 'O'||symbol == 'U'){
            cout << "It's a vowel uppercase letter." <<endl;
        }
        else {
            cout << "It's a consonant  uppercase letter." <<endl;
        }
    }
    else if (symbol >='0' && symbol <= '9' && symbol % 2==0){
        cout <<"It is an even digit." <<endl;
    }
    else if (symbol >='0' && symbol <= '9' && symbol % 2==1){
        cout << "It is an odd digit." <<endl;
    }
    else{ 
        cout << "It's a special character." <<endl;
    }
    return 0;
}
