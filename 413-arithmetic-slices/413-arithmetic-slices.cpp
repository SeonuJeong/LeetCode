class Solution {
public:
    // 06:26
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        
        int left=0;
        int dif=nums[1]-nums[0];
        
        vector<int> dp(nums.size(),0);
        int count=0;
        
        for(int i=2; i<nums.size(); i++){
            if(nums[i]-nums[i-1]!= dif){
                dif = nums[i] - nums[i-1];
                left = i-1;
            }
            else if(i-left+1>=3){
                dp[i] = (dp[i-1])+1;
            }
            
            count+=dp[i];
        }
        
        return count;
        
    }
};