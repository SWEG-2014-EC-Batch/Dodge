//BMI calculator

#include <iostream>
using namespace std;
int main(){
    int choice, lowerbound, upperbound, number;
    float height,weight, BMI;
    char gender, exit;
    cout <<"\t1. Calculate BMI of one person\n\t2. Calculate BMI of a known number of people\n\t"
             "3. Calculate BMI until told to stop\n Choose an option: ";
    cin >>choice;
    switch(choice){
        case 1: 
            cout << "Enter \"m\" for male and \"f\" for female:";
            cin >> gender;
            cout << "Enter your weight in kilograms:";
            cin >> weight;
            cout << "Enter your height in meters:";
            cin >> height;
            BMI = weight/(height*height);
            cout << "Your BMI is " << BMI << endl;
            lowerbound = 20;
            upperbound = 25;
            if (gender == 'f') {
                lowerbound= 18;
                upperbound = 23;
            }

            if (BMI < lowerbound) {
                cout << "You are underweight" << endl;
            } 
            else if (BMI > upperbound) {
                cout << "You are overweight" << endl;
            } 
            else {
                cout << "You are in the normal range" << endl;
            }
            break;
        case 2:
            cout << "Enter number of people: ";
            cin >> number;
            for(int i=1; i<=number; i++){
                cout << "Enter \"m\" for male and \"f\" for female:";
                cin >> gender;
                cout << "Enter your weight in kilograms:";
                cin >> weight;
                cout << "Enter your height in meters:";
                cin >> height;
                BMI = weight/(height*height);
                cout << "Your BMI is " << BMI << endl;
                lowerbound = 20;
                upperbound = 25;
                if (gender == 'f') {
                    lowerbound= 18;
                    upperbound = 23;
                }

                if (BMI < lowerbound) {
                    cout << "You are underweight" << endl;
                } 
                else if (BMI > upperbound) {
                    cout << "You are overweight" << endl;
                } 
                else {
                    cout << "You are in the normal range" << endl;
                }
            }
            break;
        case 3:
            while(exit!= 'y'){
                cout << "Enter \"m\" for male and \"f\" for female:";
                cin >> gender;
                cout << "Enter your weight in kilograms:";
                cin >> weight;
                cout << "Enter your height in meters:";
                cin >> height;
                BMI = weight/(height*height);
                cout << "Your BMI is " << BMI << endl;
                lowerbound = 20;
                upperbound = 25;
                if (gender == 'f') {
                    lowerbound= 18;
                    upperbound = 23;
                }

                if (BMI < lowerbound) {
                    cout << "You are underweight" << endl;
                } 
                else if (BMI > upperbound) {
                    cout << "You are overweight" << endl;
                } 
                else {
                    cout << "You are in the normal range" << endl;
                }
                cout << "To exit enter \'y\', to continue enter any other key: ";
                cin >> exit;
            }
            break;
    }
    
    return 0;
}