class Solution {
public:
    //03:25
    int jump(vector<int>& nums) {
        int last = nums.size()-1;
        
        int limit=nums[0];
        int count=0;
        int bar=1;
        
        if(nums.size()==1) return 0;
        
        for(int i=0; i<nums.size(); i++){
            
            if(bar<=i){
                count++;
                bar = limit+1;
            }
            
            if(i+nums[i]>limit)
                limit = i+nums[i];
            
            if(limit>=last){
                count++;
                break;
            }
            
        }
        
        return count;
    }
};