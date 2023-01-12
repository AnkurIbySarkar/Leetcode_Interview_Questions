#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        stack<pair<string, int>> st;
        st.push(make_pair("(", 1));
        while (!st.empty())
        {
            auto item = st.top();
            st.pop();

            if (item.second < 0 || item.second > n)
            {
                continue;
            }
            if (item.first.length() == 2 * n)
            {
                if (item.second == 0)
                {
                    res.push_back(item.first);
                }
                continue;
            }
            st.push(make_pair(item.first + '(', item.second + 1));
            st.push(make_pair(item.first + ')', item.second - 1));
        }
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution obj;
    vector<string> ans = obj.generateParenthesis(n);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}