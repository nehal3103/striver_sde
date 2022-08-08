/*
-brute force
-make a third array having size equal to the sum of sizes of the two arrays given
-copy the elements from 1st and 2nd array to the third array
-sort the third array
-copy the elements from the third array back to the first and second array
int array[m+n];
        int i = 0, j = 0, k = 0;
        while(i < m && j < n){
            if(nums1[i]<nums2[j]){
                array[k] = nums1[i];
                i++;
                k++;
            }
            if(nums1[i]>nums2[j]){
                array[k] = nums2[j];
                j++;
                k++;
            }
        }
        while(i < m){
            array[k] = nums1[i];
            i++;
            k++;
        }
        while(j < n){
            array[k] = nums2[j];
            j++;
            k++;
        }
        i = 0;
        while(i < m+n){
            nums1[i] = array[i];
        }

-other approach
-insertion sort
-both arrays are already sorted
-lineraly traverse in both the arrays
-compare element wise
-swap if bigger, sort the other

{
        int i = 0; 
        while(i != m){
            if(nums1[i] < nums2[0]){
                i++;
            }
            else{
                int temp = nums1[i];
                nums1[i] = nums2[0];
                nums2[0] = temp;                
                sort(nums2.begin(), nums2.end());
            }
        }
        
    }
-tc -> o(m+n)
-sc -> o(n+m)

-two pointer
-i -> points to nums1[m-1]
-j -> points to the end of array2
-k -> points to the end of array1
-put the larger at kth place, k--, larger value pointer--
-tc -> o(m+n)
-sc -> o(1)
*/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }
        while(i >= 0){
            nums1[k--] = nums1[i--];
        }
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }  
};