/*pattern of questions:
- no. of rows will be given, print pascal's triangle
- row number will be given, print that particular row of the pascal's triangle -> computing fact for every column will be very costly -> tc would be O(n^2)
- first value of 4th row would be 1, 2nd will be 4C1 i.e. 4/1, 3rd will be 4C2 i.e. (4*3)/(1*2), 4th will be 4C3 i.e. (4*3*2)/1*2*3, 5th will be 4C4 i.e. (4*3*2*1)/(1*2*3*4), so we'll get the row accordingly
tc - n*O(1) ie.e O(n) 
- row no, column no. will be given, print the particular element -> formula -> (r-1)C(c-1) -> O(n)
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++){
            vector<int>v(i+1,1); //size of vector, initialise all to 1            
            for(int j = 1; j < i; j++){
                //current row = i, previous row -> i - 1
                //i = 2 -> [1,1]
                //i = 3 -> [1,2,1]
                v[j] = ans[i-1][j] + ans[i-1][j-1];  
                //sum of above two boxes                
            }
            ans.push_back(v);
        }
        return ans;
    }
};