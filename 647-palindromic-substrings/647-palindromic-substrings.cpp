class Solution {
public:
    
    string s;
    int countSubstrings(string s) {
        this->s = s;
        int total=0;
        for(int i=0; i<s.length(); i++)
            total += dfs(i);
        
        return total;
    }
    
    int dfs(int index){
        
        int count=0;
        for(int i=index; i<s.length(); i++){
            if(!checkPalindrome(index,i)) continue;
            
            count++;
        }
        
        return count;
    }
    
    bool checkPalindrome(int le,int ri){
        while(le<ri){
            if(s[le]!=s[ri])
                return false;
            
            le++; ri--;
        }
        return true;
    }
};