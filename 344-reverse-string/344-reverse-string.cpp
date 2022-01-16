class Solution {
public:
    void reverseString(vector<char>& s) {
        int le=0, ri=s.size()-1;
        
        while(le<ri){
            swap(s[le],s[ri]);
            le++; ri--;
        }
    }
};