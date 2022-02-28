class Solution {
public:
    
    vector<vector<int>> cache;
    string s;
    int minFlipsMonoIncr(string s) {
        this->s=s;
        cache.assign(s.length(),vector<int>(2,-1));
        
        return min(dp(s.length()-1,0), dp(s.length()-1,1));
    }
    
    int dp(int pos, int end){
        
        if(pos==0){
            cache[0][0] = s[pos]-'0';
            cache[0][1] = 1 - cache[0][0];
            
            return cache[0][end];
        }
        
        if(cache[pos][end]!=-1)
            return cache[pos][end];
        
        if(end==1){
            cache[pos][1] = min(dp(pos-1,0),dp(pos-1,1));
            if(s[pos]-'0' == 0)
                cache[pos][1] += 1;
        }
        else{
            cache[pos][0] = dp(pos-1,0);
            if(s[pos]-'0' == 1)
                cache[pos][0] += 1;
        }
        
        return cache[pos][end];
    }
    
};