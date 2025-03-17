class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto time : times){
            adj[time[0]].push_back({time[1], time[2]});
        }
        vector<bool> visited(n + 1, false);
        pq.push({0, k}); int visitedNodes = 0; int res = 0;
        while(!pq.empty()){
                auto [weight, node] = pq.top();
                pq.pop();
                if(visited[node]){
                    continue;
                }
                visited[node] = true;
                visitedNodes++;
                if(visitedNodes == n){
                    return weight;
                }
                for(auto nei : adj[node]){
                    auto dist = nei.second;
                    auto neighbor = nei.first;
                    pq.push({dist + weight, neighbor});
                }
        }
        return -1;
    }
};