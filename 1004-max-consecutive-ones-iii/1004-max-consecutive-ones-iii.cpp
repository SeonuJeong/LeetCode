class Solution {
public:
    //05:37
    int longestOnes(vector<int>& nums, int k) {
        
        
        int le=0, ri=0;
        
        int maxLen=0;
        for(; ri<nums.size(); ri++){
            
            if(nums[ri]==1){
                maxLen = max(maxLen,ri-le+1);
                continue;
            }
            
            
            k--;
            
            if(k>=0){
                maxLen = max(maxLen,ri-le+1);
                continue;
            }
            
            while(k<0){
                k += 1-nums[le];
                le++;
            }
            
            
        }
        
        
        
        return maxLen;
        
    }
};