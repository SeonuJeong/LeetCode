class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0;
        int odd=0, even=0;
        
        vector<int> result(nums.size(),0);
        sort(nums.begin(), nums.end());

        while(i<result.size()){
            
            if(i%2==0){
                while(nums[even]%2!=0){
                    even++;
                }
                result[i++] = nums[even++];
            }
            else{
                while(nums[odd]%2!=1){
                    odd++;
                }
                result[i++] = nums[odd++];
            }
        }
        return result;
    }
};