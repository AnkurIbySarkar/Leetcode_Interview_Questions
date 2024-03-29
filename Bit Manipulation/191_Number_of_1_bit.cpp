#include <iostream>
using namespace std;
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n != 0)
        {
            if (n & 1)
            {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};
int main()
{
    uint32_t n = 00000000000000000000000000001011;
    Solution obj;
    int ans = obj.hammingWeight(n);
    cout << ans;
}
