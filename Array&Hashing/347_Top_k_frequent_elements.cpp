#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (auto i : mp)
        {
            q.push({i.second, i.first});
            if (q.size() > k)
            {
                q.pop();
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
int main()
{
    vector<int> v = {1, 1, 1, 2, 2, 3};
    Solution obj;
    vector<int> ans = obj.topKFrequent(v, 2);
    cout << "[";
    for (auto i : ans)
    {
        cout << i << ",";
    }
    cout << "]";
}