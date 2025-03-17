class Solution {
public:
    vector<int> parent, size;
    int find_parent(int v) {
        //This function helps in path compresssion and finding parent
        if(parent[v] == v) {
            return v;
        }
        return parent[v] = find_parent(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_parent(a);
        b = find_parent(b);
        if (a != b) {
            if (a < b) {
                swap(a, b);
            }
            parent[a] = b;
            size[b]+=size[a];
        }
    }

    void make_set(int a) {
        parent[a] = a;
    }


    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
        parent.resize(m*n, 0);
        size.resize(m*n, 1);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                make_set(n*i + j);
            }
        }
        for(vector<int> hit : hits) {
            int x = hit[0]; int y = hit[1];
            grid[x][y]--;
        }

        vector<int> x_off = {0, 0, 1, -1};
        vector<int> y_off = {1, -1, 0, 0};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]>0)
                {
                    for(int k = 0; k < 4; k++) {
                        int nx = i + x_off[k];
                        int ny = j + y_off[k];
                        if (0<= nx and nx < m and 0<= ny and ny < n and grid[nx][ny]>0) {
                            union_sets(n*i + j, nx*n + ny);
                        } 
                    }
                } 
            }
        }

        int h = hits.size();
        vector<int> ans(h, 0);
        for(int i = h-1; i >=0; i--) {
            int x = hits[i][0], y = hits[i][1];
            int flag = 0;
            grid[x][y]++;
            if(grid[x][y])
            {
                if(x==0) flag = 1;
                for(int k = 0; k < 4; k++) {
                    int nx = x + x_off[k];
                    int ny = y + y_off[k];
                    if (0<= nx and nx < m and 0<= ny and ny < n and grid[nx][ny]>0) {
                        if (find_parent(nx*n + ny) < n) {
                            flag = 1;
                        }
                        else if(find_parent(x*n + y) != find_parent(nx*n + ny)) {
                            ans[i] += size[find_parent(nx*n + ny)];
                        }
                        union_sets(x*n+y, nx*n + ny);
                    } 
                }
            }
            ans[i]*= flag;
        }
        return ans;
    }
};