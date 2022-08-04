/*
-brute force:
-sort the array, find the consecutive sequences, maintain maxLength, return maxLength
-tc -> nlogn + O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 0){
            return nums.size();
        }
        sort(nums.begin(), nums.end());
        int maxLength = INT_MIN;
        int currLength = 1;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i+1] == nums[i]+1){
                currLength++;
                maxLength = max(currLength, maxLength);
            }
        }
        return maxLength;
    }
};

-optimal solution
-linearly iterate in the array, put all elements in hashset
-linearly iterate in the array, check if i-1 exists for every i in hashmap, interate over next -> we need to start from the minimal number
-if it doesn't exist, check if i+1 exists, if it exists, check for i + 1, maintain length
-return length(max)
-tc -> o(n) + o(n) + o(n) -> o(n)
-sc -> o(n)

*/
/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet;
        for(int i = 0; i < nums.size(); i++){
            hashSet.insert(nums[i]);
        }
        int longestSequence = 0;
        for(int i = 0; i < nums.size(); i++){
            if(hashSet.count(nums[i]-1)==0){
                int currentNum = nums[i];
                int currentSequence = 1;
                while(hashSet.count(currentNum+1)){
                    currentNum++;
                    currentSequence++;
                }
                longestSequence = max(currentSequence, longestSequence);
            }
        }
        return longestSequence;
    }
};*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxLength = 1;
        int currLength = 1;
        if(nums.size() == 0){
            return 0;
        }
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1] + 1){
                currLength++;
            }
            else if(nums[i]-nums[i-1]>1){
                currLength=1;
            }
            maxLength = max(currLength, maxLength);
        }
        return maxLength;
    }
};


