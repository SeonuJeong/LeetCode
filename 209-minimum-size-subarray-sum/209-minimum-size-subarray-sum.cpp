class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int le=0;
        int minlen=INT_MAX;
        int sum=0;
        
        for(int ri=0; ri<nums.size(); ri++){
            
            sum+=nums[ri];
            
            if(target<=sum){
                minlen = min(minlen, ri-le+1);
                while(le<ri){
                    sum -= nums[le];
                    le++;
                    if(sum<target){
                        break;
                    }
                    else{
                        minlen = min(minlen,ri-le+1);
                    }
                }   
            }
            
        }
        
        return minlen==INT_MAX?0:minlen;
    }
};