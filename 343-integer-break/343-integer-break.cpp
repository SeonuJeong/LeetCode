class Solution {
public:
    // 02:35
    
    vector<int> cache;

    int integerBreak(int n) {
        cache.assign(n+1,-1);
        
        return dp(n);
    }
    
    int dp(int n){
        if(n==2 || n==1){
            return 1;
        }
        
        if(cache[n] != -1)
            return cache[n];
        
        int result = 0;
        for(int i=1; i<n; i++){
            int tmp = max(i*(n-i) , i*dp(n-i));
            result = max(result, tmp);
        }
        
        cache[n] = result;
        return cache[n];
    }
    
    
    
};