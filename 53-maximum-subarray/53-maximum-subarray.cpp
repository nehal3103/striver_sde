/*
KADANE'S ALGO

-brute force
-find all sub arrays, find sum, find max sum
-tc -> o(n^2)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum = sum + nums[j];
                if(sum > max){
                    max = sum;
                }
            }
        }
        return max;
    }
};
*/

class Solution {
public:    
    int maxSubArray(vector<int>& nums){
        int maxSum = INT_MIN;
        int currSum = 0;
        for(int i = 0; i < nums.size(); i++){
            currSum = currSum + nums[i];
            if(currSum > maxSum){
                maxSum = currSum;
            }
            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};


