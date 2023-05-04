#include <iostream>
#include <cstring>
using namespace std;
int main() {
    string id2;
    string id[5][2]={{"ETS0869/14","Kaleb Demisse"},  
                     {"ETSO944/14", "Kirubel Legesse"},
                     {"ETS0987/14", "Liya Tsegaye"}, 
                     {"ETS1052/14", "Meseret Bolled"}, 
                     {"ETS1006/14", "Makda Yoseph"}};

    cout << "Enter ID: ";
    cin >> id2;
    for (int i=0;i<5;i++){
        if(id2==id[i][0]){
            cout << id[i][1]<< endl;
            return 0;
        }
    }
    cout << "Invalid id" <<endl;
    return 0;
}