#include <iostream>
// #include <array>
using namespace std;
int main()
{
    string id[5] = {"ets0884/14", "ets0870/14", "ets0860/14", "ets0890/14", "ets0880/14"};
    char name[5][4] = {"kal", "kidus", "leul", "mathew", "miki"};
    string id_num;
    int count = 0;
    cout << "enter an ID num: ";
    cin >> id_num;
    for (int i = 0; i < sizeof(id) / sizeof(id[0]); i++)
    {
        if (id[i] == id_num)
        {
            cout << name[i] << endl;
            count++;
            break;
        }
    }
    if (count == 0)
    {
        cout << "ID not found" << endl;
    }
}