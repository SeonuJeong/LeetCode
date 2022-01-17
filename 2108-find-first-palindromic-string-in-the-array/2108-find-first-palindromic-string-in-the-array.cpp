class Solution {
public:
    string firstPalindrome(vector<string>& words) {
       for(int i=0;i<words.size(); i++){
           int le=0, ri=words[i].length()-1;
           
           while(le<ri){
               if(words[i][le]!=words[i][ri]){
                   break;
               }
               else{
                   le++; ri--;
               }
            }
           
            if(le>=ri)
                return words[i];
       }
        
        return "";
    }
};