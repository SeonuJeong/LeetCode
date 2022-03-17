class Solution {
public:
    int reverse(int x) {
        int sign=1;
        int maxNum = INT_MAX;
        if(x<0){
            sign=-1;
            maxNum = INT_MIN;
        } 
        
        
        int reves = 0;
        int digit=1;
        
        while(x!=0){
            digit = x%10; x=x/10;
            
            if(sign==1 && ((maxNum-digit)/10 < reves))
                return 0;
            else if(sign==-1 && ((maxNum-digit)/10>reves))
                return 0;
            
            reves *= 10;
            reves += digit;
            
        }
        
        return reves;
    }
};