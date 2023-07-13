#include <iostream>
using namespace std;

struct co
{
    int x, y;
} xy;
co read()
{
    cout << "Enter x and y coordinates of a point.\n";
    cout << "x: ";
    cin >> xy.x;
    cout << "y: ";
    cin >> xy.y;
    return xy;
}
void print(co xy)
{
    cout << "The coordinates of a point are...\n";
    cout << xy.x << "x + " << xy.y << "y" << endl;
}
int main()
{
    read();
    print(xy);
}