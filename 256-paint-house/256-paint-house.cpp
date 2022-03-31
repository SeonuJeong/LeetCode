class Solution {
public:
    
    int red=0;
    int green=2;
    int blue=1;
    int n;
    int minCost(vector<vector<int>>& costs) {
        n = costs.size();
        
        vector<vector<int>> dp(3, vector<int>(n,0));
        
        dp[red][0] = costs[0][red];
        dp[blue][0] = costs[0][blue];
        dp[green][0] = costs[0][green];
        
        for(int i=1; i<n; i++){
            for(int j=0; j<3; j++){
                int a = dp[(j+1)%3][i-1] + costs[i][j];
                int b = dp[(j+2)%3][i-1] + costs[i][j];
                
                dp[j][i] = min(a,b);
            }
        }
        
        
        return min(dp[red][n-1],min(dp[green][n-1],dp[blue][n-1]));
    }
    
    
};