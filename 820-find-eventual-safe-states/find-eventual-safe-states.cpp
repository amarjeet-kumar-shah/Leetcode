class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         vector<int> ans;

    int V = graph.size();
    unordered_map<int, vector<int>> adj;
    vector<int> indegree(V, 0), outdegree(V, 0);
    queue<int> q;

    // Build the adjacency list and calculate indegree/outdegree
    for (int i = 0; i < V; i++) {
        adj[i] = graph[i];
        outdegree[i] = graph[i].size();
        for (auto& v : graph[i]) {
            indegree[v]++;
        }
    }

    // Push terminal nodes (outdegree == 0) into the queue
    for (int i = 0; i < V; i++) {
        if (outdegree[i] == 0) {
            q.push(i);
            ans.push_back(i); // Include terminal nodes in the result
        }
    }

    unordered_map<int,vector<int>> adjR;
    for (int u = 0; u < V; u++) {
        for(auto &v: adj[u]){
        adjR[v].push_back(u);
    }
    }
   

    // Process the graph using BFS
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (auto& v : adjR[u]) {
            outdegree[v]--;
            if (outdegree[v] == 0) {
                q.push(v);
                ans.push_back(v);
            }
        }
    }

    // Sort the result for consistent output
    sort(ans.begin(), ans.end());
    return ans;
    }
};