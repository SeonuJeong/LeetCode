class Solution {
public:
    int maxProfit(vector<int>& prices) {
        priority_queue<pair<int,int>> pque;
        
        for(int i=0; i<prices.size();i++){
            pque.push(make_pair(prices[i],i));
        }
        
        int profit = 0;
        for(int i=0; i<prices.size()-1;i++){
            
            while(pque.top().second<=i){
                pque.pop();
            }
            
            if(pque.top().first>prices[i])
                profit = max(profit, pque.top().first-prices[i]);
            
        }
        
        return profit;
    }
};