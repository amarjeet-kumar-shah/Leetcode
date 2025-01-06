class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if (b == "")
            return 0;

        string result = a;
        for (int i = 1; i <= b.size() / a.size() + 2; i++) { 
            if (result.find(b) != string::npos) 
                return i;
            result += a;
        }
        return -1;
    }
};