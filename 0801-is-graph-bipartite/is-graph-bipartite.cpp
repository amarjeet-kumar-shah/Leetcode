class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int> &color) {
        color[node] = col; // Assign a color to the current node
        for (auto it : graph[node]) { // Iterate through all neighbors
            if (color[it] == -1) { // If the neighbor is uncolored
                if (dfs(it, !col, graph, color) == false) // Recursively color with the opposite color
                    return false; // Return false if a conflict is detected
            } else if (color[it] == col) { // If a neighbor has the same color
                return false; // Graph is not bipartite
            }
        }
        return true; // All neighbors are properly colored
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size(); // Number of nodes in the graph
        vector<int> color(V, -1); // Initialize all nodes as uncolored

        for (int i = 0; i < V; i++) { // Loop through all nodes
            if (color[i] == -1) { // If the node is uncolored
                if (dfs(i, 0, graph, color) == false) // Start DFS with color 0
                    return false; // Return false if any component is not bipartite
            }
        }
        return true; // Graph is bipartite
    }
};