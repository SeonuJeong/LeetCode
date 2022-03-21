class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            
            int target = nums[i]+k;
            int index = lower_bound(nums.begin()+i+1,nums.end(),target)-nums.begin();
            if(index != nums.size())
                if(nums[index]==target) count++;
            
            if(target == nums[i]-k)
                continue;
            
            target = nums[i]-k;
            index = lower_bound(nums.begin()+i+1,nums.end(),target)-nums.begin();
            
            if(index != nums.size())
                if(nums[index]==target) count++;
            
        }
        
        return count;
        
    }
};