class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int maxVal=0,window=0;

        for(int &i:nums){
            // Reset Everything
            if(i>maxVal){
                maxVal=i;
                window=0;
                ans=0;
            }

            if(i==maxVal) window++;
            else window=0;
            
            ans=max(ans,window);
        }
        return ans;
    }
};