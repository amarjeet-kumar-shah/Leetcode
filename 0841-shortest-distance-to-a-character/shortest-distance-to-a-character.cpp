
/*
// Example dry run with s = "loveleetcode", c = 'e'
// Initial state: indicesOfC = [3, 5, 6, 11], n = 12, ans = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], left = 0, right = 0
// First iteration (i = 0 to 2): No change in right, ans updates based on distance to indicesOfC[0] = 3
// Second iteration (i = 3): ans[3] = 0 (direct hit on 'e')
// Third iteration (i = 4): ans[4] = 1 (closest 'e' at index 3 or 5)
// Fourth iteration (i = 5): ans[5] = 0 (direct hit on 'e')
// Fifth iteration (i = 6): ans[6] = 0 (direct hit on 'e')
// Sixth iteration (i = 7 to 10): ans updates based on distance to nearest 'e' at indices 6 or 11
// Seventh iteration (i = 11): ans[11] = 0 (direct hit on 'e')
// Final result: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
*/
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> indicesOfC;
        int n = s.length();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == c) indicesOfC.push_back(i);
        }
        int m = indicesOfC.size();
        int left = 0;
        int right = 0;
        for (int i = 0; i < n; i++) {
            if (i > indicesOfC[right] && right < m - 1) {
                  left = right; // Left is crossed right so update left to right and right++ right moving for next neared right 'c' pos 
                right++;
            }
            if (right == left) {
                ans[i] = abs(indicesOfC[right] - i);
            } else {
                ans[i] = min(abs(indicesOfC[right] - i), abs(indicesOfC[left] - i));
            }
        }
        return ans;
    }
}; 