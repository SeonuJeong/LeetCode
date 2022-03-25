class Solution {
public:
    
    vector<int> nums;
    int target;
    bool search(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        
        return binary(0,nums.size()-1);
    }
    
    bool binary(int le,int ri){
        
        while(le<=ri){
            
            int mid=(le+ri)/2;
            
            if(nums[mid]==target) return true;
            
            if(nums[mid]==nums[le]){
                le++;
                continue;
            }
            
            if(nums[mid]<target){
                if(nums[le]>nums[mid] && nums[le]<=target)
                    ri = mid-1;
                else
                    le = mid+1;
            }
            else if(nums[mid]>target){
                if(nums[ri]<nums[mid] && nums[ri]>=target)
                    le = mid+1;
                else
                    ri = mid-1;
            }
        }
        
        return false;
    }
};