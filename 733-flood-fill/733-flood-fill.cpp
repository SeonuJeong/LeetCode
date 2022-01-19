class Solution {
public:
    vector<vector<int>> visited;//m*n
    int delta[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};//up,down,left,right
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(); // row
        int n = image[0].size(); //column
        visited.assign(m,vector<int>(n,0));
        floodFill(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
    
    void floodFill(vector<vector<int>>& image,int row, int col, int newColor, int value){
        if(row<0||row>=image.size()||col<0||col>=image[0].size())
            return;
        if(visited[row][col]!=0)
            return;
        if(image[row][col]!=value)
            return;
        
        visited[row][col] = 1;
        image[row][col] = newColor;
        for(int i=0;i<4;i++){
            floodFill(image,row+delta[i][0],col+delta[i][1],newColor,value);
        }
        
    }
    
};