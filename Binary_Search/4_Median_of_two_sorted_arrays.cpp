#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    // double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    // {
    //     int n1 = nums1.size();
    //     int n2 = nums2.size();
    //     int i = 0;
    //     int j = 0;
    //     int lastindex = -1;

    //     // Initialize a new array
    //     vector<int> v(n1 + n2, 0);

    //     while (i < n1 && j < n2)
    //     {
    //         if (nums1[i] <= nums2[j])
    //             v[++lastindex] = nums1[i++];
    //         else
    //             v[++lastindex] = nums2[j++];
    //     }

    //     while (i < n1)
    //         v[++lastindex] = nums1[i++];
    //     while (j < n2)
    //         v[++lastindex] = nums2[j++];

    //     // Return the result
    //     int n = n1 + n2;
    //     return n % 2 ? v[n / 2] : (v[n / 2] + v[n / 2 - 1]) / 2.0;
    // }

    // space - O(1)
    // double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    // {
    //     int n1 = nums1.size();
    //     int n2 = nums2.size();
    //     int n = n1 + n2;

    //     // Edge Cases
    //     if (n2 == 0)
    //         return n1 % 2 ? nums1[n1 / 2] : (nums1[n1 / 2 - 1] + nums1[n1 / 2]) / 2.0;
    //     if (n1 == 0)
    //         return n2 % 2 ? nums2[n2 / 2] : (nums2[n2 / 2 - 1] + nums2[n2 / 2]) / 2.0;

    //     // Resize the array 'nums1': O(N), N is size of resized array
    //     nums1.resize(n);

    //     // Now use pointer to compare arrays elements
    //     int i = 0;
    //     int j = 0;

    //     // Store all element in 'array 1' in sorted order
    //     while (i < n1) // O(n1)
    //     {
    //         if (nums1[i] > nums2[0])
    //         {
    //             swap(nums1[i], nums2[0]); // O(1)
    //             // Rearrange Array nums2
    //             rearrangeArray(nums2); // O(n2)
    //         }
    //         i++;
    //     }

    //     // Store remaining elements of 'array 2' in 'array 1'
    //     while (j < nums2.size()) // O(n2)
    //         nums1[i++] = nums2[j++];

    //     // Return Result
    //     return n % 2 ? nums1[n / 2] : (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
    // }

    // void rearrangeArray(vector<int> &nums2)
    // {
    //     // Using insertion sort for insertion
    //     // worst case Time Complexity Would be: O(n)
    //     for (int i = 1; i < nums2.size() && nums2[i] < nums2[i - 1]; i++)
    //         swap(nums2[i], nums2[i - 1]);
    // }

    // O(log(m*n))
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        int low = 0, high = m;
        while (low <= high)
        {
            int cut1 = (low + high) >> 1;
            int cut2 = ((m + n) + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((m + n) % 2 != 0)
                {
                    return max(l1, l2);
                }
                else
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return 0.0;
    }
};
int main()
{
    vector<int> v1{1, 2};
    vector<int> v2{3, 4};
    Solution obj;
    double ans = obj.findMedianSortedArrays(v1, v2);
    cout << ans;
}