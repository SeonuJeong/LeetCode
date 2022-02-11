class Solution {
public:
    //09:54
    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),0));
            
        for(int i=0; i<text2.length(); i++){
            if(text1[0]==text2[i]){
                dp[0][i]=1;
            }
            else if(i!=0 && dp[0][i-1]==1){
                dp[0][i]=1;
            }
        }
        
        for(int i=0; i<text1.length(); i++){
            if(text2[0]==text1[i]){
                dp[i][0]=1;
            }
            else if(i!=0 && dp[i-1][0]==1){
                dp[i][0]=1;
            }
        }
        
        for(int y=1; y<text1.length(); y++){
            for(int x=1; x<text2.length(); x++){
                if(dp[y-1][x] == dp[y][x-1]){
                    if(dp[y-1][x] != dp[y-1][x-1]){
                        dp[y][x] = dp[y-1][x];
                    }
                    else{
                        if(text1[y]==text2[x]){
                            dp[y][x] = dp[y-1][x-1]+1;
                        }
                        else
                            dp[y][x] = dp[y-1][x-1];
                    }
                }
                else{
                    dp[y][x] = max(dp[y-1][x],dp[y][x-1]);
                }
            }
        }
        
        return dp[text1.length()-1][text2.length()-1];
        
    }
};