#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution
{
public:
    // int maxProfit(vector<int> &prices)
    // {
    //     int ans = 0;
    //     for (int i = 0; i < prices.size(); i++)
    //     {
    //         for (int j = i + 1; j < prices.size(); j++)
    //         {
    //             if (prices[j] > prices[i])
    //             {
    //                 ans = max(prices[j] - prices[i], ans);
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // O(n)
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        int minprice = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            {
                minprice = min(prices[i], minprice);
                ans = max(ans, prices[i] - minprice);
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> v{7, 1, 5, 3, 6, 4};
    Solution obj;
    int ans = obj.maxProfit(v);
    cout << ans;
}