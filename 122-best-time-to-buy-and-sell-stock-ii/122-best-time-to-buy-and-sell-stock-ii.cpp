class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0];
        
        int total=0;
        for(int i=1; i<prices.size(); i++){
            
            if(minPrice < prices[i]){
                total += prices[i]-minPrice;
                minPrice=prices[i];
            }
            else{
                minPrice = prices[i];
            }
        }
        
        return total;
    }
};