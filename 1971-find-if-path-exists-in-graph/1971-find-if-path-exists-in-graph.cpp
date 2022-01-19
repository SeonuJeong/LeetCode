class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        graph.assign(n,vector<int>(0));
        visited.assign(n,false);
        
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        return dfs(source,destination);
    }
    
    bool dfs(int source, int dest){
        
        if(source==dest)
            return true;
        
        if(visited[source]!=false)
            return false;
        
        visited[source] = true;
        
        for(int i=0; i<graph[source].size(); i++){
            if(dfs(graph[source][i],dest))
                return true;
        }
        return false;
    }
};