class Solution {
public:
 
    int delta[4][2] ={{1,0},{-1,0},{0,1},{0,-1}}; // down,up,right,left;
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<tuple<int,int,int>> que;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==2){
                  que.push(tuple<int,int,int>(i,j,0));
                }
            }
           
        }
        
        int minute=0;
        
        
        while(!que.empty()){
            tuple<int,int,int> tmp = que.front();
            que.pop();
            
            minute = get<2>(tmp);
            
            for(int i=0; i<4; i++){
                int x = get<1>(tmp) + delta[i][1];
                int y = get<0>(tmp) + delta[i][0];
                if(!(y<0||y>=grid.size()||x<0||x>=grid[0].size()) ){
                    if(grid[y][x]==1){
                        grid[y][x] = 2;
                        que.push(tuple<int,int,int>(y, x,get<2>(tmp)+1) );
                    }
                }
            }
        }
                
    
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return minute;
    
    }
};