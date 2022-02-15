class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        
        for(int i=1; i<=numRows; i++){
            dp.push_back(vector<int>(i,0));
        }
        dp[0][0] = 1;
        
        for(int i=1; i<numRows; i++){
            for(int j=0; j<dp[i].size(); j++){
                dp[i][j] += j!=0?dp[i-1][j-1]:0;
                dp[i][j] += j!=dp[i].size()-1?dp[i-1][j]:0;
            }
        }
        
        return dp;
    }
};