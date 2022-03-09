class Solution {
public:
    //04:56
    
    int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};
    
    int m,n;
    void gameOfLife(vector<vector<int>>& board) {
        m=board.size();
        n=board[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                changeCell(i,j,board);
            }
        }
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(board[i][j]==-2)
                    board[i][j]=0;
                else if(board[i][j]==-1)
                    board[i][j]=1;
            }
                
        
    }
    
    void changeCell(int y,int x, vector<vector<int>>& board){
        
        bool isLive = false;
        if(board[y][x]==1 || board[y][x]==-2)
            isLive = true;
        
        int liveCount=0;
        for(int i=0; i<8; i++){
            int row = y + dir[i][0];
            int col = x + dir[i][1];
            
            if(row<0||row>=m||col<0||col>=n)
                continue;
            
            if(board[row][col]==1 || board[row][col]==-2)
                liveCount++;
        }
        
        if((liveCount<2||liveCount>3)&&isLive)
            board[y][x] = -2;
        else if(liveCount==3 && !isLive)
            board[y][x] = -1;
        
    }
};