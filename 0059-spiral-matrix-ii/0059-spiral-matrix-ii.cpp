class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> mat(n,vector<int>(n));
      int startRow = 0,startCol = 0,endRow = n-1,endCol = n-1;
      int x = 1;
      while(startRow <= endRow && startCol <= endCol){
        for(int i = startCol; i <= endCol; i++){
            mat[startRow][i] = x;
            x++;
        }
        startRow++;
        for(int i = startRow; i <= endRow; i++){
            mat[i][endCol] = x;
            x++;
        }
        endCol--;
        for(int i = endCol; i >= startCol; i--){
            mat[endRow][i] = x;
            x++;
        }
        endRow--;
        for(int i = endRow; i >= startRow; i--){
            mat[i][startCol] = x;
            x++;
        }
        startCol++;
      }
    return mat;    
    }
};