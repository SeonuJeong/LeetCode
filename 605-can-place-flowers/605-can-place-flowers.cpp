class Solution {
public:

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       
        vector<int> dp(flowerbed.size(),0);
        
        if(flowerbed[0]==0&&flowerbed.size()==1)
            dp[0] = 1;
        else if(flowerbed[0]==0&&flowerbed[1]==0){
            dp[0] = 1;
            flowerbed[0] = 1;
        }
        
        
        
        
        for(int i=1; i<flowerbed.size();i++){
            
            /*if(i+1 ==flowerbed.size()){
                if(flowerbed[i-1]==0 && flowerbed[i]==0) dp[i] = dp[i-1]+1;
                else dp[i] = dp[i-1];
                continue;
            }
            
            
            if(flowerbed[i+1]==0 && flowerbed[i-1]==0 && flowerbed[i]==0){
                dp[i] = dp[i-1]+1;
                flowerbed[i] = 1;
            }
            else
                dp[i] = dp[i-1];*/
            
            if(flowerbed[i]==0 && (i==0||flowerbed[i-1]==0) && (i==flowerbed.size()-1||flowerbed[i+1]==0)){
                dp[i] = dp[i-1] + 1;
                flowerbed[i] = 1;
            }
            else
                dp[i] = dp[i-1];
        }
        
        if(dp[flowerbed.size()-1]-n>=0)
            return true;
        else 
            return false;
        
    }
    
    
};