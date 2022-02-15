class Solution {
public:
    // 07:42
    
    string s;
    bool validPalindrome(string s) {
        this->s = s;
        
        return recursive(0,s.length()-1,0);
    }
    
    bool recursive(int le,int ri, int dlt){
        
        
        if(le>=ri){
            return true;    
        }
        
        if(s[le]==s[ri]){
            return recursive(le+1, ri-1, dlt);
        }
        else if(dlt==0){   
            return recursive(le+1, ri, dlt+1)||recursive(le, ri-1, dlt+1);
        }
        else{
            return false;
        }
        
    }
};