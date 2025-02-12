class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int checkPoints = 0;
        int dist = 0;
        int fuel = startFuel;
        int i = 0;
        priority_queue<pair<int,int>>pq;
        while(true){
            while(i<stations.size()){
                if(stations[i][0] <= dist + fuel){
                    pq.push({stations[i][1],stations[i][0]});
                }
                else{
                    break;
                }
                i++;
            }
            dist += fuel;
            fuel = 0;
            if(dist>=target) break;

            if(pq.empty()){
                checkPoints = -1;
                break;
            }

            auto &top = pq.top();
            fuel = (dist-top.second)+top.first;
            dist = top.second;
            pq.pop();
            checkPoints++;
        }
        return checkPoints;
    }
};