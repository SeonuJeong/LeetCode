class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int le=0, ri=numbers.size()-1;
        vector<int> result;
        while(le<ri){
            int sum = numbers[le]+numbers[ri];
            if(sum>target)
                ri--;
            else if(sum<target)
                le++;
            else
                break;
        }
        
        result.push_back(le+1);
        result.push_back(ri+1);
        
        return result;
    }
};