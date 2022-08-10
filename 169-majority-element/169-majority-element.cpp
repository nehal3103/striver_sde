
/*
-brute approach
-count occurances for all the elements using nested loops
-tc->o(n^2)
-sc->o(1)
int maxCount = 0;
        int index = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]){
                count++;
                }                
            }            
            if(count > maxCount){
                maxCount = count;
                index = i;
            }
        }
        return nums[index];

-better approach
-sorting and returning the element present at the middle
-tc - o(nlogn)
-sc - o(1)
sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
        
-linear tc approach
-using hashmaps
-tc - o(n)
-sc - o(n)

*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }
        int maj = nums[0];
        for(auto i:freq){
            if(i.second>n/2){
                maj = i.first;
            }
        }
        return maj;
    }
};