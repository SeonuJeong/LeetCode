class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0, col=0;
        
        while(row<matrix.size() && col<matrix[0].size()){
            
            if(matrix[row][col]==target)
                return true;
            
            if(row+1 == matrix.size() && col+1 == matrix[0].size()){
                break;
            }
            else if(row+1 == matrix.size()){
                col++;
            }
            else if(col+1 == matrix[0].size()){
                row++;
            }
            else{
                if( (target >= matrix[row][col+1]) && (target < matrix[row+1][col]) ){
                    col = col+1;
                }
                else if( (target >= matrix[row+1][col])  ){
                    row = row+1;
                }
                else
                    break;
            }
            
        }
        
        return false;
        
    }
};