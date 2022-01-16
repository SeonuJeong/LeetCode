class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0;
        int odd=0, even=0;
        
        while(i<nums.size()){
            if(i%2==1 && nums[i]%2==0){
                if(odd<i) odd = i;
                
                while(nums[odd]%2==0){
                    odd++;
                }
                
                swap(nums[i],nums[odd]);
            }
            else if(i%2==0 && nums[i]%2==1){
                if(even<i) even = i;
                
                while(nums[even]%2==1){
                    even++;
                }
                
                swap(nums[i],nums[even]);
            }
            
            i++;
        }
        
        return nums;
    }
};