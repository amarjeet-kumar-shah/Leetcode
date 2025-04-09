class Solution {
public:

void dfs(vector<vector<char>>& board, int row, int col, int r, int c){
    if(row<0 || col<0 || row>=r || col>=c || board[row][col]!='O') return ;
    board[row][col]='T';
    int rw[]={1,0,-1,0};
    int cw[]={0,1,0,-1};
    for(int i=0;i<4;++i){
        dfs(board, row+rw[i],col+cw[i],r,c);
    }
}
    void solve(vector<vector<char>>& board) {
        int r=board.size(),c=board[0].size();
        for(int i=0;i<r;++i){
            if(board[i][0]=='O') dfs(board, i, 0, r, c);
            if(board[i][c-1]=='O') dfs(board, i, c-1, r, c);
        }
        for(int i=0;i<c;++i){
            if(board[0][i]=='O') dfs(board,0,i,r,c);
            if(board[r-1][i]=='O') dfs(board, r-1, i, r,c);
        }

        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(board[i][j]=='T') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};