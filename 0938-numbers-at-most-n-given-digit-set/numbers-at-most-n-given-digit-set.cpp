class Solution {
private:
    int dp[11][2][2];
    
    int solve(string &R,int n,bool tight,bool isLeading,vector<int>& digits){
        if(n == 0) return 1;
        
        if(dp[n][tight][isLeading] != - 1) return dp[n][tight][isLeading];
        
        int ub = tight ? (R[R.length() - n] - '0') : 9;
        int ans = 0;
        
        if(isLeading){
            ans += solve(R,n - 1,0,1,digits);
        }   
        for(int dig : digits){
            if(dig <= ub)
                ans += solve(R,n - 1,(tight & (dig == ub)),0,digits);
        }

        return dp[n][tight][isLeading] = ans;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        vector<int> temp;
        for(string s : digits)
            temp.push_back(stoi(s));
        
        string R = to_string(n);
        memset(dp,-1,sizeof(dp));
        
        return solve(R,R.length(),1,1,temp) - 1;
    }
};