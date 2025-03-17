
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right){
        int count = 0, leftIndex = -1, lastValidIndex = -1;
        // lastvalidexIndex means the end 
        int n = nums.size();
        for (int i = 0; i <n;i++){// dry run this example  [2,9,2,5,6]
            if (nums[i] > right){// if 9 greater that right means it is not satisfying the condtion so valid index will be starting from ther updated to leftindex = i 
                leftIndex = i;  // dry run this example  [2,9,2,5,6]
                // lastValidIndex is not updated because nums[1] is out of range. 
            }
            if(nums[i] >= left && nums[i] <= right){
                lastValidIndex = i;
            }
            if(lastValidIndex > leftIndex){
                count += (lastValidIndex - leftIndex);
            }
        }
        return count;
    }
};