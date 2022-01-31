class Solution {
public:
    int island=0;
    vector<vector<bool>> visited;
    int delta[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        visited.assign(grid.size(), vector<bool>(grid[0].size(),false));
        
        queue<pair<int,int>> que;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    que.push(make_pair(i,j));
                    visited[i][j]=true;
                    island++;
                }// if
                
                while(!que.empty()){
                    pair<int,int> tmp = que.front();
                    que.pop();
                    
                    for(int k=0; k<4; k++){
                        int row = tmp.first + delta[k][0];
                        int col = tmp.second + delta[k][1];
                        
                        if((0<=row && row<grid.size()) && (0<=col && col<grid[0].size()) && grid[row][col]=='1'
                          && visited[row][col]==false){
                            que.push(make_pair(row,col));
                            visited[row][col]=true;
                        }//if
                    }//for
                    
                }//while
                
                        
            }//for j
        }// for i
        
        return island;
        
    }// numIslands
};