#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs)
    {
        string s = "";
        for (string &str : strs)
        {
            s += to_string(str.size()) + "@" + str;
        }
        return s;
    }

    vector<string> decode(string &str)
    {
        vector<string> vtr;
        int ptr = 0;
        while (ptr < str.size())
        {
            int pos = str.find("@", ptr);
            int len = stoi(str.substr(ptr, pos - ptr + 1));
            vtr.push_back(str.substr(pos + 1, len));
            ptr = pos + len + 1;
        }
        return vtr;
    }
};
int main()
{
    vector<string> v = {"lint", "code", "love", "you"};
    Solution obj;
    string encode = obj.encode(v);
    cout << encode << endl;
    vector<string> decode = obj.decode(encode);
    for (auto i : decode)
    {
        cout << i << " ";
    }
}