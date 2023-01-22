#include <iostream>
#include <unordered_map>
#include <cstring>
#include <string>
using namespace std;
class TimeMap
{
public:
    // unordered_map<string, string> ump;
    // TimeMap()
    // {
    // }

    // void set(string key, string value, int timestamp)
    // {
    //     ump[key + to_string(timestamp)] = value;
    // }

    // string get(string key, int timestamp)
    // {
    //     for (int i = timestamp; i >= 0; i--)
    //     {
    //         if (ump[key + to_string(i)] != "")
    //         {
    //             return ump[key + to_string(i)];
    //         }
    //     }
    //     return "";
    // }

    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (mp.find(key) == mp.end())
            return "";
        int low = 0, high = mp[key].size() - 1;
        if (mp[key][0].first > timestamp)
            return "";
        string ans = "";
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mp[key][mid].first == timestamp)
                return mp[key][mid].second;
            if (mp[key][mid].first > timestamp)
                high = mid - 1;
            else
            {
                ans = mp[key][mid].second;
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{

    string key = "foo";
    string value = "bar";
    int timestamp = 1;
    TimeMap *obj = new TimeMap();
    obj->set(key, value, timestamp);
    string param_2 = obj->get(key, timestamp);
    cout << param_2;
}