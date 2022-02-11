class Solution {
public:
    //03:56
    
    vector<vector<int>> cache;
    string word1;
    string word2;
    int minDistance(string word1, string word2) {
        cache.assign(word1.length(),vector<int>(word2.length(),-1));
        // row = word1 , col = word2
        
        this->word1 = word1;
        this->word2 = word2;
        
        return dp(word1.length()-1, word2.length()-1);
        
    }
    
    int dp(int y, int x){
        
        if(y==-1 || x==-1){
            return y==-1?x+1:y+1;
        }
        
        if(cache[y][x]!=-1){
            return cache[y][x];
        }
        
        if(word1[y] == word2[x]){
             cache[y][x] = dp(y-1,x-1);
        }
        else{
             cache[y][x] = min(dp(y-1,x),dp(y,x-1))+1;
        }
        
        
        return cache[y][x];
    }
};