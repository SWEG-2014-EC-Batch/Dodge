#include <iostream>

int fibonacci(int n = 10);

int main()
{
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    std::cout << "Fibonacci series up to " << num << " terms: ";
    fibonacci(num);

    return 0;
}

int fibonacci(int n)
{
    int first = 1;
    int second = 1;

    if (n <= 0)
    {
        std::cout << "Invalid input! The number of terms must be positive." << std::endl;
        return 0;
    }

    if (n == 1 || n == 2)
    {
        return 1;
    }

    for (int i = 2; i < n; ++i)
    {
        int next = first + second;
        first = second;
        second = next;
    }

    return second;
}
