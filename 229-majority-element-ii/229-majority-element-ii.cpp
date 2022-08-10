/*
-brute force
-linearly traverse every element, if it appears more than n/3 times, it is one of the majority elements
-tc - > o(n^2)
-sc -> o(1)
int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
            if(count > n/3){
                int count2 = std::count(ans.begin(), ans.end(), nums[i]);
                if(count2 == 0){
                    ans.push_back(nums[i]);                                             
                }
            }
        }
        return ans;

-hashmap
-make a freq hashmap
-check if freq>n/3 return those elements
-tc -> o(n)
-tc -> o(n)
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

-moore's voting algo
-iterate over all the elements
-initialise num1, num2 = -1, count1, count2 = 0
-find the two maj elements
-check if their count > n/3
-tc->o(n)
-sc->o(1)

*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int num1 = -1;
        int num2 = -1;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == num1){
                count1++;
            }
            else if(nums[i] == num2){
                count2++;
            }
            else if(count1 == 0){
                num1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        int c1 = 0;
        int c2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == num1){
                c1++;
            }
            else if(nums[i] == num2){
                c2++;
            }
        }
        if(c1 > n/3){
            ans.push_back(num1);
        }
        if(c2 > n/3){
            ans.push_back(num2);
        }
        return ans;
    }
};