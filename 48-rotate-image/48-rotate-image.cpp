class Solution {
public:
    //02:37

    int N;
    void rotate(vector<vector<int>>& matrix) {
        N = matrix.size()-1;
        
        for(int i=0;i<=N/2; i++){
            int tmp;
            for(int j=i; j<=(N-1-i); j++){
                convert(i,j,matrix);
            }
        }
        
    }
    
    void convert(int firstrow, int firstcol, vector<vector<int>>& matrix){
        
        int before=matrix[firstrow][firstcol];
        int after;
        int row = firstrow;
        int col = firstcol;
        for(int i=0; i<4; i++){
            int nextrow = col;
            int nextcol = N-row;
            
            after = matrix[nextrow][nextcol];;
            matrix[nextrow][nextcol] = before;
            
            before = after;
            
            col = nextcol;
            row = nextrow;
        }
        
    }
    
    
};