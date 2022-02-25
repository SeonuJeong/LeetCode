class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> grid(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int i=0;i<matrix.size(); i++)
            for(int j=matrix[0].size()-1; j>=0; j--)
                if(matrix[i][j]=='1'){
                    if(j==matrix[0].size()-1)
                        grid[i][j]=1;
                    else
                        grid[i][j] = grid[i][j+1]+1;
                }
        
        
        int area=0;
        for(int i=0; i<grid.size(); i++){
            
            for(int j=0; j<grid[0].size(); j++){
                
                int height=i;
                int rowMin = grid[i][j];
                while(height<grid.size() && height-i+1<=rowMin){
                
                    rowMin = min(grid[height][j],rowMin);
                    if(rowMin>=height-i+1)
                        area = max(area,(height-i+1)*(height-i+1));
                    height++;
                    
                }
                
            }
        }
            
        
        return area;
        
    }
};