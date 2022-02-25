class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int left=0, right=nums.size()-1;
        
        
        while(left<right){
            
            int mid = (right+left)/2;
            
            int up = upper_bound(nums.begin()+left, nums.begin()+right, nums[mid])-nums.begin();
            int lo = lower_bound(nums.begin()+left, nums.begin()+right, nums[mid])-nums.begin();
            
            if((up-lo==1 && nums[up]!=nums[lo]) || (up-lo==0 && nums[up]==nums[lo])){
                left = lo;
                break;
            }
            
            if((lo-left)%2==0)
                left = up;
            else
                right = lo-1;
        }
        
        return nums[left];
        
    }
};