

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int i = 0, j = 0;

        while (i - j != k) {
            while (!dq.empty() && nums[dq.front()] < nums[i]) {
                dq.pop_front();
            }
            dq.push_front(i);
            i++;
        }
        ans.push_back(nums[dq.back()]);

        while (i < nums.size()) {
            if (dq.back() == j) {
                dq.pop_back();
            }
            j++;
            while (!dq.empty() && nums[dq.front()] < nums[i]) {
                dq.pop_front();
            }
            dq.push_front(i);
            i++;
            ans.push_back(nums[dq.back()]);
        }

        return ans;
    }
};