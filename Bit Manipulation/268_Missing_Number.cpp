#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // int missingNumber(vector<int> &nums)
    // {
    //     sort(nums.begin(), nums.end());
    //     int sum = nums.size();
    //     int total = nums.size() * (nums.size() + 1) / 2;
    //     for (int i = 0; i < nums.size(); i++)
    //     {

    //         if (nums[i] != i)
    //         {
    //             sum = i;
    //             break;
    //         }
    //     }
    //     return sum;
    // }

    // XOR

    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int ans = n, mask = 0;
        for (int i = 0; i < n; i++)
        {
            ans ^= nums[i];
            mask ^= i;
        }
        return ans = (ans ^ mask);
    }
};
int main()
{
    vector<int> v{0, 1};
    Solution obj;
    int ans = obj.missingNumber(v);
    cout << ans;
}