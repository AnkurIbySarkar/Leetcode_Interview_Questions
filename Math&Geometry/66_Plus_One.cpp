#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size() - 1;
        for (int i = n; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            else
            {
                digits[i] = 0;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};
int main()
{
    vector<int> v{1, 2, 3};
    Solution obj;
    vector<int> ans = obj.plusOne(v);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}