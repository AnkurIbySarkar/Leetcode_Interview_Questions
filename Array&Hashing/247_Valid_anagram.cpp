#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution
{
public:
    // int linearSearch(string s, char c)
    // {
    //     for (int i = 0; i < s.length(); i++)
    //     {
    //         if (s[i] == c)
    //         {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    // bool isAnagram(string s, string t)
    // {
    //     if (s.length() != t.length())
    //     {
    //         return false;
    //     }
    //     for (int i = 0; i < s.length(); i++)
    //     {
    //         int pos = linearSearch(t, s[i]);
    //         if (pos == -1)
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    bool isAnagram(string s, string t)
    {
        vector<int> ans(26, 0);
        if (s.length() != t.length())
        {
            return false;
        }
        for (int i = 0; i < s.length(); i++)
        {
            ans[s[i] - 'a'] += 1;
            ans[s[i] - 'a'] -= 1;
        }
        for (auto i : ans)
        {
            if (i != 0)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution obj;
    bool ans = obj.isAnagram("anagram", "nagaram");
    if (ans == 1)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}