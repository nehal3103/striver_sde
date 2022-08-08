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
-sc -> o(1)

-sort the array, find duplicate
-tc -> o(nlogn) + o(n)
-sc -> o(1)
sort(nums.begin(), nums.end());
        int dup = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                dup = nums[i];
            }
        }
        return dup;
        
-better approach
-make a frequency array having n size, initialise with 0
-traverse the given array and update the frequency array as and when the element comes
-if the value of any element in the freq array becomes 2, then that is the duplicate element
-tc -> O(n)
-sc -> o(n)
int n = nums.size();
        int dup = 0;
        int freq[n+1];
        for(int i = 0; i < n+1; i++){
            freq[i] = 0;
        }
        for(int i = 0; i < n; i++){
            if(freq[nums[i]] == 0){
                freq[nums[i]]++;                
            }
            else{
                dup = nums[i];               
            } 
        }
        return dup;
        
-hashmap 
unordered_map<int, int> freq;
        int dup = 0;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }        
        for(int i = 0; i < nums.size(); i++){
            if(freq[i] > 1){
                dup = i;
                break;
            }
        }
        return dup;
-tc -> O(n)
-sc -> o(n)



*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int dup = 0;
        for(int i = 0; i < n; i++){
            int index = abs(nums[i]);
            if(nums[index] > 0)
                nums[index] = -1*nums[index];
            else{
                dup = index;
                break;
            }
        }
        return dup;
    }
};