#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        if (n == 1)
        {
            return true;
        }
        string str = "";
        for (int i = 0; i < n; i++)
        {
            if (isalnum(s[i]))
            {
                str += s[i];
            }
        }
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        int i = 0, j = str.size() - 1;
        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
int main()
{
    string s = "A man, a plan, a canal: Panama";
    Solution obj;
    bool ans = obj.isPalindrome(s);
    if (ans == 1)
    {
        cout << s << " is a palindrome";
    }
    else
    {
        cout << s << " is not a palindrome";
    }
}