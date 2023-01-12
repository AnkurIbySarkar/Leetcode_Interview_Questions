#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
class Solution
{
public:
    // sort in nlogn
    //  bool containsDuplicate(vector<int> &nums)
    //  {
    //      sort(nums.begin(), nums.end());
    //      for (int i = 0; i < nums.size() - 1; i++)
    //      {
    //          if (nums[i] == nums[i + 1])
    //          {
    //              return true;
    //          }
    //      }
    //      return false;
    //  }

    // unordered_map
    //  bool containsDuplicate(vector<int> &nums)
    //  {
    //      unordered_map<int, int> mpp;
    //      for (int i : nums)
    //      {
    //          mpp[i]++;
    //      }
    //      for (auto i : mpp)
    //      {
    //          if (i.second > 1)
    //          {
    //              return true;
    //          }
    //      }
    //      return false;
    //  }

    // set
    bool containsDuplicate(vector<int> &nums)
    {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};
int main()
{
    vector<int> v = {1, 2, 4, 1};
    Solution obj;
    int ans = obj.containsDuplicate(v);
    if (ans == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}