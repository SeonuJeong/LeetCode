class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        int i=0, j=s.length()-1;
        
        while(i<j){
            if(!('a'<=s[i]&&s[i]<='z')&&!('A'<=s[i]&&s[i]<='Z'))
                i++;
            else if(!('a'<=s[j]&&s[j]<='z')&&!('A'<=s[j]&&s[j]<='Z'))
                j--;
            else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
                
        }
        
        return s;
    }
};