class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size(), area = 0;
        vector<int> x_v(n), y_v(n);
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                int v = grid[x][y];
                if (v) {
                    area++;
                    if (x_v[x] < v) x_v[x] = v;
                    if (y_v[y] < v) y_v[y] = v;
                }
            }
            area += x_v[x];
        }
        for (int y = 0; y < n; y++)
            area += y_v[y];
        return area;
    }
};