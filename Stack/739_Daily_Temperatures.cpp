#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    // vector<int> dailyTemperatures(vector<int> &temperatures)
    // {
    //     vector<int> ans(temperatures.size(), 0);
    //     int n = temperatures.size();
    //     for (int i = 0; i < n; i++)
    //     {
    //         int diff = 0;
    //         for (int j = i + 1; j < n; j++)
    //         {
    //             if (temperatures[j] > temperatures[i])
    //             {
    //                 diff = j - i;
    //                 ans[i] = diff;
    //                 break;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().first < temperatures[i])
            {
                auto it = st.top();
                ans[it.second] = i - it.second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};
int main()
{
    vector<int> v{73, 74, 75, 71, 69, 72, 76, 73};
    Solution obj;
    vector<int> ans = obj.dailyTemperatures(v);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}