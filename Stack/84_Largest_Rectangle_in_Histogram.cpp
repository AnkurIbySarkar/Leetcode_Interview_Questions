#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
using namespace std;
class Solution
{
public:
    // int largestRectangleArea(vector<int> &heights)
    // {
    //     int n = heights.size();
    //     int maxArea = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         int minheight = INT_MAX;
    //         for (int j = i; j < n; j++)
    //         {
    //             minheight = min(minheight, heights[j]);
    //             maxArea = max(maxArea, minheight * (j - i + 1));
    //         }
    //     }
    //     return maxArea;
    // }

    // time - O(N) space - O(3N)
    // int largestRectangleArea(vector<int> &heights)
    // {
    //     int n = heights.size();
    //     int leftsmall[n], rightsmall[n];
    //     stack<int> st;

    //     for (int i = 0; i < n; i++)
    //     {
    //         while (!st.empty() && heights[st.top()] >= heights[i])
    //         {
    //             st.pop();
    //         }
    //         if (st.empty())
    //         {
    //             leftsmall[i] = 0;
    //         }
    //         else
    //             leftsmall[i] = st.top() + 1;
    //         st.push(i);
    //     }

    //     while (!st.empty())
    //     {
    //         st.pop();
    //     }
    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         while (!st.empty() && heights[st.top()] >= heights[i])
    //         {
    //             st.pop();
    //         }
    //         if (st.empty())
    //         {
    //             rightsmall[i] = n - 1;
    //         }
    //         else
    //             rightsmall[i] = st.top() - 1;
    //         st.push(i);
    //     }
    //     int maxA = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         int curr = heights[i] * (rightsmall[i] - leftsmall[i] + 1);
    //         maxA = max(maxA, curr);
    //     }
    //     return maxA;
    // }

    // time - O(N)+O(N) space - O(N)
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        int maxA = 0;
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width = 0;
                if (st.empty())
                {
                    width = i;
                }
                else
                {
                    width = i - st.top() - 1;
                }
                maxA = max(maxA, height * width);
            }
            st.push(i);
        }
        return maxA;
    }
};
int main()
{
    vector<int> v{2, 1, 5, 6, 2, 3, 1};
    Solution obj;
    int ans = obj.largestRectangleArea(v);
    cout << ans;
}