class Solution {
public:
    int findIntegers(int n) {
        vector<int> bits;
        while (n) {
            bits.push_back(n & 1);
            n /= 2;
        }

        int dp[32][2][2];
        memset(dp, -1, sizeof(dp));

        function<int(int, int, bool)> f = [&](int idx, int last, bool tight) {
            if (idx == -1) {
                return 1;
            }
            
            int& mem = dp[idx][last][tight];
            if (mem != -1) {
                return mem;
            }
            
            int res = 0, limit = tight ? bits[idx] : 1;
            for (int bit = 0; bit <= limit; bit++) {
                if (last != 1 || bit != 1) {
                    res += f(idx - 1, bit, tight && (bit == limit));
                }
            }
            return mem = res;
        };

        return f(bits.size() - 1, 0, 1);
    }
};