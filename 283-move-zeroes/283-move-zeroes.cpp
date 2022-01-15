class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int le=0, ri=0;
        
        while(ri<nums.size()&&le<nums.size()){
            if(nums[le]==0&&nums[ri]!=0){
                iter_swap(nums.begin()+le, nums.begin()+ri);
            }
            else if(nums[le]==0&&nums[ri]==0){
                ri++;
            }
            else{
                le++;
                ri++;
            }
        }
    }
};