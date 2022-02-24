class Solution {
public:
    vector<vector<bool>> visited;
    int delta[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};//right, down, left, up
    int M,N;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        M = matrix.size();
        N = matrix[0].size();
        
        visited.assign(matrix.size(), vector<bool>(matrix[0].size(),false));
        vector<int> result;
        
        int dir=0;
        queue<pair<int,int>> que;
        que.push(make_pair(0,0));
        visited[0][0] = true;
        result.push_back(matrix[0][0]);
        while(!que.empty()){
            
            pair<int,int> cur = que.front();
            que.pop();
            
            int row = cur.first+delta[dir][0];
            int col = cur.second+delta[dir][1];
            if(!(row>=0&&row<M&&col>=0&&col<N && visited[row][col]==false)){
                dir = (dir+1)%4;
                row = cur.first+delta[dir][0];
                col = cur.second+delta[dir][1];
            }
            
            if(row>=0&&row<M&&col>=0&&col<N && visited[row][col]==false){
                    que.push(make_pair(row,col));
                    visited[row][col] = true;
                    result.push_back(matrix[row][col]);
            }
            
        }
        
        return result;
        
    }
};