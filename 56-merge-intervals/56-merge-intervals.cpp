class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int mxval=0;
        for(int i=0; i<intervals.size();i++){
            mxval = max(mxval, intervals[i][1]);
        }
        
        vector<int> lestate(mxval+1,0);
        vector<int> ristate(mxval+1,0);
        int left=0, right=0;
        int ledex=0, ridex=0;
        for(int i=0; i<intervals.size();i++){

            lestate[intervals[i][0]] = lestate[intervals[i][0]]-1;
            ristate[intervals[i][1]] = ristate[intervals[i][1]]+1;
            
        }
        
        
        for(int i=0; i<lestate.size(); i++){
            
            if(lestate[i]<0 && left==0)
                ledex = i;
            
            if(ristate[i]>0 && right>=0)
                ridex = i;
            
            if(lestate[i]<0)
                left += lestate[i];
            
            if(ristate[i]>0)
                right += ristate[i];
            
            
            if(abs(left) == right && left!=0 && right!=0){
                result.push_back(vector<int>(2,0));
                result.back()[0] = ledex;
                result.back()[1] = ridex;
                left=0; right=0;
                ledex=0; ridex=0;
            }
        }
        
        return result;
    }
};