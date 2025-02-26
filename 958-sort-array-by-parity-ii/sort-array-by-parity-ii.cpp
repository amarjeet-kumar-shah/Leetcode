class Solution {
public:
    vector<int> BruteForce(vector<int>& nums) {
        int e = 0;// Pointer For even
        int o = 1;// Pointer For odd
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size();i++){
            if( nums[i]%2 == 0){
                ans[e] = nums[i];
                e += 2;
            }else{
                ans[o] = nums[i];
                o += 2;
            }
        }
        return ans;
    }

    vector<int> sortArrayByParityII(vector<int>& nums) {
       return BruteForce(nums);
       
    }
};