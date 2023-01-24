#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Solution
{
public:
    // O(n^2) //O(1)
    //  vector<int> maxSlidingWindow(vector<int> &nums, int k)
    //  {
    //      vector<int> ans;
    //      if (nums.size() == 0 || k == 0)
    //      {
    //          return ans;
    //      }
    //      for (int i = 0; i < nums.size() - k + 1; i++)
    //      {
    //          int currsum = nums[i];
    //          for (int j = i; j <= i + k - 1; j++)
    //          {
    //              currsum = max(currsum, nums[j]);
    //          }
    //          ans.push_back(currsum);
    //      }
    //      return ans;
    //  }

    // O(N) //O(K)
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
int main()
{
    vector<int> v{1, 3, -1, -3, 5, 3, 6, 7};
    Solution obj;
    vector<int> ans = obj.maxSlidingWindow(v, 3);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}