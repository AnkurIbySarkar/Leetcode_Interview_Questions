#include<iostream>
#include<unordered_map>
#include<climits>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

// int solve(string str) {

//   if(str.size()==0)
//       return 0;
//   int maxans = INT_MIN;
//   for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
//   {
//     unordered_set < int > set;
//     for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
//     {
//       if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
//       {
//         maxans = max(maxans, j - i);
//         break;
//       }
//       set.insert(str[j]);
//     }
//   }
//   return maxans;
// }

// int main() {
//   string str = "nootnoot";
//   cout << "The length of the longest substring without repeating characters is " << 
//   solve(str);
//   return 0;
// }

class Solution{
public:
    int lengthofLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};

int main() {
  string str = "noot noot";
  Solution obj;
  cout << "The length of the longest substring without repeating characters is " << obj.lengthofLongestSubstring(str);
  return 0;
}
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char,int> mp;
//         int length =0,maxlength =0,j=0;
//         for(int i =0;i<s.size();i++){
//             mp[s[i]]++;
//             length++;
//             while(mp[s[i]]>1){
//                 mp[s[j++]]--;
//                 length--;
//             }
//             maxlength = max(maxlength,length);
//         }
//         return maxlength;
//     }
// };
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//     string s;
//     cin>>s;
//     Solution obj;
//     int ans = obj.lengthOfLongestSubstring(s);
//     cout<<ans;
//     }

// }