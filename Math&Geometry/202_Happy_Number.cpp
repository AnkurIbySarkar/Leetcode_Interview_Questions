#include <iostream>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    // bool isHappy(int n) {
    //     for(int i=0;i<=10;i++){
    //         int x=n;
    //         n=0;
    //         while(x!=0){
    //             n+=((x%10)*(x%10));
    //             x/=10;
    //         }
    //         if(n==1){
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // set
    bool isHappy(int n)
    {
        unordered_set<int> myset;
        int val;
        int index;
        while (1)
        {
            val = 0;
            while (n)
            {
                index = n % 10;
                val += index * index;
                n = n / 10;
            }
            if (val == 1)
            {
                return true;
            }
            else if (myset.find(val) != myset.end())
            {
                return false;
            }
            myset.insert(val);
            n = val;
        }
        return false;
    }
};
int main()
{
    int n = 19;
    Solution obj;
    bool ans = obj.isHappy(n);
    if (ans == 1)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}