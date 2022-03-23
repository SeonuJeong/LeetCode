class Solution {
public:
    int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; //right , down, left, up
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n,0));
        
        queue<pair<int,int>> que;
        
        que.push(make_pair(0,0));
        int element=0;
        int cur_dir=0;
        while(!que.empty()){
            int y = que.front().first;
            int x = que.front().second;
            que.pop();
            
            result[y][x] = ++element; 
            
            for(int i=0; i<4; i++){
                int row = dir[cur_dir][0] + y;
                int col = dir[cur_dir][1] + x;
                
                if(row>=0&&row<n&&col>=0&&col<n&&result[row][col]==0){
                    que.push(make_pair(row,col));
                    break;
                }
                cur_dir = (cur_dir+1)%4;
            }
            
        }
        
        return result;
        
    }
};