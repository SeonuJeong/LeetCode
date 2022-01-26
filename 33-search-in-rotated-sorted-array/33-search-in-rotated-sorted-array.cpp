class Solution {
public:
    int search(vector<int>& nums, int target) {
        int le=0, ri=nums.size()-1;
        
        bool isLeft;
        
        if(target>=nums[le])
            isLeft = true;
        else
            isLeft = false;
    
        
        while(le<=ri){
            
            int mid = (le+ri)/2;
            
            if(nums[mid]==target) return mid;
            
            if(nums[mid]<=nums[nums.size()-1] && isLeft==true && nums[0]>nums[nums.size()-1]){ // B에 속하면서 isLeft TRUE
                ri = mid-1;
            }
            else if(nums[mid]>=nums[0] && isLeft == false && nums[0]>nums[nums.size()-1]){
                le = mid+1;
            }
            else{
                if(nums[mid]>target) ri=mid-1;
                if(nums[mid]<target) le=mid+1;
            }
            
        }
        
        return -1;
    }
};