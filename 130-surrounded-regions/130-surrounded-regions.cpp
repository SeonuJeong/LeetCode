class Solution {
public:
    
    vector<vector<int>> visited;
    int delta[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void solve(vector<vector<char>>& board) {
        visited.assign(board.size(), vector<int>(board[0].size(),0));
        
        for(int i=0; i<board.size(); i++){
            
            for(int j=0; j<board[0].size(); j++){
                
                if(board[i][j]=='O' && visited[i][j]==0){
                    if(enableFlip(i,j, board)){
                        doFlip(i,j, board);
                    }
                }
               
            }
        }
        
        
    }
    
    bool enableFlip(int row, int col, vector<vector<char>>& board){
        
        bool result=true;
        if(row==0 || row==board.size()-1|| col==0 || col==board[0].size()-1)
                result=false;
        
        visited[row][col]=-1;
        
        for(int i=0; i<4; i++){
            int y = row+delta[i][0];
            int x = col+delta[i][1];
            
            if((y>=0 && y<board.size()) && (x>=0 && x<board[0].size()) && visited[y][x]==0 && board[y][x]=='O'){
                if(enableFlip(y,x, board)==false) result=false;
            }
        }
        
        return result;
        
    }
    
    void doFlip(int row, int col,vector<vector<char>>& board){
        
        board[row][col] = 'X';
        
        for(int i=0; i<4; i++){
            int y = row+delta[i][0];
            int x = col+delta[i][1];
            
            if((y>=0 && y<board.size()) && (x>=0 && x<board[0].size()) && visited[y][x]==-1 && board[y][x]=='O'){
                doFlip(y,x, board);
            }
        }
        
    }
    
};