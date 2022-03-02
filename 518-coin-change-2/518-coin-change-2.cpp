class Solution {
public:
    vector<vector<int>> cache;
    vector<int> coins;
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        this->coins = coins;
        cache.assign(amount+1,vector<int>(coins.size(),-1));
        
        return dp(amount,0);
    }
    
    int dp(int amount,int cur){
        
        if(amount==0)
            return 1;
        
        if(cache[amount][cur]!=-1)
            return cache[amount][cur];
        
        int count=0;
        for(int i=cur; i<coins.size(); i++){
            if(coins[i] <= amount)
                count += dp(amount-coins[i],i);
            else 
                break;
        }
        
        cache[amount][cur] = count;
        return count;
    }
};