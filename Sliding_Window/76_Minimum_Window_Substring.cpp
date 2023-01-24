#include <iostream>
#include <map>
#include <climits>
using namespace std;
class Solution
{
public:
    //O(n^3) //O(N)
    // string minWindow(string s, string t)
    // {
    //     map<char, int> mps;
    //     map<char, int> mpt;
    //     for (int i = 0; i < t.length(); i++)
    //     {
    //         mpt[t[i]]++;
    //     }
    //     int i = 0, j = 0;
    //     int ans = INT_MAX;
    //     string str = "";
    //     while (j < s.length())
    //     {
    //         if (mpt.find(s[j]) != mpt.end())
    //         {
    //             if (mps.size() == 0)
    //                 i = j;
    //             mps[s[j]]++;
    //         }
    //         if (j - i + 1 >= t.length())
    //         {
    //             bool f = check(mpt, mps);
    //             if (f)
    //             {
    //                 mps.clear();
    //                 if (ans > j - i + 1)
    //                 {
    //                     str = makeString(i, j, s);
    //                     ans = j - i + 1;
    //                 }
    //                 j = i + 1;
    //                 i = j;
    //                 continue;
    //             }
    //         }
    //         j++;
    //     }

    //     return str;
    // }
    // bool check(map<char, int> mpt, map<char, int> mps)
    // {
    //     for (auto i : mpt)
    //     {
    //         if (mps.find(i.first) == mps.end())
    //             return false;
    //         if (mps[i.first] < i.second)
    //             return false;
    //     }
    //     return true;
    // }

    // string makeString(int i, int j, string s)
    // {
    //     string str = "";
    //     while (i <= j)
    //     {
    //         str += s[i]++;
    //         i++;
    //     }
    //     return str;
    // }


    //O(N) //O(N)
    string minWindow(string s, string t) {
        if(t.length()==0) return "";
        map<char,int> mps;
        map<char,int> mpt;
        for(int i =0;i<t.length();i++){
            mpt[t[i]]++;
        }
        int curr =0;
        int total = mpt.size();
        int res = INT_MAX;
        int i =0, j=0;
        pair<int,int> indices;
        while(j<s.length()){
            if(mpt.find(s[j])!=mpt.end()) mps[s[j]]++;
            if(mpt.find(s[j])!=mpt.end() && mps[s[j]]==mpt[s[j]]) curr++;
            while(curr==total){
                if(j-i+1<res){
                    res = j-i+1;
                    indices = make_pair(i,j);
                }
                if(mps.find(s[i])!=mps.end()) {
                    mps[s[i]]--;
                if(mps.find(s[i])!=mps.end() && mps[s[i]]<mpt[s[i]]) curr--;
            }
            i++;
        }
        j++;
        }  
            if(res==INT_MAX) return "";
            string str = "";
            for(int i=indices.first;i<=indices.second;i++){
                str +=s[i];
            }
        return str;
    }
};
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution obj;
    cout << obj.minWindow(s, t);
}