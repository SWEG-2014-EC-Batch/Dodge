#include <iostream>
#include <cassert>
using namespace std;

void applyDiscount(double &price, double discount, bool isPercentage)
{
    assert(discount >= 0); // Check that discount is not negative

    if (isPercentage)
    {
        double percentage = discount / 100.0;
        price -= price * percentage;
        assert(price > 0); // Check that price doesn't drop to zero
    }
    else
    {
        assert(price - discount > 0); // Check that price doesn't drop to zero
        price -= discount;
    }
}

int main()
{
    double price, discount;
    bool isPercentage;
    cout << "enter price and discount: ";
    cin >> price >> discount;
    cout << "Is the discount in percentage? (1/0): ";
    cin >> isPercentage;

    applyDiscount(price, discount, isPercentage);

    cout << "Discounted price: " << price << endl;

    return 0;
}
