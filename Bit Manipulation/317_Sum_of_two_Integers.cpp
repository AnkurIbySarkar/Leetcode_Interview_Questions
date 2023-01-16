#include <iostream>
using namespace std;
class Solution
{
public:
    // int getSum(int a, int b)
    // {
    //     int carry;
    //     while (b != 0)
    //     {
    //         carry = a & b;
    //         a = a ^ b;
    //         b = (unsigned int)carry << 1;
    //     }
    //     return a;
    // }

    // recursion
    int getSum(int a, int b)
    {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
};
int main()
{
    int a = 1, b = 2;
    Solution obj;
    int ans = obj.getSum(a, b);
    cout << ans;
}