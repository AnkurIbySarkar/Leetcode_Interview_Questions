#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // int minEatingSpeed(vector<int> &piles, int h)
    // {
    //     int maxi = *max_element(piles.begin(), piles.end());
    //     int n = piles.size();
    //     int k = 1;
    //     while (1)
    //     {
    //         int totTime = 0;
    //         for (auto pile : piles)
    //         {
    //             totTime += ceil(pile / float(k));

    //             if (totTime > h)
    //                 break;
    //         }
    //         if (totTime <= h)
    //         {
    //             return k;
    //         }
    //         else
    //         {
    //             k += 1;
    //         }
    //     }
    //     return k;
    // }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxi = *max_element(piles.begin(), piles.end());
        int low = 1;
        int high = maxi;
        int mid;
        while (low <= high)
        {
            long long int cnt = 0;
            mid = low + (high - low) / 2;
            for (int i = 0; i < piles.size(); i++)
            {
                if (piles[i] < mid)
                {
                    cnt++;
                }
                else
                {
                    cnt += ((piles[i] / mid) + (piles[i] % mid != 0));
                }
            }
            if (cnt > h)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main()
{
    vector<int> v{3, 6, 7, 11};
    Solution obj;
    int ans = obj.minEatingSpeed(v, 8);
    cout << ans;
}