class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> result;
        int k = 1;
        while(k<=n){
        int sum=0;
        for(int i=0; i<n;i++){
            sum += nums[i];
            
            if(i==k-1) result.push_back(sum);
    
            if(i>k-1){
                sum = sum - nums[i-k];
                result.push_back(sum);
            }
            
        }//end for(i)
            
        k++;
        }//end while
        
        sort(result.begin(), result.end());
        
        int big = 1000000000 + 7;
        int sum = 0;

        for(int i=left-1; i<right; i++){
            sum += result[i];
            sum = sum % big;
        }
        
        return sum;
    }
};