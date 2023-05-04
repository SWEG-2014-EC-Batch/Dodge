#include <iostream>
using namespace std;

void display(char *strng)
{
    cout << strng << endl;
}

int main()
{
    char message[] = "vacation is near";
    display(message);
    return 0;
}
