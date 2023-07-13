#include <iostream>
using namespace std;

struct complex
{
    float real;
    float imaginary;
} comp[2];
void operation(complex *comp)
{
    cout << "sum= " << comp[0].real + comp[1].real << " + " << comp[0].imaginary + comp[1].imaginary << "i" << endl;
    cout << "difference= " << comp[0].real - comp[1].real << " + " << comp[0].imaginary - comp[1].imaginary << "i" << endl;
    cout << "product= " << comp[0].real * comp[1].real << " + " << comp[0].imaginary * comp[1].imaginary << "i" << endl;
    cout << "quotient= " << comp[0].real / comp[1].real << " + " << comp[0].imaginary / comp[1].imaginary << "i" << endl;
}
int main()
{
    cout << "Enter the real and imaginary part of the number" << endl;
    for (int i = 0; i < 2; ++i)
    {
        cout << "real part of no" << i + 1 << ": ";
        cin >> comp[i].real;
        cout << " imaginary part of no" << i + 1 << ": ";
        cin >> comp[i].imaginary;
    }
    operation(comp);
}