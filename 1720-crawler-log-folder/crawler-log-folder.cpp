class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for (auto str : logs) {
            // move to parent folder
            if (str[0] == '.' && str[1] == '.') {
                // not empty
                if (!st.empty()) st.pop();
                // empty - means same at root dir
                else continue;
            }
            // curr folder
            else if (str[0] == '.' && str[1] == '/') {
                continue;
            }
            // go to further dir
            else {
                st.push(str);
            }
        }

        return st.size();
    }
};