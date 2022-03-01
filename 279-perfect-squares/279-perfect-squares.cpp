class Solution {
public:
    vector<int> cache;
    int numSquares(int n) {
        
        cache.assign(n+1,-1);
        
        return dp(n);
    }
    
    int dp(int n){
        
        if(n==0)
            return 0;
        
        if(cache[n]!=-1)
            return cache[n];
        
        int min_=INT_MAX;
        
        for(int i=1; i<=n; i++){
            if(n>=(i*i)){
                int tmp = dp(n-(i*i))==INT_MAX?INT_MAX:dp(n-(i*i))+1;
                min_ = min(tmp,min_);
            }
            else
                break;
        }
        
        cache[n]=min_;
        return min_;
    }
};