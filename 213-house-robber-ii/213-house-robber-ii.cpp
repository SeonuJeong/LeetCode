class Solution {
public:
    
    vector<vector<int>> cache;
    int N;
    vector<int> nums;
    int rob(vector<int>& nums) {
        this->nums = nums;
        N = nums.size();
        cache.assign(N,vector<int>(N,-1));
        
        if(N==1)
            return nums[0];
        
        return max(dp(0,N-2),dp(1,N-1));
    }
    
    
    int dp(int le, int ri){
        if(le==ri){
            return nums[le];
        }
        
        if(le>ri){
            return 0;
        }
        
        if(cache[le][ri]!=-1)
            return cache[le][ri];
        
        
        cache[le][ri] = max(nums[le]+dp(le+2,ri), dp(le+1,ri));
        
        return cache[le][ri];
    }
    
};