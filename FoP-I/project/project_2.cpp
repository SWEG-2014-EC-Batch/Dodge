#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a postive integer: ";
    cin >> n;
    if (n<1){
         return 0;
    }
    for (int i = 0; i <= n*2; i++)
    {
        for (int j = 0; j <= n*2; j++)
        {
            if(i<=n){
                if(j<=i){
                    cout << i-j <<" ";
                }
                else if(j>=n*2 -i){
                    cout << i+j-n*2 << " ";
                }
                else{
                cout << "  ";
                }
            }
            else{
                if(j<= n*2 -i){
                    cout << n*2 -i-j <<" ";
                }
                else if ( j>=i){
                    cout << j-i << " ";
                }
                else{
                cout << "  ";
                }
            }
        }
        cout << endl;
    }    
    return 0;
}
