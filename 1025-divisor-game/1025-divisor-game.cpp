class Solution {
public:
    //08:48
    vector<vector<int>> cache;
    bool divisorGame(int n) {
        cache.assign(n+1,vector<int>(2,-1));
        return dp(n,0);
    }
    
    bool dp(int n, int who){
        
        if(n==1){
            return who;
        }
        
        if(cache[n][who]!=-1)
            return cache[n][who];
        
        for(int i=1; i<n; i++){
            if(n%i==0 && dp(n-i,!who)==!who){
                cache[n][who] = !who;
                return !who;
            }
        }
        
        cache[n][who] = who;
        return who;
    }
};