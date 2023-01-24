#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        vector<int> freq(26, 0);
        int max_freq = 0;
        int ans = -1;
        int low = 0, high = 0;
        while (high < n)
        {
            freq[s[high] - 'A']++;
            max_freq = max(max_freq, freq[s[high] - 'A']);
            while ((high - low + 1) - k > max_freq)
            {
                freq[s[low] - 'A']--;
                low++;
            }
            ans = max(ans, (high - low + 1));
            high++;
        }
        return ans;
    }
};

int main()
{
    string s = "AABABBA";
    Solution obj;
    int ans = obj.characterReplacement(s, 1);
    cout << ans;
}