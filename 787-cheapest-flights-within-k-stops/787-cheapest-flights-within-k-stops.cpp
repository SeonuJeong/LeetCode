class Solution {
public:
    vector<vector<int>> cache;
    unordered_map<int,vector<pair<int,int>>> um;
    
    int k;
    int dst;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        this->k=k; this->dst = dst;
        
        cache.assign(n, vector<int>(k+2,-1));
        
        for(vector<int>& v: flights){
            um[v[0]].push_back(make_pair(v[1],v[2]));
        }
        
        return dp(src,0)==INT_MAX?-1:dp(src,0);
    }
    
    int dp(int src, int stop){
        
        if(stop>k+1) return INT_MAX;
        
        if(src==dst){
            if(stop<=k+1) return 0;
            else return INT_MAX;
        }
        
        if(cache[src][stop]!=-1)
            return cache[src][stop];
        
        vector<pair<int,int>> v = um[src];
        int cost=INT_MAX;
        for(int i=0; i<v.size(); i++){
            int tmp =dp(v[i].first,stop+1);
            cost = min(cost, tmp==INT_MAX?INT_MAX:tmp+v[i].second);
        }
        
        cache[src][stop] = cost;
        return cost;
    }
};