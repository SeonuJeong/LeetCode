class Solution {
public:
    
    int dir[2][2] ={{1,0}, {0,1}};
    int M,N;
    vector<vector<int>> grid;
    vector<vector<int>> cache;
    
    int minPathSum(vector<vector<int>>& grid) {
        
        this->grid=grid;
        M=grid.size(); N=grid[0].size();
        cache.assign(M,vector<int>(N,-1));
        
        return dp(0,0);
    }
    
    int dp(int y, int x){
        if(y==M-1 && x==N-1)
            return grid[y][x];
        
        
        if(cache[y][x]!=-1)
            return cache[y][x];
        
        int path = INT_MAX;
        for(int i=0; i<2; i++){
            int row = y+dir[i][0];
            int col = x+dir[i][1];
            
            if(row>=0&&row<M&&col>=0&&col<N){
                path = min(path,grid[y][x]+dp(row,col));
            }
        }
        
        cache[y][x]=path;
        
        return path;
        
    }
};