class Solution {
public:
    
    
    int m,n;
    int maxKilledEnemies(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        
        vector<vector<int>> right(m,vector<int>(n,0));
        vector<vector<int>> left(m,vector<int>(n,0));
        vector<vector<int>> up(m,vector<int>(n,0));
        vector<vector<int>> down(m,vector<int>(n,0));
        
        
        for(int i=0; i<m; i++){
            int person=0;
            for(int j=n-1; j>=0; j--){
                if(grid[i][j]=='E')
                    person++;
                else if(grid[i][j]=='W')
                    person=0;
                else
                    right[i][j] = person;
            }
        }
        
        for(int i=0; i<m; i++){
            int person=0;
            for(int j=0; j<n; j++){
                if(grid[i][j]=='E')
                    person++;
                else if(grid[i][j]=='W')
                    person=0;
                else
                    left[i][j] = person;
            }
        }
        
        for(int j=0; j<n; j++){
            int person=0;
            for(int i=0; i<m; i++){
                if(grid[i][j]=='E')
                    person++;
                else if(grid[i][j]=='W')
                    person=0;
                else
                    up[i][j] = person;
            }
        }
        
        for(int j=0; j<n; j++){
            int person=0;
            for(int i=m-1; i>=0; i--){
                if(grid[i][j]=='E')
                    person++;
                else if(grid[i][j]=='W')
                    person=0;
                else
                    down[i][j] = person;
            }
        }
        
        int result=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='0'){
                    int total = up[i][j] + down[i][j] + left[i][j] + right[i][j];
                    result = max(result,total);
                }
            }
        }
        
        return result;
    }
    
    
};