class Solution {
public:
    int rotatedDigits(int n) {
        /* 
            2 3 1
            dp[0] = 0
            dp[1] = 0
            dp[2] = 1
            dp[3] = 0
            dp[5] = 1
            dp[10] = dp[1] & dp[0];
            dp[11] = dp[1] & dp[1];
        */
        vector<int> dp(max(n+1, 11), 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 3;
        dp[5] = 3;
        dp[6] = 3;
        dp[8] = 1;
        dp[9] = 3;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            if(dp[i/10] & dp[i%10]) {
                dp[i] = dp[i/10]| dp[i%10];
            }
            if(dp[i] == 3) {
                sum++;
            }
        }
        return sum;
    }
};