#include <iostream>
#include <stack>
#include <climits>
using namespace std;
// class MinStack
// {
//     stack<pair<int, int>> st;

// public:
// MinStack()
// {
// }

// void push(int val)
// {
//     int min;
//     if (st.empty())
//     {
//         min = val;
//     }
//     else
//     {
//         min = std::min(st.top().second, val);
//     }
//     st.push({val, min});
// }

// void pop()
// {
//     st.pop();
// }

// int top()
// {
//     return st.top().first;
// }

// int getMin()
// {
//     return st.top().second;
// }

// O(1) space O(1)
// };

class MinStack
{
    stack<long long> st;
    long long mini;

public:
    MinStack()
    {
        while (!st.empty())
        {
            st.pop();
        }
        mini = INT_MAX;
    }

    void push(int value)
    {
        long long val = value;
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val < mini)
            {
                st.push(2 * val * 1LL - mini);
                mini = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        long long el = st.top();
        st.pop();
        if (el < mini)
        {
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        long long el = st.top();
        if (el < mini)
        {
            return mini;
        }
        return el;
    }

    int getMin()
    {
        return mini;
    }
};
int main()
{
    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int param_2 = obj->getMin();
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    cout << param_2 << endl;
    cout << param_3 << endl;
    cout << param_4 << endl;
}