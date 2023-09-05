#include <iostream>
#include <iomanip>
using namespace std;

int acceptInput();
int countDigits(int rows);
void printRow(int input, int row, int digits, int column =0);
void printPattern(int input, int digits, int row=0);

int main(){
    int input = acceptInput();
    int digits= countDigits(input);
    printPattern(input, digits);
    return 0;
}

int acceptInput(){
    int input;
    cout << "Enter a postive number: ";
    cin >> input;
    if (input < 1){
        cout << "Invalid Input" << endl;
        terminate;
    }
    return input;
}
int countDigits(int rows){
    int digits = 0;
    while (rows != 0)
    {
        rows /= 10;
        digits++;
    }
    return digits;
}
void printRow(int input, int row, int digits, int column){
    if(column>=2*input+1)
        return;
    else{
        if((column>row && column< 2*input-row)||(column<row && column>2*input-row))
            cout << left << setw(digits+1) << " ";
        else
            cout << left << setw(digits+1) << ((column < input) ? (row-column): (column+row-2*input));
        printRow(input, row, digits, column+1);
    }
}
void printPattern(int input, int digits, int row){
    if(row>=2*input+1)
        return;
    else{
        (row<input) ? printRow(input,row,digits):printRow(input, 2*input-row, digits);
        cout << endl;
        printPattern(input, digits, row+1);
    }
}
