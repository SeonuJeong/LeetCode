class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> stk;
        vector<int> result(temperatures.size(),0);
        
        for(int i=0; i<temperatures.size(); i++){
            
            while(!stk.empty()&&temperatures[stk.back()]<temperatures[i]){
                result[stk.back()] = i-stk.back();
                stk.pop_back();
            }
            stk.push_back(i);
        }
        
        return result;
    }
};