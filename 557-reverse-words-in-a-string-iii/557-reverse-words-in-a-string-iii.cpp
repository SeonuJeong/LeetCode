class Solution {
public:
    string reverseWords(string s) {
        int le=0;
        
        for(int i=0; i<s.length(); i++){
            bool flag = false;
            if(i+1 == s.length()) flag = true;
            else if(s[i+1] == ' ') flag = true;
            
            if(flag){
                int _i = i;
                while(le<_i){
                    swap(s[le],s[_i]);
                    le++; _i--;
                }
                le = i+2;
            }
        }
        return s;
    }
};