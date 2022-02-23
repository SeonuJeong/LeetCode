class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        
        int mx=INT_MIN;
        vector<int> result;
        for(int i=heights.size()-1 ; i>=0; i--){
            if(heights[i]>mx)
                result.push_back(i);
            
            mx = max(mx,heights[i]);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};