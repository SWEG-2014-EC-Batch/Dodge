#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if(i<10){
                if(j<=i){
                    cout << i-j <<" ";
                }
        }
        else if(j>=18-i){
                    cout << i+j-18 << " ";
                }
                else
                {
                cout << "  ";
                }
            }
        
    return 0;
}
