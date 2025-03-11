class Solution {
public:
    int n;
    vector<bool> sieve;
    vector<int> prime;
    vector<vector<int>> commonFactor;
    vector<int> num_state;

    void linearSieve(int n) {
        sieve.assign(n + 1, false);
        prime.reserve((int)(n/log(n)));// Use Prime Number Theory
        for (int i = 2; i <= n; i++) {
            if (!sieve[i]) prime.push_back(i); // When not sieved, i is a prime
            for (int j = 0; i * prime[j] <= n; j++) {
                sieve[i * prime[j]] = true;
                if (i % prime[j] == 0) break;
            }
        }
    }

    void build_commonFactor_path(vector<int>& nums, int M) {
        num_state.assign(M + 1, 0);
        commonFactor.resize(M + 1, vector<int>());

        for (int x : nums)
            num_state[x] = 1;

        for (int p : prime) {//Probably M/log(M) primes
            if (num_state[p] != 1)
                num_state[p] = -1;

            for (int i = p * 2; i <= M; i += p) {
                if (num_state[i] == 1) {
                    commonFactor[i].push_back(p);
                    commonFactor[p].push_back(i);
                }
            }
        }
    }

    void dfs(int i, int& sz) {
        if (num_state[i] == 1)
            sz++;
        num_state[i] = 2;

        for (int x : commonFactor[i]) {
            if (num_state[x] == 1 || num_state[x] == -1) {
                dfs(x, sz);
            }
        }
    }

    int largestComponentSize(vector<int>& nums) {
        n = nums.size();
        int M = *max_element(nums.begin(), nums.end());
        linearSieve(M);
        build_commonFactor_path(nums, M);
        int ans = 0;
        for (int i : nums) {
            if (num_state[i] == 1) {
                int sz = 0;
                dfs(i, sz);
                ans = max(ans, sz);
            }
        }
        return ans;
    }
};
