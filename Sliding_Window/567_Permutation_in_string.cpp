#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    // bool checkInclusion(string s1, string s2)
    // {
    //     int n = s1.length();
    //     int m = s2.length();
    //     for (int i = 0; i + n - 1 < m; i++)
    //     {
    //         if (isAnagram(s1, s2, i))
    //             return true;
    //     }

    //     return false;
    // }

    // bool isAnagram(string &s1, string &s2, int start)
    // {

    //     int table[26] = {0}, n = s1.length();
    //     for (char x : s1)
    //         table[x - 'a']++;
    //     for (int i = start; i <= start + n - 1; i++)
    //     {
    //         table[s2[i] - 'a']--;
    //     }
    //     for (int val : table)
    //     {
    //         if (val != 0)
    //             return false;
    //     }
    //     return true;
    // }

    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 > n2)
            return false;

        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (char x : s1)
            cnt1[x - 'a']++;
        for (int i = 0; i < n2; i++)
        {
            if (i >= n1)
                cnt2[s2[i - n1] - 'a']--;
            cnt2[s2[i] - 'a']++;
            if (cnt1 == cnt2)
                return true;
        }
        return false;
    }
};

int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    Solution obj;
    bool ans = obj.checkInclusion(s1, s2);
    if (ans == 0)
    {
        cout << "false";
    }
    else
    {
        cout << "true";
    }
}