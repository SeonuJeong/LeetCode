class Solution {
public:
   
    int delta[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};//up,down,left,right
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        dfs(image,sr,sc,newColor,image[sr][sc]);
        
        return image;
    }
    
    void dfs(vector<vector<int>>& image,int row, int col, int newColor, int value){
        if(row<0||row>=image.size()||col<0||col>=image[0].size()||image[row][col]!=value
          ||image[row][col]==newColor)
            return;
        
        image[row][col] = newColor;
        
        dfs(image,row+1,col+0,newColor,value);
        dfs(image,row-1,col+0,newColor,value);
        dfs(image,row+0,col+1,newColor,value);
        dfs(image,row+0,col-1,newColor,value);
        
    }
    
};