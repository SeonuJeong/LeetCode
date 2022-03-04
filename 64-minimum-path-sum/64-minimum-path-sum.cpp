class Solution {
public:
    
    int M,N; 
    
    int minPathSum(vector<vector<int>>& grid) {
        
        M=grid.size(); N=grid[0].size();
        vector<vector<int>> dp(M,vector<int>(N,0));
        dp[M-1][N-1] = grid[M-1][N-1];
        
        for(int x=N-2; x>=0; x--){
            dp[M-1][x] = grid[M-1][x] + dp[M-1][x+1];
        }
        
        for(int y=M-2; y>=0; y--){
            dp[y][N-1] = grid[y][N-1] + dp[y+1][N-1];
        }
        
        for(int y=M-2; y>=0; y--){
            for(int x=N-2; x>=0; x--){
                dp[y][x] = grid[y][x] + min(dp[y+1][x],dp[y][x+1]);
            }
        }
        
        return dp[0][0];
    }
    
    
};