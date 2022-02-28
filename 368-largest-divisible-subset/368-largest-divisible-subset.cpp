class Solution {
public:
    //05:30
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<int> dp(nums.size(),1);
        vector<vector<int>> list(nums.size());
        
        for(int i=0; i<list.size(); i++){

        }
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            
            int index=-1;
            
            for(int j=i-1; j>=0; j--){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i] = dp[j]+1;
                        index=j;
                    }
                }
            }//for(int j)
            
            if(index==-1)
                list[i].push_back(nums[i]);
            else{
                list[i] = {list[index].begin(), list[index].end()};
                list[i].push_back(nums[i]);
            }
            
        }//for(int i)
        
        int maxLen=0;
        int index;
        
        for(int i=0; i<dp.size(); i++){
            if(dp[i]>=maxLen){
                maxLen=dp[i];
                index=i;
            }
                
        }
       
        return list[index];
    }
};