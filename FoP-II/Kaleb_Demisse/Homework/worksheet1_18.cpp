#include <iostream>
#include <assert.h>

using namespace std;

void get_input(double& price, double& discount, bool& is_percentage);
void calculate_discount(double& price, double discount, bool is_percentage);
void print_output(double price);

int main() {
    double price;
    double discount;
    bool is_percentage;

    get_input(price, discount, is_percentage);

    calculate_discount(price, discount, is_percentage);

    print_output(price);

    return 0;
}
void get_input(double& price, double& discount, bool& is_percentage) {

    cout << "Enter the price of the item: ";
    cin >> price;

    cout << "Enter the discount: ";
    cin >> discount;

    cout << "Is the discount a percentage (true/false)? ";
    cin >> is_percentage;
}

void calculate_discount(double& price, double discount, bool is_percentage) {

    assert(discount >= 0);



    if (is_percentage) {
        discount = discount / 100.0;
        price -= price * discount;
    } else {
        price -= discount;
    }
    assert(price > 0);
}

void print_output(double price) {
    cout << "The price after applying the discount is " << price << endl;
}