#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string multiply(string &A, string &B)
    {
        if (A == "0" || B == "0")
            return "0";
        string ans(A.size() + B.size(), '0');
        for (int i = A.size() - 1; i >= 0; i--)
        {
            for (int j = B.size() - 1; j >= 0; j--)
            {
                int res = (ans[i + j + 1] - '0') + (A[i] - '0') * (B[j] - '0');
                ans[i + j + 1] = res % 10 + '0'; // ones place of multiplication result
                ans[i + j] += res / 10;          // carry over to previous index if result >= 10
            }
        }
        if (ans[0] == '0')
            return ans.substr(1);
        return ans;
    }
};
int main()
{
    string s1 = "123";
    string s2 = "456";
    Solution obj;
    string ans = obj.multiply(s1, s2);
    cout << ans;
}