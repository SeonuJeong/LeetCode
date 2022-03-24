class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int two = nums.size()-1;
        int n = nums.size();
        while(zero<n && nums[zero]==0)
            zero++;
        
        while(two>=0 && nums[two]==2)
            two--;
        
        int i=zero;
        
        while(i<=two){
            
            if(nums[i]==0){
                swap(nums[i],nums[zero]);
            }
            else if(nums[i]==1){
                i++; continue;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[two]);
            }
            
            while(zero<n&&nums[zero]==0)
                zero++;
        
            while(two>=0&&nums[two]==2)
                two--;
            
            if(zero<i && nums[i]==0) continue;            
            else i = max(zero,i+1);
        }
        
    }
};