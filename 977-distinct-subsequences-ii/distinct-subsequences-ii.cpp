class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> dp(26);
        long long mod = 1e9 + 7;

        for (int i = 0; i < s.size(); i++) 
            dp[s[i] - 'a'] = accumulate(dp.begin(), dp.end(), 1LL) % mod;

        return accumulate(dp.begin(), dp.end(), 0LL) % mod;
    }
};