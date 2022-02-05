class Solution {
public:
    // 06:21
    // 06:39
    vector<vector<bool>> visited;
    string word;
    vector<vector<char>> board;
    int delta[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    bool exist(vector<vector<char>>& board, string word) {
        visited.assign(board.size(), vector<bool>(board[0].size(),false));
        this->word = word;
        this->board = board;
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(backTrack(i,j,0))
                    return true;
            }
        }
        
        return false;
    }
    
    bool backTrack(int row,int col,int index){
        
        if(index == word.size()-1 && board[row][col]== word[index]){
            return true;    
        }
        
        if(board[row][col] != word[index])
            return false;
        
        visited[row][col] = true;
        
        for(int i=0; i<4; i++){
            int y = row+delta[i][0];
            int x = col+delta[i][1];
            
            if(y>=0 && y< board.size() && x>=0 && x<board[0].size() && visited[y][x]==false){
                if(backTrack(y,x,index+1)){
                    visited[row][col] = false;
                    return true;
                }
            }
        }
                
        visited[row][col] = false;
        return false;
    }
};