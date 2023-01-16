#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    // O(N),O(1)
    // int search(vector<int> &nums, int target)
    // {
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (nums[i] == target)
    //         {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && nums[mid] >= target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> v{4, 5, 6, 7, 0, 1, 2};
    Solution obj;
    int ans = obj.search(v, 0);
    cout << ans;
}