class Solution {
public:
    
    
    int m,n;
    int maxKilledEnemies(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        
        vector<vector<int>> output(m,vector<int>(n,0));
        
        
        
        for(int i=0; i<m; i++){
            int person=0;
            for(int j=n-1; j>=0; j--){
                if(grid[i][j]=='E')
                    person++;
                else if(grid[i][j]=='W')
                    person=0;
                else
                    output[i][j] += person;
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
                    output[i][j] += person;
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
                    output[i][j] += person;
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
                    output[i][j] += person;
            }
        }
        
        int result=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='0'){
                    result = max(result,output[i][j]);
                }
            }
        }
        
        return result;
    }
    
    
};