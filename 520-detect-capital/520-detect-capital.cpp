class Solution {
public:
    bool detectCapitalUse(string word) {
      
        if(word.length()==1)
            return true;
        
        bool isCapital = false;
        if(word[1]>='A'&&word[1]<='Z')
            isCapital = true;
        
        for(int i=1; i<word.length(); i++){
            if(word[i]>='A'&&word[i]<='Z'){
                if(!isCapital)
                    return false;
            }
            else{
                if(isCapital)
                    return false;
            }
        }
        
        if(isCapital)
            if(word[0]>='a'&&word[0]<='z')
                return false;
        
        return true;
    }
};