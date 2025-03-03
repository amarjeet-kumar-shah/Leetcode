class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> dl;
        vector<string> ll;
        vector<string> ans;
        for(int i = 0; i < logs.size(); i++){
            int index = logs[i].find(" ") + 1;
            if(logs[i].at(index) >= '0' && logs[i].at(index) <= '9'){
                dl.push_back(logs[i]);
            }
            else{
                ll.push_back(logs[i]);
            }
        }

        sort(ll.begin(), ll.end(), [](const string &a, const string &b){
            int pos1 = a.find(" ") + 1;
            int pos2 = b.find(" ") + 1;

            string contentA = a.substr(pos1);
            string contentB = b.substr(pos2);

            if(contentA == contentB)
                return a < b;
            
            return contentA < contentB;
        });

        for(auto it : ll){
            ans.push_back(it);
        }

        ans.insert(ans.end(), dl.begin(), dl.end());

        return ans;

    }
};