class Solution {
public:
    //03:56
    //04:14
    vector<vector<int>> dp;

    int minDistance(string word1, string word2) {
        dp.assign(word1.length()+1,vector<int>(word2.length()+1,0));
        // row = word1 , col = word
        
        for(int i=0; i<word1.length(); i++){
            dp[i][word2.length()] = word1.length()-i;
        }
        
        for(int i=0; i<word2.length(); i++){
            dp[word1.length()][i] = word2.length()-i;
        }
        
        for(int y=word1.length()-1; y>=0; y--){
            for(int x=word2.length()-1; x>=0; x--){
                if(word1[y]==word2[x]){
                    dp[y][x] = dp[y+1][x+1];
                }
                else{
                    dp[y][x] = min(dp[y+1][x],dp[y][x+1])+1;
                }
            }
        }
        
        return dp[0][0];
    }
    
    
};