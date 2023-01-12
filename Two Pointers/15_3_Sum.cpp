#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // vector<vector<int>> threesum(vector<int> &nums)
    // {
    //     vector<vector<int>> ans;
    //     vector<int> temp;
    //     for (int i = 0; i < nums.size() - 2; i++)
    //     {
    //         for (int j = i + 1; j < nums.size() - 1; j++)
    //         {
    //             for (int k = j + 1; k < nums.size(); k++)
    //             {
    //                 temp.clear();
    //                 if (nums[i] + nums[j] + nums[k] == 0)
    //                 {
    //                     temp.push_back(nums[i]);
    //                     temp.push_back(nums[j]);
    //                     temp.push_back(nums[k]);
    //                 }
    //                 if (temp.size() != 0)
    //                 {
    //                     ans.push_back(temp);
    //                 }
    //             }
    //         }
    //         return ans;
    //     }
    // }

    // two pointer
    vector<vector<int>> threesum(vector<int> &num)
    {
        vector<vector<int>> res;
        sort(num.begin(), num.end());

        // moves for a
        for (int i = 0; i < (int)(num.size()) - 2; i++)
        {

            if (i == 0 || (i > 0 && num[i] != num[i - 1]))
            {

                int lo = i + 1, hi = (int)(num.size()) - 1, sum = 0 - num[i];

                while (lo < hi)
                {
                    if (num[lo] + num[hi] == sum)
                    {

                        vector<int> temp;
                        temp.push_back(num[i]);
                        temp.push_back(num[lo]);
                        temp.push_back(num[hi]);
                        res.push_back(temp);

                        while (lo < hi && num[lo] == num[lo + 1])
                            lo++;
                        while (lo < hi && num[hi] == num[hi - 1])
                            hi--;

                        lo++;
                        hi--;
                    }
                    else if (num[lo] + num[hi] < sum)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        return res;
    }
};
int main()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    Solution obj;
    vector<vector<int>> ans = obj.threesum(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}