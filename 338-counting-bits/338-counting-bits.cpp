class Solution {
public:
    vector<int> cache;
    
    vector<int> countBits(int n) {
        cache.assign(n+1,-1);
        
        vector<int> result(n+1);
        
        for(int i=n; i>=0; i--){
            result[i] = dp(i);    
        }
        
        return result;
    }
    
    int dp(int n){
        
        if(n==0)
            return 0;
        
        if(cache[n]!=-1){
            return cache[n];
        }
        
        int cur = n & 1;
        
        cache[n] = dp(n>>1)+cur;
        
        return cache[n];
    }
    
};