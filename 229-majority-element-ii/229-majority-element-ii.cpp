/*
-brute force
-linearly traverse every element, if it appears more than n/3 times, it is one of the majority elements
-tc - > o(n^2)
-sc -> o(1)

-hashmap
-make a freq hashmap
-check if freq>n/3 return those elements
-tc -> o(n)
-tc -> o(n)

-

*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }
        vector<int>ans;
        for(auto i: freq){
            if(i.second > n/3){
                ans.push_back(i.first);
            }            
        }
        return ans;
    }
};