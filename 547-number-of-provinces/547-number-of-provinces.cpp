class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(),false);
        
        vector<int> stk;
        int group=0;
        for(int i=0; i<isConnected.size(); i++){
            if(visited[i]==false){
                stk.push_back(i);
                visited[i] = true;
                group++;
            } 
            
            while(!stk.empty()){
                int cur = stk.back();
                stk.pop_back();
                
                for(int i=0; i<isConnected[0].size();i++){
                    if(isConnected[cur][i]==1 && visited[i]==false){
                        stk.push_back(i);
                        visited[i] = true;
                    }
                }
            }
        }
        
        return group;
    }
};