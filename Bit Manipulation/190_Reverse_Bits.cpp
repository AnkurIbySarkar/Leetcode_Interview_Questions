#include <iostream>
using namespace std;
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t rev = 0;
        int d = 0;
        while (n > 0)
        {
            rev += (n % 2) << (31 - d);
            n >>= 1;
            d++;
        }

        return rev;
    }
};
int main()
{
    uint32_t n = 10100101000001000011;
    Solution obj;
    uint32_t ans = obj.reverseBits(n);
    cout << ans;
}