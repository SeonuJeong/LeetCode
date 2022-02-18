class Solution {
public:
    //10:45

    vector<vector<int>> grid;
    int total=1;
    int startY,startX;
    
    int delta[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};
    int uniquePathsIII(vector<vector<int>>& grid) {
        this->grid = grid;
        
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==0) total++; 
                else if(grid[i][j]==1){
                    startY=i; startX=j;
                }
            }
        }
        
        unordered_map<string,bool> visited;
        string key = to_string(startY) + " " + to_string(startX);
        visited[key] = true;
        return dfs(startY, startX, visited);
        
    }
    
    int dfs(int row,int col ,unordered_map<string,bool>& visited){
        
        if(grid[row][col]==-1){
            return 0;
        }
        
        if(grid[row][col]==2){
            if(visited.size()==total+1)
                return 1;
            else return 0;
        }
        
        int count=0;
        for(int i=0; i<4; i++){
            int y = row + delta[i][0];
            int x = col + delta[i][1];
            
            string key = to_string(y) + " " + to_string(x);
            if(y>=0 && y<grid.size() && x>=0 && x<grid[0].size() && visited.find(key)==visited.end()){
                visited[key] = true;
                count += dfs(y,x,visited);
                visited.erase(key);
            }
        }
        
        return count;
    }
};