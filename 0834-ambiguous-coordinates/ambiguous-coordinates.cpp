class Solution {
public:
	// issecword denotes if it is the second word (the part after the decimal)
    bool check(string s, bool issecword)
    {
        int n=s.length();
		// Logic explained above
        if(issecword){
            if(n>0 && s[n-1]=='0') return false;
        }
        else{
            if(n>1 && s[0]=='0') return false;
        }
        return true;
    }

    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        S=S.substr(1,S.length()-2);  // Remove the brackets
        int n=S.length();

        for(int i=1;i<n;i++){
            string s1=S.substr(0,i);
            string s2=S.substr(i);
            vector<string> res1, res2;
			
			// The full string without any decimal point can also be a coordinate.
			// But '01' or '001' is not possible.
            if(check(s1, false)) res1.push_back(s1);
            if(check(s2, false)) res2.push_back(s2);
			
			// First co-ordinate
            for(int j=1;j<s1.length();j++){
                string first=s1.substr(0,j);
                string second=s1.substr(j);
                if(check(first, false) && check(second, true)) res1.push_back(first+"."+second);
            }
			
			// Second co-ordinate
            for(int j=1;j<s2.length();j++){
                string first=s2.substr(0,j);
                string second=s2.substr(j);
                if(check(first, false) && check(second, true)) res2.push_back(first+"."+second);
            }
			
			// Combine all the results
            for(auto left:res1){
                for(auto right:res2){
                    res.push_back("(" + left + ", "+ right + ")");
                }
            }
        }
        return res;
    }
};