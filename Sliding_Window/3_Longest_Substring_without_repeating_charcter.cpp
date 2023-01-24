#include <iostream>
#include <unordered_set>
#include <climits>
#include <Vector>
using namespace std;
class Solution
{
public:
    // int lengthOfLongestSubstring(string s)
    // {
    //     if (s.size() == 0)
    //         return 0;
    //     int maxans = INT_MIN;
    //     for (int i = 0; i < s.length(); i++) // outer loop for traversing the string
    //     {
    //         unordered_set<int> set;
    //         for (int j = i; j < s.length(); j++) // nested loop for getting different string starting with str[i]
    //         {
    //             if (set.find(s[j]) != set.end()) // if element if found so mark it as ans and break from the loop
    //             {
    //                 maxans = max(maxans, j - i);
    //                 break;
    //             }
    //             set.insert(s[j]);
    //         }
    //     }
    //     return maxans;
    // }

    // O(2n)
    // int lengthOfLongestSubstring(string s)
    // {
    //     int n = s.size();
    //     if (n == 0)
    //     {
    //         return 0;
    //     }
    //     int ans = INT_MIN;
    //     unordered_set<int> st;
    //     int l = 0;
    //     for (int r = 0; r < n; r++)
    //     {
    //         if (st.find(s[r]) != st.end())
    //         {
    //             while (l < r && st.find(s[r]) != st.end())
    //             {
    //                 st.erase(s[l]);
    //                 l++;
    //             }
    //         }
    //         st.insert(s[r]);
    //         ans = max(ans, r - l + 1);
    //     }
    //     return ans;
    // }

    // O(n)
    int lengthOfLongestSubstring(string s)
    {
        vector<int> mpp(256, -1);

        int left = 0, right = 0;
        int n = s.size();
        int len = 0;
        while (right < n)
        {
            if (mpp[s[right]] != -1)
            {
                left = max(left, mpp[s[right]] + 1);
            }
            mpp[s[right]] = right;
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};

int main()
{
    string s = "abcabcbb";
    Solution obj;
    int ans = obj.lengthOfLongestSubstring(s);
    cout << ans;
}