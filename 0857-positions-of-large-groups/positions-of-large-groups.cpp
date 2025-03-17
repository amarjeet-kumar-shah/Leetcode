class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int ch=s[0];
        vector<vector<int>>ans;
        if(s.size()<3)
        {
            return ans;
        }
        for(int i=1;i<s.size();i++)
        {
            if(ch==s[i])
            {
                int index=i-1;
                int c=1;
                while(ch==s[i])
                {
                    c++;
                    i++;
                }
                if(c>=3)
                {
                    ans.push_back({index,i-1});
                }
                
            }
            ch=s[i];
        }

        return ans;
    }
};