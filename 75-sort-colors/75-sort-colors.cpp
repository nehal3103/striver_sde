/*
-first -> sort the array -> tc -> O(nlogn), sc -> O(1)
class Solution {
public:
    void sortColors(vector<int>& nums){
        sort(nums.begin(), nums.end());
    }
};

-better -> use count sort -> count 0s, 1s, 2s, run loops and insert elements -> tc -> O(n) + O(n)
class Solution {
public:
    void sortColors(vector<int>& nums){
        int countZero = 0;
        int countOne = 0;
        int countTwo = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(nums[i] == 0){
                countZero++;
            }
            else if(nums[i] == 1){
                countOne++;
            }
            else{
                countTwo++;
            }
        }
        for(int i = 0; i < countZero; i++){
            nums[i] = 0;
        }
        for(int i = countZero; i < countOne + countZero; i++){
            nums[i] = 1;
        }
        for(int i = countZero + countOne; i < size; i++){
            nums[i] = 2;
        }
    }
};

-optimized -> Dutch National Flag Algo
-3 pointers to be considered -> low, mid, high
-initially -> low at start, mid at start, high at last
-all numbers to the left of low should be 0
-all numbers to the right of high should be 2
-mid to be moved till it crosses high
-checks - mid pointing to 0, mid pointing to 1, 2
-mid pointing to 0 - swap with low, low++, mid++
-mid pointing to 1 - mid++
-mid pointing to 2 - swap with high, high--
*/

class Solution {
public:
    void sortColors(vector<int>&nums){
        int size = nums.size();
        int low = 0;
        int mid = 0;
        int high = size-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }            
        }
    }
};





