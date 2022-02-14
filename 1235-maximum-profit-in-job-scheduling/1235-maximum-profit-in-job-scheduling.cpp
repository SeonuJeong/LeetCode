class Solution {
public:
    ///10:40
    vector<int> cache;
    vector<int> startTime;
    vector<int> endTime;
    vector<int> profit;
    vector<pair<int,int>> v;
    
    static bool cmp(pair<int,int>& a, pair<int,int>& b){
        if(a.first==b.first)
            return a.second<b.second;
        
        return a.first<b.first;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        cache.assign(startTime.size(),-1);
        this->startTime = startTime;
        this->endTime = endTime;
        this->profit = profit;

        for(int i=0; i<startTime.size(); i++){
            v.push_back(make_pair(startTime[i],i));
        }
        sort(v.begin(),v.end(),cmp);
        
        
        
        int mx=INT_MIN;
        for(int i=0; i<startTime.size(); i++){
            mx = max(mx,dp(i));
        }
        
        return mx;
    }
    
    int dp(int start){
        
        if(start==startTime.size()-1){
            return profit[v[start].second];
        }
        
        if(cache[start]!=-1)
            return cache[start];
        
        
        int nextStart = find(endTime[v[start].second]);
        if(v[nextStart].first<endTime[v[start].second]){
            cache[start] = max(profit[v[start].second], dp(start+1));
        }
        else{
            cache[start] = max(dp(nextStart)+profit[v[start].second], dp(start+1));
        }
        
        return cache[start];
    }
    
    int find(int end){
        
        int le=0, ri=startTime.size()-1;
        
        
        while(le<ri){
            
            int mid = (ri+le)/2;
            
            if(v[mid].first<end){
                le = mid+1;
            }
            else if(v[mid].first>=end){
                ri = mid;
            }
        }
        
        return ri;
    }
    
};