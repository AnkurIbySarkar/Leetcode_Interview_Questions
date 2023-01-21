#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    // O(N*M)+O(N*M)
    //  void setZeroes(vector<vector<int>> &matrix)
    //  {
    //      int rows = matrix.size(), cols = matrix[0].size();
    //      for (int i = 0; i < rows; i++)
    //      {
    //          for (int j = 0; j < cols; j++)
    //          {
    //              if (matrix[i][j] == 0)
    //              {

    //                 int ind = i - 1;
    //                 while (ind >= 0)
    //                 {
    //                     if (matrix[ind][j] != 0)
    //                     {
    //                         matrix[ind][j] = -1;
    //                     }
    //                     ind--;
    //                 }
    //                 ind = i + 1;
    //                 while (ind < rows)
    //                 {
    //                     if (matrix[ind][j] != 0)
    //                     {
    //                         matrix[ind][j] = -1;
    //                     }
    //                     ind++;
    //                 }
    //                 ind = j - 1;
    //                 while (ind >= 0)
    //                 {
    //                     if (matrix[i][ind] != 0)
    //                     {
    //                         matrix[i][ind] = -1;
    //                     }
    //                     ind--;
    //                 }
    //                 ind = j + 1;
    //                 while (ind < cols)
    //                 {
    //                     if (matrix[i][ind] != 0)
    //                     {
    //                         matrix[i][ind] = -1;
    //                     }
    //                     ind++;
    //                 }
    //             }
    //         }
    //     }
    //     for (int i = 0; i < rows; i++)
    //     {
    //         for (int j = 0; j < cols; j++)
    //         {
    //             if (matrix[i][j] <= 0)
    //             {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    // O(N*M+N*M)
    // void setZeroes(vector<vector<int>> &matrix)
    // {
    //     int row = matrix.size();
    //     int col = matrix[0].size();
    //     vector<int> dummy1(row, -1), dummy2(col, -1);
    //     for (int i = 0; i < row; i++)
    //     {
    //         for (int j = 0; j < col; j++)
    //         {
    //             if (matrix[i][j] == 0)
    //             {
    //                 dummy1[i] = 0;
    //                 dummy2[j] = 0;
    //             }
    //         }
    //     }
    //     for (int i = 0; i < row; i++)
    //     {
    //         for (int j = 0; j < col; j++)
    //         {
    //             if (dummy1[i] == 0 || dummy2[j] == 0)
    //             {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    // O(2*(N*M))
    void setZeroes(vector<vector<int>> &matrix)
    {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
            if (col0 == 0)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
int main()
{
    vector<vector<int>> arr{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    Solution obj;
    obj.setZeroes(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}