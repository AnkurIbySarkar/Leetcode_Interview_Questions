#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    // int maxArea(vector<int> &height)
    // {
    //     int mx = INT_MIN;
    //     for (int i = 0; i < height.size(); i++)
    //     {
    //         for (int j = i + 1; j < height.size(); j++)
    //         {
    //             int water = (j - i) * min(height[i], height[j]);
    //             mx = max(water, mx);
    //         }
    //     }
    //     return mx;
    // }

    // two pointer approach
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1, mx = INT_MIN;
        while (i < j)
        {
            int water = (j - i) * min(height[i], height[j]);
            mx = max(mx, water);
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return mx;
    }
};
int main()
{
    vector<int> v{1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution obj;
    int ans = obj.maxArea(v);
    cout << ans;
}