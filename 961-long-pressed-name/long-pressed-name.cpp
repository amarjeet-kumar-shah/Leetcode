#pragma GCC optimize("Ofast")

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
};

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        // Vectors to store character and consecutive count pairs for name and typed
        vector<pair<char,int>> namearr;
        vector<pair<char,int>> typedarr;
        
        // Count consecutive characters for 'name'
        int cnt = 1;
        for (int i = 0; i < name.size() - 1; i++) {
            if (name.at(i) == name.at(i + 1)) {
                cnt++;
            } else {
                namearr.push_back(make_pair(name.at(i), cnt));
                cnt = 1;
            }
        }
        // Add the last character and its count
        namearr.push_back(make_pair(name.at(name.size() - 1), cnt));
        
        // Reset count for 'typed'
        cnt = 1;
        for (int i = 0; i < typed.size() - 1; i++) {
            if (typed.at(i) == typed.at(i + 1)) {
                cnt++;
            } else {
                typedarr.push_back(make_pair(typed.at(i), cnt));
                cnt = 1;
            }
        }
        // Add the last character and its count
        typedarr.push_back(make_pair(typed.at(typed.size() - 1), cnt));
        
        // Check if both vectors have the same size
        if (typedarr.size() != namearr.size()) {
            return false;
        }
        
        // Compare characters and their counts
        for (int k = 0; k < namearr.size(); k++) {
            if (namearr.at(k).first != typedarr.at(k).first || namearr.at(k).second > typedarr.at(k).second) {
                return false;
            }
        }
        
        return true;
    }
};