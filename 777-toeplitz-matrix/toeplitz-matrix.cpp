class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        
        map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int d = i-j+m-1;
                
				// check if diagonal already has a number asigned or not
                if(mp.find(d) != mp.end() && mp[d] != mat[i][j]) return false;
                
                mp[d] = mat[i][j];
            }
        }
        
        return true;
    }
};