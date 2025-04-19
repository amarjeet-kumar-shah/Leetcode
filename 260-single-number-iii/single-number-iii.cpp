class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> arr;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1) {
                if (nums[i] == nums[i - 1]) {
                    break;
                } 
                else {
                    arr.push_back(nums[i]);
                    break;
                }
            }
            if (nums[i] == nums[i + 1]) {
                i += 1;
            } 
            else {
                arr.push_back(nums[i]);
            }
        }
        return arr;
    }
};