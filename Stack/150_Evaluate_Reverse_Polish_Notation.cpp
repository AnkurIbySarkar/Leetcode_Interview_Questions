#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long long> st;
        for (auto letter : tokens)
        {
            if (letter == "+" || letter == "-" || letter == "*" || letter == "/")
            {
                long long num1 = st.top();
                st.pop();

                long long num2 = st.top();
                st.pop();

                char charac = letter[0];
                switch (charac)
                {
                case '+':
                    st.push(num2 + num1);
                    break;

                case '-':
                    st.push(num2 - num1);
                    break;

                case '*':
                    st.push(num2 * num1);
                    break;
                case '/':
                    st.push(num2 / num1);
                    break;

                default:
                    break;
                }
            }
            else
            {
                long long num = stoi(letter);
                st.push(num);
            }
        }
        return st.top();
    }
};
int main()
{
    vector<string> v{"2", "1", "+", "3", "*"};
    Solution obj;
    int ans = obj.evalRPN(v);
    cout << ans;
}