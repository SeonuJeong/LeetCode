class Solution {
public:
    int maxArea(vector<int>& height) {
        int le=0, ri=height.size()-1;
        int result=0;
        
        while(le<ri){
            
            result = max(result , (ri-le)*(min(height[ri],height[le])) );
            
            if(height[le]<height[ri])
                le++;
            else
                ri--;
            
        }
        
        return result;
    }
};