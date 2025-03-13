class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ret = 0;
        vector<int> sorted(strs.size(), 0); 
        for (int j = 0; j < strs[0].size(); ++j) {
            bool deletion = false;
            for (int i = 0; i < strs.size() - 1; ++i) {
                if (!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                    deletion = true;
                    ++ret;
                    break;
                }
            }
            if (deletion) {
                continue;
            }
            for (int i = 0; i < strs.size() - 1; ++i) {
                sorted[i] |= (strs[i][j] < strs[i + 1][j]);
            }
        }
        return ret;
    }
};