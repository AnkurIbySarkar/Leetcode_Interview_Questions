#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // int trap(vector<int> &height)
    // {
    //     int n = height.size();
    //     int watertrapped = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         int j = i;
    //         int leftmax = 0, rightmax = 0;
    //         while (j >= 0)
    //         {
    //             leftmax = max(leftmax, height[j]);
    //             j--;
    //         }
    //         j = i;
    //         while (j < n)
    //         {
    //             rightmax = max(rightmax, height[j]);
    //             j++;
    //         }
    //         watertrapped += min(leftmax, rightmax) - height[i];
    //     }
    //     return watertrapped;
    // }

    // O(3N), space - O(2N)
    // int trap(vector<int> &height)
    // {
    //     int n = height.size();
    //     int prefix[n], suffix[n];
    //     prefix[0] = height[0];
    //     for (int i = 1; i < n; i++)
    //     {
    //         prefix[i] = max(prefix[i - 1], height[i]);
    //     }
    //     suffix[n - 1] = height[n - 1];
    //     for (int i = n - 2; i >= 0; i--)
    //     {
    //         suffix[i] = max(suffix[i + 1], height[i]);
    //     }
    //     int watertrapped = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         watertrapped += min(suffix[i], prefix[i]) - height[i];
    //     }
    //     return watertrapped;
    // }

    // time - O(N) space - O(1)
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0, right = n - 1;
        int res = 0;
        int leftmax = 0, rightmax = 0;
        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= leftmax)
                {
                    leftmax = height[left];
                }
                else
                {
                    res += leftmax - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] >= rightmax)
                {
                    rightmax = height[right];
                }
                else
                {
                    res += rightmax - height[right];
                }
                right--;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution obj;
    int ans = obj.trap(v);
    cout << ans;
}