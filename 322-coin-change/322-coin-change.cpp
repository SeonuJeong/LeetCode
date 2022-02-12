class Solution {
public:
    //02:20
    vector<int> coins;
    vector<int> cache;
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        cache.assign(10001,-1);
        
        int tmp = dp(amount);
        
        if(tmp!=INT_MIN){
            return tmp;
        }
        else return -1;
        
    }
    
    int dp(int amount){
        if(amount==0){
            return 0;
        }
        else if(amount<0){
            return INT_MIN;
        }
        
        if(cache[amount]!=-1){
            return cache[amount];
        }
        
        int result = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int tmp = dp(amount-coins[i]);
            if(tmp >=0){
                result = min(result,tmp+1);
            }
        }
        
        if(result!=INT_MAX){
            cache[amount] = result;
            return cache[amount];
        }
        else{
            cache[amount] = INT_MIN;
            return cache[amount];
        }
    }
};