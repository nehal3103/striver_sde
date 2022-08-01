/*brute force:
-keep on traversing in the matrix, whenever you get a zero, traverse for its entire row + column, place value which is not a part of the matrix(-1 for matrix with 0s and 1s)
-whenever there is a zero, dont change it -> might be a part of some other row or column
-if you change it to -1, then other values wont be changed to 0
-tc -> (n*m)*(n+m) 
n*m for traversing
n+m for traversing each row and column for every zero
-sc -> o(1) -> changes are made to the given array only

better approach
-take 2 dummy arrays, one having size = no. of rows, other having size = number of columns
-traverse lineary in the 2d matrix
-whenever 0 is found, set 0 in the column index + row index
-traverse again linearly, if any index in row or column array corresponding to the element is 0, set the element in the matrix to 0
-tc = 2* o(n*m) -> traversal twice
-sc = o(n) + o(m) -> two dummy arrays used

optimized approach
-take 1st row as column dummy matrix
`take 1st column as row dummy matrix
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();  //length of row
        int m = matrix[0].size(); //length of col
        bool col = true;
        bool row = true;
        for(int i = 0; i < n; i++){
            if(matrix[i][0]==0){
                col = false;
            }
        }   
        for(int j = 0; j < m; j++){
            if(matrix[0][j]==0){
                row = false;
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(col == false){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
        if(row == false){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }
    }
};


// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix){
//         int n = matrix.size(); //length of row
//         int m = matrix[0].size(); //length of col
//         int row[n]; //dummy array having length = n
//         int col[m]; //dummy array having length = m
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(matrix[i][j] == 0){
//                     row[i] = 0;
//                     col[j] = 0;
//                 }
//             }
//         }
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(row[i]==0 || col[j]==0){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
//     }    
// };