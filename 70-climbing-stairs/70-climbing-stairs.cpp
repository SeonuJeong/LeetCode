class Solution {
public:
    
    vector<int> cache;
    
    int climbStairs(int n) {
        
        cache.assign(46,-1);
        return func(n);
    }
    
    int func(int n){
        
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        
         if(cache[n]!=-1)
            return cache[n];
        
        cache[n] = func(n-1)+func(n-2);
        return cache[n];
    }
};