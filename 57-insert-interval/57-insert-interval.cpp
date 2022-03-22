class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> result;
        
        int i=0;
        
        int nf = newInterval[0];
        int firstVal= nf;
        while(i<intervals.size()){
            int of = intervals[i][0];
            int ol = intervals[i][1];
            
            
            if(nf > ol){
                vector<int> v = {of, ol};
                result.push_back(v);
                i++;
            }
            else{
                firstVal = min(nf,of);  
                break;
            }
        }
        
        int nl = newInterval[1];
        int lastVal=nl;
        while(i<intervals.size()){
            int of = intervals[i][0];
            int ol = intervals[i][1];
            

            if(nl > ol){
                i++;
                continue;
            }
            else if(nl < of){
                lastVal = nl;
                break;
            }
            else{
                i++;
                lastVal = ol;
                break;
            }
        }
        
        vector<int> overlap = {firstVal, lastVal};
        result.push_back(overlap);
        
        for( ; i<intervals.size();i++){
            int of = intervals[i][0];
            int ol = intervals[i][1];
            vector<int> v = {of, ol};
            result.push_back(v);
        }
        
        return result;
    }
    
    
};