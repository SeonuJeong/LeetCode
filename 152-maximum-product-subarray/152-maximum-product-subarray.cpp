class Solution {
public:
    int maxProduct(vector<int>& nums) {
                
        int big=nums[0];
        int small=nums[0];
        
        int result = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            
            int cur = nums[i];
            int beforeBig = big*cur;
            int beforeSmall = small*cur;
            
            big = max(cur,max(beforeBig, beforeSmall));
            small = min(cur,min(beforeBig, beforeSmall));
            
            result = max(result,big);
        }
        
        return result;
    }
};