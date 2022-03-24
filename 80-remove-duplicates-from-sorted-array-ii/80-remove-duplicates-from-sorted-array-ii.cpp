class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int  j=1;
        int len=1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]==nums[i])
                len++;
            else
                len=1;
            
            if(len<=2)
                nums[j++] = nums[i];
        }
        
        return j;
    }
};