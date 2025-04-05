// Pow(x, n).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
using namespace std;

class Solution1  // log n
{
public:
    double myPow(double x, int n) 
    {
        if (n == 0 || x == 1) return 1.00;
        if (x == 0) return 0;

        long long exp = n; // prevent overflow
        if (exp < 0)  // handle negative exponent
        {
            x = 1 / x;
            exp = -exp;
        }

        double result = 1.0;
        while (exp > 0)
        {
            if (exp & 1)
                result *= x; // update result
            x *= x;           // square x
            exp >>= 1; // move exponent a bit further
        }
        return result;
    }
}; 

// Divide and conquer
class Solution2
{
public:
    double myPow(double x, int n)
    {
        function<double(double, int)> helper = [&](double a, int b) -> double
        {
            if (b == 0 || a == 1) return 1.00;
            if (a == 0) return 0;

            auto res = helper(a, b / 2);
            res *= res;
            return b % 2 == 0 ? res : a * res;
        };

        auto result = helper(x, abs(n));
        return n >= 0 ? result : 1 / result;
    }
};

int main()
{
    Solution2 s;
    cout << "pow(x, n): " << s.myPow(1, 10) << endl;
    cout << "pow(x, n): " << s.myPow(2, 8) << endl;
}