/* Leetcode Link : https://leetcode.com/problems/rotate-function/description/ */

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        int curr_state = 0;
        for (int i = 0; i < n; i++)
            curr_state += i * nums[i];
        int ans = curr_state;
        for (int i = n - 1; i >= 0; i--)
        {
            curr_state += (sum - (n * nums[i]));
            ans = max(ans, curr_state);
        }
        return ans;
    }
};