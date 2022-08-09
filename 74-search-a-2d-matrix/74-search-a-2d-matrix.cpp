/*
-brute force
-linearly traverse the m*n matrix, search for target
-if target present -> true
-if not present -> false




*/






class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans = false;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == target){
                    ans = true;
                }
            }
        }
        return ans;
        
    }
};