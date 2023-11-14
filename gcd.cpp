#include <iostream>
using namespace std;

int gcd(int a, int b);
int extendedGCD(int a, int b, int &x, int &y);
int modInverse(int a, int b);

int main()
{
    int num1, num2;
    int x, y;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    int result_1 = gcd(num1, num2);
    int result_2 = extendedGCD(num1, num2, x, y);
    int inverse = modInverse(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " by Euclidean algorithm: " << result_1 << endl;
    cout << "GCD of " << num1 << " and " << num2 << " by extended Euclidean algorithm: " << result_2 << endl;
    cout << "Coefficients (x, y) for ax + by = gcd(a, b): (" << x << ", " << y << ")" << endl;
    /* These coefficients can be useful in various applications,
    such as solving linear Diophantine equations or finding modular inverses. */
    if (inverse == -1) cout << "Inverse doesn't exist for " << num1 << " modulo " << num2 << endl;
    else cout << "The modular multiplicative inverse of " << num1 << " modulo " << num2 << " is: " << inverse << endl;

    return 0;
}

// Function to find GCD using Euclidean algorithm
int gcd(int a, int b)
{
    // return b == 0 ? a : gcd(b, a % b);
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find GCD using extended Euclidean algorithm
int extendedGCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int gcd = extendedGCD(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;

    return gcd;
}

// Function to find the modular multiplicative inverse of a modulo m
int modInverse(int a, int b)
{
    int x, y;
    int gcd = extendedGCD(a, b, x, y);

    if (gcd != 1) return -1;
    else return (x % b + b) % b;
}
