class Solution {
public:
    //1050
    
    bool isOneEditDistance(string s, string t) {
        int situ=-1;
        string longest,shortest;
        if(s.length()+1==t.length()){
            situ=0;
            longest = t;
            shortest =s;
        }
        if(s.length()==t.length()+1){
            situ=1;
            longest = s;
            shortest =t;
        }
        if(s.length()==t.length()&&s!=t){
            situ=2;
            longest = s;
            shortest = t;
        }
        if(situ==-1) return false;
        
        int count=0;
        for(int i=0; i<longest.length(); i++){
            
            if(situ!=2&&longest[i]!=shortest[i-count]){
                count++;
            }
            else if(situ==2&&longest[i]!=shortest[i]){
                count++;
            }
            
            if(count>1)
                return false;
        }
        
        return true;
    }
};