/* Leetcode Link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/ */

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        int i = 0, j = 0, count = 0;
        map<char, int> mp;
        while (j <= n)
        {
            mp[s[j]]++;
            while (mp['a'] && mp['b'] && mp['c'])
            {

                //main_line
                count += 1 + (n - 1 - j);

                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
    }
};