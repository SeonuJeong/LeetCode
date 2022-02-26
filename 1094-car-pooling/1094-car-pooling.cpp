class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int length=0;
        for(vector<int> v: trips){
            length = max(length,v[2]);
        }
        
        vector<int> result(length+1,0);
        
        for(vector<int> v: trips){
            result[v[1]] += v[0];
            if(v[2]<length)
                result[v[2]] -= v[0];
        }
        
        partial_sum(result.begin(), result.end(), result.begin());
        
        for(int k : result)
            if(k>capacity)
                return false;
        
        return true;
    }
};