#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10))
        {
            return 0;
        }

        while (x != 0)
        {
            int digit = x % 10;
            rev = (rev * 10) + digit;
            x = x / 10;
        }
        return rev;
    }
};
int main()
{
    Solution obj;
    int ans = obj.reverse(123);
    cout << ans;
}