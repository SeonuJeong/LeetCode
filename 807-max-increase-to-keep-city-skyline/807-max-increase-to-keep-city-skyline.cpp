class Solution {
public:
    //07:00
    int total=0;
    vector<vector<int>> cache;
    int N;
    vector<vector<int>> grid;
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        this->grid = grid;
        N = grid.size();
        cache.assign(N, vector<int>(N,-1));
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                dp(i,j);
            }
        }
        
        return total;
    }
    
    
    
    void dp(int y, int x){
        
        int rowmx=-1;
        int colmx=-1;
        
        /*if(y-1>=0) colmx = cache[y-1][x];
        else{
            for(int i=0; i<N; i++){
                colmx = max(colmx, grid[y][i]);
            }
        }
        
        if(x-1>=0) rowmx = cache[y][x-1];
        else{
            for(int i=0; i<N; i++){
                rowmx = max(rowmx, grid[i][x]);
            }
        }*/
        
        for(int i=0; i<N; i++){
                colmx = max(colmx, grid[y][i]);
        }
        
        for(int i=0; i<N; i++){
                rowmx = max(rowmx, grid[i][x]);
            }
        
        total += min(colmx,rowmx) - grid[y][x];
        //cache[y][x] = min(colmx,rowmx);
        return;
    }
};