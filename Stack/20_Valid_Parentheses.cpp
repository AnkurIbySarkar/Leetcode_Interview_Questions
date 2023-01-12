#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution
{
public:
    bool isValid(string &s)
    {
        stack<char> st;
        if (s.size() == 0)
        {
            return true;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if ((s[i] == ')' && !st.empty() && st.top() == '(') ||
                     (s[i] == '}' && !st.empty() && st.top() == '{') ||
                     (s[i] == ']' && !st.empty() && st.top() == '['))
            {
                st.pop();
            }

            else
            {
                return false;
            }
        }
        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    string s = {"()[]{}"};
    Solution obj;
    bool ans = obj.isValid(s);
    if (ans == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}