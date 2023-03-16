#include <iostream> 
using namespace std;
int main(){
    int choice,input,remainder, reversedNumber;
    int count=0;
    int sum=0;
    int product =1;
    int first, last, temp1, temp2;
    cout <<"\t1. Prints the reverses of the number"
            "\n\t2. Counts the number of digits in a given number"
            "\n\t3. Find the sum of the digits of the a given number"
            "\n\t4. Find the product of even digits of the a given number"
            "\n\t5. Prints the first and the last digit of the number and find their sum"
            "\n\t6. Check whether a number is palindrome or not"
            "\n\t7. Check if a number is Armstrong or not."
            "\nChoose an option: ";
    cin >> choice;
    cout << "Enter an integer: ";
    cin >> input;
    switch(choice){
        case 1:
            while(input != 0){
                remainder = input % 10;
                reversedNumber = reversedNumber * 10 + remainder;
                input /= 10;
            }
            cout << "Reversed Number = " << reversedNumber;
            break;
        case 2:
            while(input !=0){
                input /=10;
                count++;
            }
            cout << "The number of digits is equal to " << count << endl;
            break;
        case 3:
            while(input!=0){
                sum += input%10;
                input/=10;
            }
            cout << "The sum of  its digits is equal to " << sum << endl;
            break;
        case 4:
            while(input!=0){
                product *= input%10;
                input/=10;
            }
            cout << "The product of  its digits is equal to " << product << endl;
            break;
        case 5:
            last = input%10;
            while(input !=0){
                first = input%10;
                input/=10;
            }
            cout << "The first digit is " << first << endl;
            cout << "The last digit is " << last << endl;
            cout << "Their sum is equal to " << first+last << endl;
            break;
        case 6:
            temp2=input;
            while(input != 0){
                remainder = input % 10;
                reversedNumber = reversedNumber * 10 + remainder;
                input /= 10;
            }
            if (temp2 == reversedNumber)
                cout << " The number is a palindrome.";
            else
                cout << " The number is not a palindrome.";
            break;
        case 7:
            temp2= input;
            while(input !=0){
                temp1 = input %10;
                sum += temp1*temp1*temp1;
                input/=10;
            }
            if (temp2 == sum)
                cout << " The number is an armstrong.";
            else
                cout << " The number is not a armstrong.";
            break;
        default:
            cout << "Invalid choice" <<endl;
    }
    return 0;
}