#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    // int longestConsecutive(vector<int> &nums)
    // {
    //     if (nums.size() == 0)
    //     {
    //         return 0;
    //     }
    //     sort(nums.begin(), nums.end());
    //     int ans = 1;
    //     int prev = nums[0];
    //     int curr = 1;
    //     for (int i = 1; i < nums.size(); i++)
    //     {
    //         if (nums[i] == prev + 1)
    //         {
    //             curr++;
    //         }
    //         else if (nums[i] != prev)
    //         {
    //             curr = 1;
    //         }
    //         prev = nums[i];
    //         ans = max(ans, curr);
    //     }
    //     return ans;
    // }

    // using unordered_set
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> hashset;
        for (int num : nums)
        {
            hashset.insert(num);
        }

        int longeststreak = 0;

        for (int num : nums)
        {
            if (!hashset.count(num - 1))
            {
                int currNum = num;
                int currStreak = 1;

                while (hashset.count(currNum + 1))
                {
                    currNum += 1;
                    currStreak += 1;
                }
                longeststreak = max(longeststreak, currStreak);
            }
        }
        return longeststreak;
    }
};
int main()
{
    vector<int> v = {1, 2, 0, 1};
    Solution obj;
    int ans = obj.longestConsecutive(v);

    cout << ans;
}