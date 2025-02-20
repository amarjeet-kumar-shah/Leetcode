class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_num = *min_element(nums.begin(), nums.end());
        int max_num = *max_element(nums.begin(), nums.end());

        if ((max_num - min_num) - (2 * k) <= 0 || max_num - min_num == 0)
            return 0;
        else
            return (max_num - min_num) - (2 * k);
    }
};