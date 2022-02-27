class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int sum;
        if(target<0)
            sum = 10000;
        else
            sum = -10000;
        
        for(int i=0; i<nums.size()-2; i++){
            for(int j=i+1; j<nums.size()-1; j++){
                int tmp = nums[i]+nums[j];
                int index = lower_bound(nums.begin()+j+1,nums.end(),target-tmp)
                    - nums.begin();
                
                if(nums.size()==index)
                    index--;
                    
                if(index!=j+1)
                    if(abs(target-sum)>abs(target-tmp-nums[index-1]))
                        sum = tmp+nums[index-1];
                
                if(abs(target-sum)>abs(target-tmp-nums[index]))
                        sum = sum = tmp+nums[index];

            }
        }
        
        return sum;
    }
    
};