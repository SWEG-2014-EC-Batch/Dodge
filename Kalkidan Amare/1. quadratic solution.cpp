
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b, c, x1, x2, discriminant;
    cout << "enter a b and c ";
    cin >> a >> b >> c;
    discriminant = b * b - (4 * a * c);
    if (discriminant > 0)
    {
        cout << "x1= " << ((-b) + sqrt(discriminant)) / (2 * a);
        cout << "x2= " << ((-b) - sqrt(discriminant)) / (2 * a);
    }
    else if (discriminant == 0)
    {
        cout << "x= " << (-b) / (2 * a);
    }
    else if (discriminant < 0)
    {
        double real = -b / 2 * a;

        cout << "x1= " << real << " imaginary " << sqrt(-discriminant) / (2 * a) << "i \n";
        cout << "x2= " << real << " imaginary " << -sqrt(-discriminant) / (2 * a) << "i \n";
    }
    return 0;
}
