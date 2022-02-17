class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int count=1;
        int num;
        for(int i=nums.size()-1; i>=0 ; i--){
            if(k==count){
                num = nums[i];
            }
            count++;
        }
        
        return num;
    }
};