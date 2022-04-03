class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        vector<int> up(nums.size(),1);
        vector<int> down(nums.size(),1);
        
        int result=1;
        
        for(int i=1; i<nums.size(); i++){
            
            //up
            for(int j=i-1; j>=0; j--){
                if(nums[j]>nums[i])
                    down[i] = max(down[i],up[j]+1);
            }
            
            
            for(int j=i-1; j>=0; j--){
                if(nums[j]<nums[i])
                    up[i] = max(up[i],down[j]+1);
            }
            
            result = max(result,max(up[i],down[i]));    
            
        }
        
        
        return result;
    }
};