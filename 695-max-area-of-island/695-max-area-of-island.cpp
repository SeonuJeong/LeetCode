class Solution {
public:
    vector<vector<int>> visited;
    int delta[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        visited.assign(m,vector<int>(n,0));
        int area=0;
        
        for(int i=0; i<m ; i++)
            for(int j=0; j<n; j++)
                area = max(area,calArea(grid,i,j));
        
        return area;
    }
    
    int calArea(vector<vector<int>>& grid, int row, int col){
        if(row<0||row>=grid.size()||col<0||col>=grid[0].size()) return 0;
        if(grid[row][col]!=1 || visited[row][col]!=0) return 0;
        
        int sum=0;
        visited[row][col] = 1;
        
        for(int i=0; i<4; i++){
            sum += calArea(grid, row+delta[i][0], col+delta[i][1]);
        }
        
        return sum+1;
    }
    
};