class Solution {
public:
    
    vector<vector<int>> cache;
    int M,N;
    int delta[2][2] ={{0,1}, {1,0}};
    vector<vector<int>> obstacleGrid;
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->obstacleGrid = obstacleGrid;
        M = obstacleGrid.size();
        N = obstacleGrid[0].size();
        
        
        
        cache.assign(M,vector<int>(N,-1));
        
        if(obstacleGrid[0][0] != 1)
            return dp(0,0);
        else 
            return 0;
    }
    
    int dp(int y, int x){
        
        if(y==M-1 && x==N-1){
            return !obstacleGrid[y][x];
        }
        
        if(cache[y][x]!=-1)
            return cache[y][x];
        
        int path=0;
        for(int i=0; i<2; i++){
            int row = y + delta[i][0];
            int col = x + delta[i][1];
            
            if(row>=0&&row<M&&col>=0&&col<N&&obstacleGrid[row][col]!=1){
                path += dp(row,col);
            }
            
        }
        
        cache[y][x] = path;
        return path;
    }
};