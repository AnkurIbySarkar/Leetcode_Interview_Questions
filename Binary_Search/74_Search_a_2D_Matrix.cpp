#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // leetcode - O(m*n)
    //  bool searchMatrix(vector<vector<int>> &matrix, int target)
    //  {
    //      int m = matrix.size();
    //      int n = matrix[0].size();
    //      for (int i = 0; i < m; i++)
    //      {
    //          for (int j = 0; j < n; j++)
    //          {
    //              if (matrix[i][j] == target)
    //              {
    //                  return true;
    //              }
    //          }
    //      }
    //      return false;
    //  }

    // leetcode - O(log(m*n))
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = (n * m - 1);
        while (low <= high)
        {
            int mid = (low + (high - low) / 2);
            if (matrix[mid / n][mid % n] == target)
            {
                return true;
            }
            if (matrix[mid / n][mid % n] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }

    // gfg - O(nlogn)
    int search(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                cout << "Found at " << i << " " << j << endl;
                return 0;
            }
            else if (matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    }
};
int main()
{
    vector<vector<int>> v{
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    vector<vector<int>> g{{10, 20, 30, 40},
                          {15, 25, 35, 45},
                          {27, 29, 37, 48},
                          {32, 33, 39, 50}};
    Solution obj;
    bool ans = obj.searchMatrix(v, 3);
    if (ans == 1)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    int ans1 = obj.search(g, 29);
    cout << ans1;
    return 0;
}