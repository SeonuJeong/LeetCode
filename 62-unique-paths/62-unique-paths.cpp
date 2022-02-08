class Solution {
public:
    //04:43
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        grid[0][0] = 1;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n ;j++){
                if(!(i==0 && j==0)){
                    int up=0, left=0;
                    if(i-1 >= 0){
                        up = grid[i-1][j];
                    }
                    if(j-1>=0){
                        left = grid[i][j-1];
                    }
                    
                    grid[i][j] = up+left;
                }
            }
        }
        
        return grid[m-1][n-1];
    }
};