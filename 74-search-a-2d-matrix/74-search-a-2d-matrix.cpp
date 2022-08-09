/*
-brute force
-linearly traverse the m*n matrix, search for target
-if target present -> true
-if not present -> false
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
-tc -> o(m*n)
-sc -> o(1)

-next approach
-go to all the rows, do binary search on each row
-return true if found, false if not found
-tc -> n * logm 

-optimal solution
-the pointer should be at the last element of the first row
-if found, return true
-if target > elemet -> go downwards
-if target < element, go towards the left
-tc->o(n);
-sc->o(n);
 int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        int j = m-1;
        while(i < n && j >= 0){
            int element = matrix[i][j];
            if(target == element){
                return true;
            }
            if(target > element){
                i++;
            }
            else{
                j--;
            }
        }
        return false;      
    }
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0; 
        int high = m*n-1;
        while(low <= high){
            int mid = (low + high)/2;
            int rowIndex = mid/m;
            int colIndex = mid%m;
            int element = matrix[rowIndex][colIndex];
            if(target == element){
                return true;
            }
            if(target > element){
                low = mid + 1;
            }
            if(target < element){
                high = mid - 1;
            }
        }   
        return false;
    }
};