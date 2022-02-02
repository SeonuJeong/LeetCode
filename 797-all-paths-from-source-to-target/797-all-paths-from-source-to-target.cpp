class Solution {
public:
    
    vector<vector<int>> result;
    int N;
    vector<vector<int>> graph;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->graph = graph;
        N = graph.size();
        vector<int> a;
        dfs(0,a);
        return result;
    }
    
    void dfs(int node, vector<int>& path){
        
        path.push_back(node);
        
        if(node==N-1){
            result.push_back(path);
            path.pop_back();
            return;
        }
        
        for(int i=0; i<graph[node].size(); i++){
                dfs(graph[node][i],path);
        }
        
        path.pop_back();
        return;
    }
};