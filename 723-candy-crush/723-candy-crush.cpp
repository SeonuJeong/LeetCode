class Solution {
public:
    
    int delta[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int m,n;
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        //if find same type, make it minus
        
        bool iscrush=true;
        
        while(iscrush){
            
            vector<vector<bool>> visited(m,vector<bool>(n,false));
            
            int crush=0;
            for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                    if(!visited[i][j]&&board[i][j]!=0){
                        for(int dir=0; dir<4; dir++)
                            crush = max(crush, dfs(i,j,1,dir,board));
                    }
            
            if(crush<3) break;;
            
            
            for(int i=0; i<n; i++)
                crushNdrop(i,board);
        }
        
        return board;
    }
    
    void crushNdrop(int col,vector<vector<int>>& board){
        
        int count=0;
        for(int y=m-1; y>=0; y--){
            
            if(board[y][col]>0){
                int tmp = board[y][col];
                board[y][col]=0;
                board[y+count][col]=tmp;
            }
            else{
                board[y][col]=0;
                count++;
            }
                
        }
        
    }
    
    
    int dfs(int y, int x,int count,int dir, vector<vector<int>>& board){
         
        int returnCount=0;
        
        int row=y+delta[dir][0];
        int col=x+delta[dir][1];

        if(!(row<0||row>=m||col<0||col>=n)){

            if(abs(board[row][col])==abs(board[y][x])){
                returnCount =  dfs(row,col,count+1,dir,board);
            }
        }
        
        if(count>=3 || returnCount>=3)
            if(board[y][x]>0)
                board[y][x] = board[y][x]*-1;
        
        return max(count,returnCount);
    }
};