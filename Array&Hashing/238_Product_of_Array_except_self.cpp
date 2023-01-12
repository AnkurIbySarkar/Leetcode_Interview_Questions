#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    // vector<int> productExceptSelf(vector<int> &nums)
    // {
    //     vector<int> ans;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         int prod = 1;
    //         for (int j = 0; j < nums.size(); j++)
    //             if (j != i)
    //             {
    //                 prod *= nums[j];
    //             }
    //         ans.push_back(prod);
    //     }
    //     return ans;
    // }

    // O(N) space and time
    // vector<int> productExceptSelf(vector<int> &nums)
    // {
    //     vector<int> ans(nums.size(), 0);
    //     vector<int> pref(nums.size(), 0);
    //     vector<int> suff(nums.size(), 0);

    //     pref[0] = nums[0];
    //     for (int i = 1; i < nums.size(); i++)
    //     {
    //         pref[i] = pref[i - 1] * nums[i];
    //     }
    //     suff[nums.size() - 1] = nums[nums.size() - 1];
    //     for (int i = nums.size() - 2; i >= 0; i--)
    //     {
    //         suff[i] = suff[i + 1] * nums[i];
    //     }
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (i == 0)
    //         {
    //             ans[i] = suff[i + 1];
    //         }
    //         else if (i == nums.size() - 1)
    //         {
    //             ans[i] = pref[i - 1];
    //         }
    //         else
    //         {
    //             ans[i] = pref[i - 1] * suff[i + 1];
    //         }
    //     }
    //     return ans;
    // }

    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        if (n < 1)
        {
            return ans;
        }
        int product = 1;
        for (int i = 0; i < n; i++)
        {
            product *= nums[i];
            ans.push_back(product);
        }
        product = 1;
        for (int i = n - 1; i > 0; i--)
        {
            ans[i] = ans[i - 1] * product;
            product *= nums[i];
        }
        ans[0] = product;
        return ans;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4};
    Solution obj;
    vector<int> ans = obj.productExceptSelf(v);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}