class Solution {
public:
    
    vector<vector<int>>dp;

    int solve (int i, bool prev_swapped, vector<int>& nums1, vector<int>& nums2){

        if(i == nums1.size()) return 0;

        if(dp[i][prev_swapped] != -1) return dp[i][prev_swapped];

        int prev1 = -1;
        int prev2 = -1;

        if(i > 0){
            if(prev_swapped){
                prev1 = nums2[i-1];
                prev2 = nums1[i-1];
            }

            else{
                prev1 = nums1[i-1];
                prev2 = nums2[i-1];
            }
        }

        int res = INT_MAX;

        if(nums1[i] > prev1 && nums2[i] > prev2){ // may or may not swap

            res = min(res, solve(i+1, false, nums1, nums2));
        }

        if(nums1[i] > prev2 && nums2[i] > prev1){ // this condition is must, when we have to swap;

            res = min(res, 1+solve(i+1, true, nums1, nums2));
        }   

        return dp[i][prev_swapped] = res;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();

        dp.resize(n+1, vector<int>(2, -1));
        return solve(0, false, nums1, nums2);
    }
};