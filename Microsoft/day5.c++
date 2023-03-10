class Solution 
{
public:
    int dp[100001];
    bool flag = false;
    int minimumRounds(vector<int>& tasks)
    {
     
        {
            dp[0] = INT_MAX/2;dp[1] = INT_MAX/2;
            dp[2] = 1;dp[3] = 1;
            for(int i = 4;i<=100000;i++)
                dp[i] = min(dp[i-2],dp[i-3]) + 1;
            flag = true;
        }
        int ans = 0;
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            if(it->second == 1)
                return -1;
            ans += dp[it->second];
        }
        return ans;
    }
};
