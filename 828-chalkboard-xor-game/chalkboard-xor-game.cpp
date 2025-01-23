class Solution {
public:    
    bool xorGame(vector<int>& nums) {
        int xorr=0;
        int n=nums.size();

        if(n==1 && nums[0]!=0)
        return false;

        else
        {
            for(int i=0; i<n; i++)
            {
                xorr = (xorr ^ nums[i]);
            }
            if(xorr==0)
            return true;
        }

        if(n % 2 == 1)
        return false;
        else
        return true;
    }
};