class Solution {
public:
    
    int N;
    vector<int> prices;
    
    vector<vector<int>> cache;
    int maxProfit(vector<int>& prices) {
        N = prices.size();
        this->prices = prices;
        
        cache.assign(N+1,vector<int>(N+1,-1));
        return max(dp(1,0),dp(1,1));
    }
    
    int dp(int index, int lastBuy){
        
        if(index>=N+1)
            return 0;
        
        if(cache[index][lastBuy]!=-1)
            return cache[index][lastBuy];
        
        int profit=0;
        if(lastBuy==0){
            profit = max(dp(index+1,index), dp(index+1,lastBuy));
        }
        else{
            if(prices[index-1]>prices[lastBuy-1])
                profit = max(profit, dp(index+2,0)+prices[index-1]-prices[lastBuy-1]);
            
            profit = max(profit,dp(index+1,lastBuy));
        }
        
        cache[index][lastBuy] = profit;
        
        return profit;
    }
};