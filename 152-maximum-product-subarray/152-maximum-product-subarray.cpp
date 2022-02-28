class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> big(nums.size());
        vector<int> small(nums.size());
        
        big[0]=nums[0];
        small[0]=nums[0];
        
        int result = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            
            int cur = nums[i];
            int beforeBig = big[i-1]*cur;
            int beforeSmall = small[i-1]*cur;
            
            big[i] = max(cur,max(beforeBig, beforeSmall));
            small[i] = min(cur,min(beforeBig, beforeSmall));
            
            result = max(result,big[i]);
        }
        
        return result;
    }
};