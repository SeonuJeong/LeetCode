class Solution {
public:
    bool isPalindrome(int x) {
       
        if(x<0)return false;
        if(x==0)return true;
        
        int tmp=x;
        vector<int> pv;
        while(tmp!=0){
            pv.push_back(tmp%10);
            tmp = tmp/10;
        }
        
        vector<int> ori = pv;
        
        reverse(ori.begin(),ori.end());
        
        for(int i=0; i<pv.size(); i++){
            if(pv[i]!=ori[i]) return false;
        }
        return true;
    }
};