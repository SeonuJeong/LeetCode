class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3)
            return false;
        
        int le=0, ri=arr.size()-1;
        
        while(le<ri){
            
            bool ch=false;
            
            if(arr[le+1]>arr[le]){
                le++;
                ch = true;
            }
            
            if(arr[ri-1]>arr[ri]){
                ri--;
                ch = true;
            }
            
            if(!ch)
                break;
        }
        
        if(le==ri && (le!=0) && (ri!=arr.size()-1))
            return true;
        else
            return false;
    }
};