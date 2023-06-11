#include <iostream>
using namespace std;

//recieve a name and write a welcome message
void welcome();

int main(){
    welcome();
    return 0;
}

void welcome(){
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello, " << name << "\nWelcome to M.P" << endl;
}