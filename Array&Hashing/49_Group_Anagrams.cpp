#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // int n = strs.size();
        // if (n == 0)
        // {
        //     return {{""}};
        // }
        // vector<vector<string>> ans;
        // unordered_set<int> st;
        // for (int i = 0; i < n; i++)
        // {
        //     if (!st.empty() && st.find(i) != st.end())
        //         continue;
        //     vector<string> grp;
        //     vector<int> c1(26, 0);
        //     for (char c : strs[i])
        //     {
        //         c1[c - 'a']++;
        //     }
        //     for (int j = i; j < n; j++)
        //     {
        //         vector<int> c2(26, 0);
        //         for (char c : strs[i])
        //             c2[c - 'a']++;
        //         if (c1 == c2)
        //         {
        //             grp.push_back(strs[j]);
        //             st.insert(j);
        //         }
        //     }
        //     ans.push_back(grp);
        // }
        // return ans;

        // sorted O(n logn)
        //  unordered_map<string, vector<string>> mp;
        //  vector<vector<string>> res;
        //  int n = strs.size();
        //  if (n == 0)
        //      return {{""}};
        //  for (int i = 0; i < n; i++)
        //  {
        //      string s = strs[i];
        //      sort(s.begin(), s.end());
        //      if (mp.find(s) != mp.end())
        //          mp[s].push_back(strs[i]);
        //      else
        //          mp[s] = {strs[i]};
        //  }
        //  for (auto i = mp.begin(); i != mp.end(); i++)
        //      res.push_back(i->second);
        //  return res;

        // counting sort O(N)
        int n = strs.size();
        if (n == 0)
            return {{""}};
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for (int i = 0; i < n; i++)
        {
            vector<int> count(26, 0);
            for (char c : strs[i])
                count[c - 'a']++;
            string s;
            for (int j = 0; j < 26; j++)
                if (count[j] != 0)
                    // first argument how many times, second argument ascii code for the char
                    s += string(count[j], j + 'a');
            if (mp.find(s) != mp.end())
                mp[s].push_back(strs[i]);
            else
                mp[s] = {strs[i]};
        }
        for (auto i : mp)
            res.push_back(i.second);
        return res;
    }
};
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution obj;
    vector<vector<string>> ans = obj.groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}