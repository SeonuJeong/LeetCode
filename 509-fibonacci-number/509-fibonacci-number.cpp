class Solution {
public:
    
    vector<int> cache;
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        cache.assign(n+1,-1);
        cache[0]=0;
        cache[1]=1;
        return dp(n);
    }
    
    int dp(int n){
        
        if(cache[n]!=-1)
            return cache[n];
        
        cache[n] = dp(n-1)+dp(n-2);
        return cache[n];
    }
};