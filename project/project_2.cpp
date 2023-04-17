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
        cout << endl;
    }
    return 0;
}
