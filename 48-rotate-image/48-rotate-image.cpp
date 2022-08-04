/*
-brute force approach 
-take another matrix, take 1st row, add it to the last column ans so on
-tc -> o(n^2)
-sc -> o(n^2)

-optimal approach
-inplace
-find transpose of the matrix
-reverse every row of the matrix
-tc -> o(n^2)
-sc -> o(1) -> inplace
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i =  0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};