class Solution {
public:
    string reverseStr(string s, int k) {
        int pos = 0;
        int n = s.length();
        while (pos < n) {
            int i = pos;
            int j = min(pos + k - 1, n - 1);
            while (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }

            pos += 2 * k;
        }
        return s;
    }
};