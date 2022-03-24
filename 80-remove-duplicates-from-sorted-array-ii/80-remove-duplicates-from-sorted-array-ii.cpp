class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, j=1;
        int len=1;

        for( ; j<nums.size(); i++,j++){
            
            if(nums[i-1]==nums[j])
                len++;
            else
                len=1;
            
            if(len<=2){
                swap(nums[i],nums[j]);
                continue;
            }
            
            while(j<nums.size()&&nums[i-1]==nums[j])
                j++;
            
            len=1;
            if(j<nums.size())swap(nums[i],nums[j]);
            else break;
        }
        
        return i;
    }
};