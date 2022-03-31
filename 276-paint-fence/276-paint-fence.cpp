class Solution {
public:
    int numWays(int n, int k) {
        vector<vector<int>> dp(k, vector<int>(n+1,1));
        
        
        for(int i=2; i<=n; i++){
            
            int sum=0;
            for(int c=0; c<k; c++){
                sum += dp[c][i-1];
            }
            
            for(int color=0; color<k; color++){

                dp[color][i] = (sum-dp[color][i-1]);
                
                if(i!=2)
                    dp[color][i] += dp[color][i-2]*(k-1);
                else
                    dp[color][i] += dp[color][i-1];
            }
        }
        
        int result=0;
        
        for(int color=0; color<k; color++){
            result += dp[color][n];
        }
        
        return result;
    }
};