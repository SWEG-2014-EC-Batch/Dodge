#include <iostream>
#include <cassert>
using namespace std;

void applyDiscount(double& price, double discount, bool isPercentage) {
    assert(discount < 0.0);  // Ensure the discount is negative

    double discountAmount;
    if (isPercentage) {
        discountAmount = (discount / 100.0) * price;
    } else {
        discountAmount = discount;
    }

    assert(price - discountAmount > 0.0);  // Ensure price doesn't drop to zero
    price -= discountAmount;
}

int main() {
    double price;
    double discount;
    bool isPercentage;

    cout << "Enter the price of the item: ";
    cin >> price;
    cout << "Enter the discount amount: ";
    cin >> discount;
    cout << "Is the discount a percentage? (0 for fixed amount, 1 for percentage): ";
    cin >> isPercentage;

    try {
        applyDiscount(price, discount, isPercentage);
        cout << "Discounted price: $" << price << endl;
    } catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}