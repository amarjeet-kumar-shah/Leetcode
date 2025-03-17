class Solution {
public:
    queue<pair<int,int>> q;

    void dfs(vector<vector<int>>& grid, int i, int j){
        // bc
        if(i<0 || i>=grid.size() || j>=grid[0].size() || j<0 || grid[i][j]==2 || grid[i][j]==0 ){
            return;
        }
        grid[i][j] = 2;
        q.push({i,j});

        dfs(grid, i+1,j);
        dfs(grid, i,j+1);
        dfs(grid, i,j-1);
        dfs(grid, i-1,j);



    }

    int multiSourceBfs(vector<vector<int>>& grid){
        int numberOfZeros=0;
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            int l=q.size();
            while(l--){
                auto curr= q.front();
                q.pop();
                for(auto direction:directions){
                    int new_x= curr.first + direction[0];
                    int new_y= curr.second + direction[1];
                    if(new_x >=0 && new_y>=0 && new_x<grid.size() && new_y<grid[0].size() &&grid[new_x][new_y]==1 ){
                        return numberOfZeros;
                    }
                    else if(new_x >=0 && new_y>=0  && new_x<grid.size() && new_y<grid[0].size() && grid[new_x][new_y]==0 ){
                        q.push({new_x,new_y});
                        grid[new_x][new_y]=2;
                    }

                }
            }
            numberOfZeros++;
        }
        return 0;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        bool flag= false;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && !flag){
                    dfs(grid,i,j);
                    flag=true;
                    break;
                }
            }
        }
        return multiSourceBfs(grid);
        
    }
};