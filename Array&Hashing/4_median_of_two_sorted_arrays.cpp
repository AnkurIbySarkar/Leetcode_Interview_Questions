#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> v;
//         for(auto nums:nums1){
//             v.push_back(nums);
//         }
//         for(auto nums:nums2){
//             v.push_back(nums);
//         }
//         sort(v.begin(),v.end());
//         int n = v.size();
//         return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
//     }
// };


// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         double ans = 0;
//         int i=0 , j=0 , m=nums1.size() , n=nums2.size();
//         vector<int> temp;
//         while(i<m && j<n){
//             if(nums1[i]<nums2[j]) {
//             temp.push_back(nums1[i++]);
//             }
//             else {
//                 temp.push_back(nums2[j++]);
//             }    
//         }
//         if(i!=m){
//             while(i<m) 
//             temp.push_back(nums1[i++]);
//         }
//         else if(j!=n){ 
//             while(j<n) 
//             temp.push_back(nums2[j++]);
//         }
//         if((m+n)%2 != 0){
//             ans = temp[(m+n)/2];
//         }
//         else {
//             ans = (temp[(m+n)/2] + temp[(m+n)/2-1])/2.0;
//         }
//         return ans;
//     }
// };



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0;
        int high = n1;
        while(low<=high){
            int cut1 = (low+high)/2;
            int cut2 = (n1+n2+1)/2 -cut1;

            int left1 = cut1 == 0?INT_MIN:nums1[cut1-1];
            int left2 = cut2 == 0? INT_MIN:nums2[cut2-1];

            int right1 = cut1 == n1? INT_MAX:nums1[cut1];
            int right2 = cut2 == n2? INT_MAX:nums2[cut2];

            if(left1<=right2 && left2 <=right1){
                if((n1+n2)%2==0){
                    return (max(left1,left2) + min(right1,right2))/2.0;
                }
                else{
                    return max(left1,left2);
                }
            }
            else if(left1>right2){
                high = cut1-1;
            }
            else{
                low = cut1+1;
            }
        }
        return 0.0;
    }
};
int main(){
    Solution obj;
    vector<int> v1{1,3};
    vector<int> v2{2};
    double ans = obj.findMedianSortedArrays(v1,v2);
        cout<<ans;
}