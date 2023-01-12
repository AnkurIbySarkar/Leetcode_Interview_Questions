#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int carFleet(int target, vector<int> &pos, vector<int> &speed)
    {
        vector<pair<int, int>> nums;

        for (int i = 0; i < pos.size(); i++)
        {
            nums.push_back({pos[i], speed[i]});
        }

        sort(nums.begin(), nums.end());

        stack<double> stk;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            double t = (target - nums[i].first) / ((double)nums[i].second);
            // cout << t << endl;

            if (stk.empty() || stk.top() < t)
            {
                stk.push(t);
                // cout << t << endl;
            }
        }

        return stk.size();
    }
};
int main()
{
    vector<int> pos = {10, 8, 0, 5, 3};  // 0,3,5,8,10
    vector<int> speed = {2, 4, 1, 1, 3}; // 1,3,1,4,2
    Solution obj;
    int ans = obj.carFleet(12, pos, speed);
    cout << ans;
}