#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> v;
//         for(int i=0;i<nums.size();i++){
//             int k = target-nums[i];
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[j]==k){
//                     v.push_back(i);
//                     v.push_back(j);
//                     break;
//                 }
//             }
//             if(v.size()==2){
//                 break;
//             }
//         }
//         return v;
//     }
// };

// int main(){
//     Solution v2;
//     vector<int> a = {3,2,4};
//     vector<int> g = v2.twoSum(a,6);
//     for(auto i: g){
//         cout<<i<<" ";
//     }
// }

class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        int i =0,j = nums.size()-1;
        for(int i =0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        while(i<j){
            if(v[i].first+v[j].first==target){
                break;
            }
            else if(v[i].first+v[j].first<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {v[i].second,v[j].second};
    }
};

int main(){
    Solution s;
    int target;
    cin>>target;
    vector<int> v = {3,2,4};
    vector<int> ans = s.twoSum(v,target);
    for(auto i:ans){
        cout<<i<<" ";
    }
}


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> v;
//            unordered_map<int,int> m;
//             for(int i = 0;i<nums.size();i++){
//                 if(m.find(target-nums[i])!=m.end()){
//                     v.push_back(m[target-nums[i]]);
//                     v.push_back(i);
//                 }
//                 else{
//                     m[nums[i]]=i;
//                 }
//             }
//         return v;
//     }
// };


// int main(){
//      int t;
//      cin>>t;
//      while(t--){
//         int n;
//         cin>>n;
//         int a;
//         int target;
//         cin>>target;
//         Solution obj;
//         vector<int> v ;
//          for(int i =0;i<n;i++){
//              cin>>a;
//              v.push_back(a);
//          }
//     vector<int> result=obj.twoSum(v,target);
//     for(int i:result){
//         cout<<i<<" ";
//      }
//     }
//  }
