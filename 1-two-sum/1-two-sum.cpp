/*
-brute force
-tc - o(n^2)
-sc - o(n1)
int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(j != i && nums[i]+nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(indices.find(target-nums[i])!=indices.end()){
                return{indices[target-nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};