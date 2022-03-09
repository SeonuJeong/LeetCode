class Solution {
public:
    //03:40
    
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        bool isup=true;
        int y=0, x=0;
        int m=mat.size(), n=mat[0].size();
        vector<int> result;
        
        while(x!=n){
            int tmpY=y;
            int tmpX=x;
            vector<int> v;
            while(y!=-1&&x!=n){
                v.push_back(mat[y][x]);
                y--;
                x++;
            }
            
            if(!isup)
                reverse(v.begin(),v.end());
               
            
            for(int num:v)
                result.push_back(num);
            
            isup = !isup;
            
            y=tmpY; x=tmpX;
            
            if(y==m-1) x++;
            else y++;
        }
        
        return result;
    }
};