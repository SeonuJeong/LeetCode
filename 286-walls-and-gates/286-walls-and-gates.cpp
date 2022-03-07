class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        int m,n;
        m = rooms.size(); n = rooms[0].size();
        
        queue<pair<int,int>> que;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j ++){
                if(rooms[i][j]==0)
                    que.push(make_pair(i,j));
            }
        }
        
        int delta[4][2] = {{1,0},{-1,0}, {0,1}, {0,-1}}; 
        
        while(!que.empty()){
            
            pair<int,int> tmp = que.front();
            int y = tmp.first;
            int x = tmp.second;
            que.pop();
            
            for(int i=0; i<4; i++){
                int row = y+delta[i][0];
                int col = x+delta[i][1];
                
                if(row<0||row>=m||col<0||col>=n||rooms[row][col]==-1||
                  rooms[row][col]==0||rooms[row][col]!=INT_MAX)
                    continue;
                
                rooms[row][col] = rooms[y][x]+1;
                que.push(make_pair(row,col));
            }
            
        }
        
        
    }
};