#include <iostream>
using namespace std;

void hollow_pyramid(int rows)
{
    for (int i = 1, k = 0; i <= rows; i++, k = 0)
    {
        for (int j = 1; j <= rows - i; j++)
        {
            cout << " ";
        }
        while (k != 2 * i - 1)
        {
            if (k == 0 || k == 2 * i - 2 || i == rows)
                cout << "*";
            else
                cout << " ";
            k++;
        }
        cout << endl;
    }
}

void pyramid(int rows)
{
    for (int i = rows, k = 0; i >= 1; i--, k = 0)
    {
        for (int space = 1; space <= rows - i; space++)
        {
            cout << "  ";
        }

        while (k != 2 * i - 1)
        {
            cout << "* ";
            ++k;
        }
        cout << "\n";
    }
    cout << "\n";
}

void inverted_pyramid(int rows)
{
    for (int i = 1, k = 0; i <= rows; i++, k = 0)
    {
        for (int space = 1; space <= rows - i; space++)
        {
            cout << "  ";
        }

        while (k != 2 * i - 1)
        {
            cout << "* ";
            ++k;
        }
        cout << "\n";
    }
    cout << "\n";
}

void right_pyramid(int rows)
{
    char alphabet = 'A';
    for (int i = 1; i <= rows; i++, alphabet = 'A')
    {
        for (int j = 1; j <= i; j++)
        {
            cout << alphabet << " ";
            alphabet++;
        }

        cout << "\n";
    }
    cout << "\n";
}

int main()
{

    int rows, choise;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter: 1 for pyramid\t 2 for inverted pyramid\t 3 for right pyramid\t 4 for hollow pyramid ";
    cin >> choise;
    switch(choise){
        case 1:
            pyramid(rows);
            break;
        case 2:
            inverted_pyramid(rows);
            break;
        case 3:
            right_pyramid(rows);
            break;
        case 4:
            hollow_pyramid(rows);
            break;
        default:
            cout << "You entered invalid number!";
    }
    return 0;
}
            
