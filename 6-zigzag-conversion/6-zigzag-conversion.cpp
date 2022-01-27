class Solution {
public:
    string convert(string s, int numRows) {
        int total = numRows*2 - 2;
        
        if(s.length()==1 || numRows==1) return s;
        
        int dp[2] = {total,0};
        int k=0;
        string str="";
        int row=0;
        int i=0;
        while(row<numRows && row<s.length()){
            
            str += s.substr(k,1);
            
            if(i%2==0){
                
                if(dp[0]==0)
                    k += dp[1];
                else
                    k += dp[0];
            }
            else{
                if(dp[1]==0)
                    k += dp[0];
                else
                    k += dp[1];
            }
            
            i++;
            
            if(k>=s.length()){
                k = ++row;
                dp[0] -= 2;
                dp[1] += 2;
                i = 0;
            }
            
            
            
        }
        
        return str;
        
    }
};