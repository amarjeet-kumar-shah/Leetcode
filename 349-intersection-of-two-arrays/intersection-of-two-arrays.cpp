class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_set<int>st(begin(nums1),end(nums1));
        unordered_set<int>st2(begin(nums2),end(nums2));

        for(auto &it:st2){
            if(st.find(it)!=st.end()){
                ans.push_back(it);
            }
        }
        return ans;
    }
};