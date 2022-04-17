class Solution {
public://1120
    
    vector<int> nums;
    
    int threeSumSmaller(vector<int>& nums, int target) {
        
        
        if(nums.size()<3)
            return 0;
        
        sort(nums.begin(),nums.end());
        this->nums= nums;
        
        
        int result=0;
        
        for(int i=0; i<nums.size()-2; i++){
            int t = target-nums[i];
            result += twoSumSmaller(i+1, t);
        }
        
        return result;
    }
    
    int twoSumSmaller(int le, int target){
        
        int result=0;
        for(int i=le; i<nums.size()-1; i++){
            
            int t = target-nums[i];
            
            int index;
            
            
            index = lower_bound(nums.begin()+i+1,nums.end(),t)-nums.begin();
            index--;
            result += index-i;
            
                
        }
        
        return result;
    }
};