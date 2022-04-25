class Solution {
public://0920
    int reverse(int x) {
        
        if(x==0)
            return 0;
        
        bool isPositive = x>0;
        
        
        int curVal=0;
        while(x!=0){
            int mrv;
            
            if(isPositive)
                mrv = x%10;
            else
                mrv = (10-(x%10))%10;
            
            x = x/10;
            
            if(isPositive){
                if((INT_MAX-mrv)/10>=curVal)
                    curVal = curVal*10+mrv;
                else
                    return 0;
            }
            else{
                if((INT_MIN+mrv)/(10)<=curVal)
                    curVal = curVal*10-mrv;
                else
                    return 0;
            }
        }
        
        
        return curVal;
    }
};