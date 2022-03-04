class Solution {
public:
    
    vector<vector<int>> cache;
    vector<int> nums;
    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums=nums;
        
        int total=0;
        for(int num:nums){
            total += num;
        }
        
        
    
        if(total>=target){
            cache.assign(nums.size(),vector<int>(total-target+1,-1));
            return dp(nums.size()-1,total-target);
        }
        else{
            cache.assign(nums.size(),vector<int>(total+target+1,-1));
            return dp(nums.size()-1,total+target);
        }
    }
    
    int dp(int index, int sub){
        
        if(index<0)
            return sub==0?1:0;
        
        if(cache[index][sub]!=-1)
            return cache[index][sub];
        
        int val = sub - nums[index]*2;
        
        int count=0;
        if(val>=0)
            count += dp(index-1,val);
        
        count += dp(index-1,sub);
        
        cache[index][sub] = count;
        return count;
    }
};