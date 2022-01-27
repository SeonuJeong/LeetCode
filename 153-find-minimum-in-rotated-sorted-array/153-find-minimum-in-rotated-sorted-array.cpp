class Solution {
public:
    int findMin(vector<int>& nums) {
        //find rotate time
        int le=0, ri=nums.size()-1;
        while(le<ri){
            int mid = (ri+le)/2;
            
            if(nums[mid]>=nums[0]){
                le = mid+1;
            }
            else if(nums[mid]<nums[0]){
                ri = mid;
            }
            
        }
        
        
        if(le!=nums.size()-1 || (nums[0]>nums[le])){
            return nums[le];
        }
        else
            return nums[0];
        
    }
};