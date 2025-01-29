class Solution {
public:
    vector<int> parent, rank;
    int find(int node) {
        if(parent[node] != node) {
            return parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    bool Union(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if(rootU == rootV) {
            return false;
        }
        else if(rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
            rank[rootV]++;
            return true;
        }
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
            return true;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1, 0);
        rank.resize(n+1, 0);
        for(int i=1; i<n; i++) {
            parent[i] = i;
        }
        for(auto e: edges) {
            if(!Union(e[0], e[1])) {
                return e;
            }
        }
        return {};
    }
};