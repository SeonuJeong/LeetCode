class Solution {
public:
    vector<vector<int>> cache;
    int height;
    vector<vector<int>> _triangle;
    int minimumTotal(vector<vector<int>>& triangle) {
        height = triangle.size();
        _triangle = triangle;

        cache.assign(height,vector<int>(0));
        for(int i=0; i<height; i++){
            cache[i].assign(i+1,-1);
        }
        
        return func(0,0);
        
    }
    
    int func(int row, int col){
        
        if(row==height-1)
            return _triangle[row][col];
        
        if(cache[row][col]!=-1)
            return cache[row][col];
        cache[row][col] = min(func(row+1,col),func(row+1,col+1))+_triangle[row][col];
        return cache[row][col];
    }
};