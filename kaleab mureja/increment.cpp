#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter a number\n\t n = ";
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "the number is even" << endl;
    }
    else
    {
        cout << "the number is odd " << endl;
    }
    return 0;
    // }
    // #include <iostream>
    // using namespace std;

    // int main()
    // {
    // Taking input
    char ch = '6';

    if (isdigit(ch))
    {
        cout << "\nEntered character is"
             << " numeric character";
    }
    else
    {
        cout << "\nEntered character is not"
                " a numeric character";
    }
    // return 0;
    // }
    // #include <iostream>
    // using namespace std;
    // int main() {
    char c1 = 's';
    char c2 = '8';

    if (isdigit(c1))
    {
        cout << "The character is a digit\n";
    }
    else
    {
        cout << "The character is not a digit\n";
    }

    if (isdigit(c2))
    {
        cout << "The character is a digit\n";
    }
    else
    {
        cout << "The character is not a digit";
    }

    //    return 0;
    // }
    // #include <iostream>
    // #include <string>

    // using namespace std;

    // int main()
    // {

    int integer;
    int positive;
    int negative;
    int odd;
    int even;
    char ynAns;

    cout << "Please enter an integer." << endl;
    cin >> integer;
    cout << "The integer you entered is " << endl;

    if (integer < 0)
    {
        integer = negative;
        cout << "negative " << endl;
    }
    if (integer > 0)
    {
        integer = positive;
        cout << "positive " << endl;
    }
    if (integer == 0)
    {
        integer = 0;
        cout << "zero." << endl;
    }

    if ((integer % 2 == 0) && (integer != 0))
    {
        integer = even;
        cout << "and even." << endl;
    }
    else if ((integer != 0) && (integer != even))
    {
        integer = odd;
        cout << "and odd." << endl;
    }

    return 0;
}
