class Solution {
public:
    
    vector<vector<int>> cache;
    int limit;
    
    vector<int> days;
    vector<int> costs;
    
    int pass[3]={1,7,30};
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        limit = days.back();
        cache.assign(days.size(), vector<int>(limit+1,-1));
        this->days = days;
        this->costs = costs;
        
       
        return dfs(0,0);
        
    }
    
    int dfs(int index, int passDay){
        
        if(index == days.size()){
            return 0;
        }
        
        
        if(cache[index][passDay]!=-1)
            return cache[index][passDay];
        
        int cost=INT_MAX;
        
        if(days[index]<=passDay){
            cost = dfs(index+1,passDay);
        }
        else{
            for(int i=0; i<costs.size(); i++){
                int day = days[index]+pass[i]-1;

                day = day>limit? limit:day;

                cost = min(cost, dfs(index+1, day)+costs[i]);
            }
        }
        
        cache[index][passDay] = cost;
        
        return cost;
    }
};