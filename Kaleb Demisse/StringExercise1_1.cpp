#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char id2[1][11];
    char id[5][11]={"ETS0869/14", "ETSO944/14", "ETS0987/14", "ETS1052/14", "ETS1006/14"};
    cout << "Enter ID: ";
    cin >> id2[0];
    for (int i=0;i<5;i++){
        if(strcmp (id2[0],id[i])==0){
            cout << "Valid id" << endl;
            return 0;
        }
    }
    cout << "Invalid id" <<endl;
    return 0;
}