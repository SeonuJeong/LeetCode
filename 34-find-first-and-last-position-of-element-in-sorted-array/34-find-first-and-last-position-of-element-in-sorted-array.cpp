class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        
        int le = 0, ri = nums.size()-1;
        int mid;
        
        if(nums.size()==0)
            return result;
        
        while(le<=ri){
            
            mid = (ri+le)/2;
            
            if(nums[mid]>target) ri = mid-1;
            else if(nums[mid]<target) le=mid+1;
            else if(nums[mid]==target) break;
            
        }
        
        int _ri = mid;
        while(le<=_ri){
            int _mid = (le+_ri)/2;
            
            if(nums[_mid]>target) _ri = _mid-1;
            else if(nums[_mid]<target) le = _mid+1;
            else if(nums[_mid]==target){ 
                result[0] = _mid;
                result[1] = _mid;
                _ri = _mid-1;
            }
        }
        
        
        int _le = mid;
        while(_le<=ri){
            int _mid = (_le+ri)/2;
            
            if(nums[_mid]>target) ri = _mid-1;
            else if(nums[_mid]<target) _le = _mid+1;
            else if(nums[_mid]==target) {
                result[1] = _mid;
                _le = _mid+1;
            }
        }
        
        return result;
    }
};