class Solution {
public:
    vector<int> cache;
    int tribonacci(int n) {
        cache.assign(n<3?3:n+1,-1);
        cache[0]=0; cache[1]=1; cache[2]=1;
        return dp(n);
    }
    
    int dp(int n){
        if(cache[n]!=-1)
            return cache[n];
        
        cache[n] = dp(n-1)+dp(n-2)+dp(n-3);
        return cache[n];
    }
};