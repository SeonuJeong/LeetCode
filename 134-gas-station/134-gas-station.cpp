class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> unit(gas.size(),0);
        
        for(int i=0; i<gas.size(); i++){
            unit[i] = gas[i]-cost[i];
        }
        
        if(gas.size()==1){return unit[0]>=0?0:-1;}
        
        int le=0;
        
        while(le<unit.size()){
            int i=le;
            int sum=0;
            for(int j=0; j<unit.size();j++){
                sum += unit[i%unit.size()];
                i++;
                if(sum<0)
                    break;
            }
            if(sum>=0)
                return le;
            else{
                le=i;
            }
        }
        
        return -1;
    }
};