/* Leetcode Link : https://leetcode.com/problems/evaluate-reverse-polish-notation/ */

class Solution
{
public:
    int solve(int a, int b, string s)
    {
        if (s[0] == '+')
            return b + a;
        if (s[0] == '-')
            return b - a;
        if (s[0] == '*')
            return b * a;
        return b / a;
    }

    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        stack<string> st;
        for (int i = 0; i < n; i++)
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                st.push(tokens[i]);
            }
            else
            {
                string first = st.top();
                st.pop();
                string second = st.top();
                st.pop();
                int temp_ans = solve(stoi(first), stoi(second), tokens[i]);
                // cout<<temp<<endl;
                st.push(to_string(temp_ans));
            }
        }
        int ans = stoi(st.top());
        return ans;
    }