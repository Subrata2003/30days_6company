/* Leetcode Link : https://leetcode.com/problems/bulls-and-cows/description/ */

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int n = secret.size(), bulls = 0, cows = 0;
        vector<int> secret_cows(10, 0), guess_cows(10, 0);
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                secret_cows[secret[i] - '0']++;
                guess_cows[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < guess_cows.size(); i++)
        {
            cows += min(guess_cows[i], secret_cows[i]);
        }
        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};