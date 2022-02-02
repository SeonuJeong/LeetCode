class Solution {
public:
    
    int delta[8][2] = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> que;
        int path=-1;
        int N = grid.size();
        
        if(grid[0][0]==0){
            que.push(pair<int,int>(0,0));
            grid[0][0]==1;
            path=1;
        }
        
        if(N==1)
            return path;
        
        
        while(!que.empty()){
            
            int count=que.size();
            path++;
            while(count>0){
                
                pair<int,int> tmp = que.front();
                que.pop();
                
                for(int i=0; i<8; i++){
                    int row = tmp.first + delta[i][0];
                    int col = tmp.second + delta[i][1];
                    
                    if(row==N-1 && col==N-1){
                        if(grid[row][col]==0) return path;
                        else return -1;
                    }
                    
                    if((row>=0 && row<N) && (col>=0 && col<N) && (grid[row][col]==0)){
                        que.push(pair<int,int>(row,col));
                        grid[row][col] = 1;
                    }
                    
                }
                count--;
            }
        }
        
        return -1;
    }
};