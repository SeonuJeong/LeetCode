class Solution {
public:
    // 09:00
    bool backspaceCompare(string s, string t) {
        int scur=s.length();
        int tcur=t.length();
        
        int sc=0,tc=0;
        
        while(scur>=0 || tcur>=0){
            
            while(scur>=0 && (sc>0 || s[scur]=='#')){
                if(s[scur]=='#'){
                    sc++;
                    scur--;
                }
                else{
                    scur--;
                    sc--;
                }

            }
            
            while( tcur>=0 &&(tc>0 || t[tcur]=='#')){
                if(t[tcur]=='#'){
                    tc++;
                    tcur--;
                }
                else{
                    tcur--;
                    tc--;
                }
            }
            
            if(scur<0 && tcur<0){
                return true;
            }
            else if(scur<0||tcur<0){
                return false;
            }
            else if(s[scur]!=t[tcur]){
                return false;
            }
            scur--; tcur--;
        }
        
        return true;
    }
};