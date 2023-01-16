#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    // int singleNumber(vector<int> &nums)
    // {
    //     int ans;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         int count = 0;
    //         for (int j = 0; j < nums.size(); j++)
    //         {
    //             if (nums[i] == nums[j])
    //             {
    //                 count++;
    //             }
    //             else
    //             {
    //                 continue;
    //             }
    //         }
    //         if (count == 1)
    //         {
    //             return nums[i];
    //         }
    //     }
    //     return -1;
    // }
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};
int main()
{
    vector<int> v{4, 1, 2, 1, 2};
    Solution obj;
    int ans = obj.singleNumber(v);
    cout << ans;
}