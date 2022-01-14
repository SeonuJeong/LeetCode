class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int mid=0;
        int size = nums.size();
        while(nums[mid]<0){
            mid++;
            if(mid == size)
                break;
        }
        
        int left=mid-1;
        int right=mid;
        
        while(right-left<=size){
            
            int leftval = left<0?INT_MAX:abs(nums[left]);
            int rightval = right==size?INT_MAX:nums[right];
            
            if(leftval < rightval){
                result.push_back(leftval*leftval);
                left = left<0?left:left-1;
            }
            else{
                result.push_back(rightval*rightval);
                right = right==size?right:right+1;
            }
            
        }
        
        return result;
    }
};