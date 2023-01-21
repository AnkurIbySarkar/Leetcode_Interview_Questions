#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // vector<vector<int>> rotate(vector<vector<int>> &matrix)
    // {
    //     int n = matrix.size();
    //     vector<vector<int>> rotated(n, vector<int>(n, 0));
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             rotated[j][n - i - 1] = matrix[i][j];
    //         }
    //     }
    //     return rotated;
    // }

    void rotate(vector<vector<int>> &matrix)
    {
        reverse(matrix.begin(), matrix.end());
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
int main()
{
    vector<vector<int>> ans{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution obj;
    // vector<vector<int>> ans = obj.rotate(v);
    obj.rotate(ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}