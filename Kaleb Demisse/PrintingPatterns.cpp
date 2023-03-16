#include <iostream> 
using namespace std;
int main(){
    int choice, row, col;
    cout << "\t1. Numbers 10 through 49 \n\t2. Rectangle(square)"
            "\n\t3. Hollow rectangle(square) \n\t4. Half pyramid"
            "\n\t5. Inverted half pyramid \n\t6. Full pyramid "
            "\n\t7. Rectangle(square) with numbers \n\t8. Half pryamid with numbers(a)"
            "\n\t9. Rectangle(square) with alphabets \n\t10. A rectangle made from A to X"
            "\n\t11. Half Pyramid with alphabets \n Choose a pattern to print: ";
    cin >> choice;
    
    if((choice >=2 && choice<=9)|| choice==11){
        cout << "Enter number of rows: ";
        cin >> row;
    }
    if (choice==2 || choice==3 || choice==7 || choice==9){
        cout << "Enter number of columns: ";
        cin >> col;
    }
    switch(choice){
        case 1:
            for(int i=10; i<50; i++){
                if (i%10==0)
                    cout <<endl;   
                cout << i << " ";
            }
            break;
        case 2:
            for(int i=1; i<=row; i++){
                for(int j=1; j<=col; j++){
                    cout << "* ";
                }
                cout << endl;
            }
            break;
        case 3:
            for (int i = 1; i <= row; i++) { 
                for (int j = 1; j <= col; j++) { 
                    if (i == 1 || i == row || j == 1 || j == col)         
                        cout << "* ";             
                    else
                        cout << "  ";
                } 
                cout << endl;
            }
            break;
        case 4:
            for(int i=1; i<=row; i++){
                for(int j=1; j<=i; j++){
                    cout << "* ";
                }
                cout << endl;
            }
            break;
        case 5:
            for(int i=row; i>=1; i--){
                for(int j=1; j<=i; j++){
                     cout << "* ";
                }
                cout << endl;
            }
            break;
        case 6:
            for(int i = 1, k = 0; i <= row; i++, k = 0) {
                for(int j = 1; j <= row-i; j++) {
                    cout <<"  ";
                }

                while(k != 2*i-1) {
                    cout << "* ";
                    k++;
                    }
                cout << endl;
            } 
            break;
        case 7:
            for(int i=1; i<=row; i++){
                for(int j=1; j<=col; j++){
                    cout << j << " ";
                }
                cout << endl;
            }
            break;
        case 8:
            for(int i=1; i<=row; i++){
                for(int j=1; j<=i; j++){
                    cout << j << ' ';
                }
                cout << endl;
            }
            break;
        case 9:
            for(int i=1; i<=row; i++){
                for(int j=1; j<=col; j++){
                    cout << (char)(96 + j)<<  ' ';
                }
                cout << endl;
            }
            break;
        case 10:
            for(int i =1; i <=24; i++ ){
                cout << (char)(64+i) << ' ';
                if(i%6==0)
                    cout <<endl;
            }
            break;
        case 11:
            for(int i=1; i<=row; i++){
                for(int j=1; j<=i; j++){
                    cout << (char)(64+j)<< ' ';
                }
                cout << endl;
            }
            break;
        default: 
        cout << "Not a valid choice. Closing Program." << endl;
    }
    return 0;
}