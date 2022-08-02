/* dictionary orders of 132 -> 123, 132, 213, 231, 312, 321

brute approach:
-generate all possible approaches
-iterate linearly, find the number, check the next permutation
-tc -> n!*n -> n! is the number of orders, n is the length of array

optimized approach
-traverse from the back, while traversing find index i such that a[i] < a[i+1]
-if no element is found, just reverse the complete number
-traverse from back, find index having value greater than element placed at the index found in the last step
-swap both indexes
-reverse everything to the right of index found in first step  + 1
-tc -> o(n) + o(n) + o(n) -> o(n)
-sc -> o(1)

123
132
213
231
312
321
*/

class Solution {

public:
    void nextPermutation(vector<int>& nums) {
        int i;
        int j;
        int n = nums.size();  //number of elements in the vector
        if(n==1){
            return;
        }
    
        for( i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                break;
            }
        }  
        if(i<0){
            reverse(nums.begin(), nums.end());
        }
        else{
            for(j = n-1; j >= 0; j--){
                if(nums[j] > nums[i]){
                    break;
                }
            }
            //swap
            swap(nums[i], nums[j]);            
            //reverse everything to the right of index
            reverse(nums.begin()+i+1,nums.end());           
        }             
    }
};