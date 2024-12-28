class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        int max_len = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int count = 0;
                int start = i;
                while (!visited[start]) {
                    visited[start] = true;
                    start = nums[start];
                    ++count;
                }
                max_len = max(max_len, count);
            }
        }
        
        return max_len;
    }
};