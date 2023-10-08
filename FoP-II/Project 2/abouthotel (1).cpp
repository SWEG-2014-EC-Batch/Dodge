#include "main.h"

void about()
{
    ifstream myfile("Dodgehotel.txt", ios::in);

    if (!myfile)
    {
        cout << "File not open" << endl;
        exit(1);
    }

    string line;
    while (getline(myfile, line))
    {
        cout << line << endl;
    }

    myfile.close();

}
