#include <iostream>
using namespace std;
class Solution
{
public:
    // double myPow(double x, int n)
    // {
    //     double ans = 1.0;
    //     if (n < 0)
    //     {
    //         return myPow(1 / x, -n);
    //     }

    //     for (int i = 0; i < n; i++)
    //     {
    //         ans = ans * x;
    //     }
    //     return ans;
    // }

    // O(log n)
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long nn = n;
        if (n < 0)
            nn = -1 * nn;
        while (nn)
        {
            if (nn % 2)
            {
                ans = ans * x;
                nn = nn - 1;
            }
            else
            {
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0)
        {
            ans = (double)(1.0) / (double)(ans);
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    double ans = obj.myPow(2.00000, -2);
    cout << ans;
}