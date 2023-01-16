#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    // O(N),O(1)
    //  int findMin(vector<int> &nums)
    //  {
    //      int min = INT_MAX;
    //      for (int i = 0; i < nums.size(); i++)
    //      {
    //          if (nums[i] < min)
    //          {
    //              min = nums[i];
    //          }
    //      }
    //      return min;
    //  }

    // O(logN),O(1)
    int findMin(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int minVal = INT_MAX;
        while (low <= high)
        {
            if (nums[low] < nums[high])
            {
                minVal = min(nums[low], minVal);
            }
            int mid = low + (high - low) / 2;
            if (nums[low] <= nums[mid])
            {
                minVal = min(minVal, nums[low]);
                low = mid + 1;
            }
            else
            {
                minVal = min(minVal, nums[mid]);
                high = mid - 1;
            }
        }
        return minVal;
    }
};
int main()
{
    vector<int> v{3, 4, 5, 1, 2};
    Solution obj;
    int ans = obj.findMin(v);
    cout << ans;
}