class Solution {
public:
    int numJewelsInStones(string j, string s) {

        unordered_map<char,int> m1;
        unordered_map<char,int> m2;

        for(auto it:j){
            m1[it]++;
        }

        for(auto it:s){
            m2[it]++;
        }
        int cnt =0;
        for(auto it:m2){
            if(m1.find(it.first) != m1.end()){
                cnt = cnt + it.second;
 
            }
        }
        return cnt;
    }
};