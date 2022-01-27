class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int le=0, ri=nums.size()-1;
        
        while(le<ri){
            
            int mid = (ri+le)/2;
            
            if((mid==0 ||(nums[mid] > nums[mid-1]))&&(mid==nums.size()-1||(nums[mid]>nums[mid+1])) ) // peak
                return mid;
            else if(mid==0 || nums[mid]<nums[mid+1]){
                le=mid+1;
            }
            else if(mid==nums.size()-1 || nums[mid]<nums[mid-1]){
                ri=mid-1;
            }
        }
        
        return le;
    }
};