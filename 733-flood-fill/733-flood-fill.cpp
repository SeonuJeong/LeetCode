class Solution {
public:
   
    int delta[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};//up,down,left,right
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor)
            floodFill(image,sr,sc,newColor,image[sr][sc]);
        
        return image;
    }
    
    void floodFill(vector<vector<int>>& image,int row, int col, int newColor, int value){
        if(row<0||row>=image.size()||col<0||col>=image[0].size()||image[row][col]!=value)
            return;
        
        image[row][col] = newColor;
        for(int i=0;i<4;i++){
            floodFill(image,row+delta[i][0],col+delta[i][1],newColor,value);
        }
        
    }
    
};