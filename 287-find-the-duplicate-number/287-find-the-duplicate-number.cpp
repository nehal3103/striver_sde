/*
-brute 
int length = nums.size();
        int dup = 0;
        for(int i = 0; i < length; i++){
            for(int j = 0; j < length; j++){
                if(j != i){
                    if(nums[i] == nums[j]){
                        dup = nums[i];
                    }
                }
            }
        }
        return dup;   
-tc -> o(n^2)

-sort the array, find duplicate
-tc -> o(nlogn) + o(n)

*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int dup = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                dup = nums[i];
            }
        }
        return dup;
    }
};