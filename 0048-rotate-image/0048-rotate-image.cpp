class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans;
        int startrow = 0,startcol = 0,endrow = n-1,endcol = n-1;
        while(startcol <= endcol && startrow <= endrow){
        for(int i = startcol; i <= endcol; i++)
            ans.push_back(matrix[startrow][i]);
        startrow++; 
        for(int i = startrow; i <= endrow; i++)
            ans.push_back(matrix[i][endcol]);
        endcol--;       
        for(int i = endcol; i >= startcol; i--)
            ans.push_back(matrix[endrow][i]);
        endrow--;    
        for(int i = endrow; i >= startrow; i--)
            ans.push_back(matrix[i][startcol]);
        startcol++;  
        } 

        int j = 0;startrow = 0,startcol = 0,endrow = n-1,endcol = n-1;
        while(startcol <= endcol && startrow <= endrow){
        for(int i = startrow; i <= endrow; i++)
            matrix[i][endcol] = ans[j++];
        endcol--; 
        for(int i = endcol; i >= startcol; i--)
            matrix[endrow][i] = ans[j++];
        endrow--;       
        for(int i = endrow; i >= startrow; i--)
            matrix[i][startcol] = ans[j++];
        startcol++;   
        for(int i = startcol; i <= endcol; i++)
            matrix[startrow][i] = ans[j++];
        startrow++;  
        }             
    }
};