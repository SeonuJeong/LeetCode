class Solution {
public:
    
    vector<int> cache;
    int numTrees(int n) {
        cache.assign(n+1,-1);
        
        return dp(n);
    }
    
    int dp(int n){
        
        //base case
        if(n==0||n==1)
            return 1;
        if(n==2)
            return 2;
        
        if(cache[n]!=-1)
            return cache[n];
        
        int result=0;
        int left=0;
        int right=n-1;
        for( ; left<n; left++,right--){
            
            result += dp(left)*dp(right);
        }
        
        cache[n] = result;
        return result;
    }
};