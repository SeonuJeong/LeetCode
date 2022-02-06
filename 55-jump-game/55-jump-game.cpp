class Solution {
public:
    //03:44
    //03:58
    vector<int> cache;
    int N;
    vector<int> nums;
    bool canJump(vector<int>& nums) {
        cache.assign(nums.size(),-1);
        N = nums.size();
        this->nums = nums;
        
        return dp(0);
    }
    
    bool dp(int index){
        
        if(index>=N-1){
            return true;
        }
        
        if(cache[index]!=-1)
            return cache[index];
        
        bool result=false;
        for(int i=nums[index]; i>0; i--){
            if(dp(index+i)){
                result = true;
                break;
            }
        }
        
        if(result==true) cache[index] = 1;
        else cache[index] = 0;
        
        return result;
        
    }
};