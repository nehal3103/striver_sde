/*
-first, we should check if the intervals given to us are in sorted order or not
-if unsorted, sort them
-after sorting, iterate linearly over every interval if it is not already added to the answer
-check if any can interval can be merged
-take one more data structure and store the value of the merged interval in it
-tc -> o(nlogn) (for sorting) + o(n^2) (for approach)

-optimal approach
-sort the array
-store first in a pair
-iterate over the array, see if any element can merge, if it cannot, replace first with that and store first in some other data structure
-whichever pairs are left, put them in the data structure
-tc -> o(nlogn) + o(n)
-sc -> o(n)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size()==0){
            return mergedIntervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] <= tempInterval[1]){
                tempInterval[1] = max(intervals[i][1], tempInterval[1]);
            }
            else{
                mergedIntervals.push_back(tempInterval);
                tempInterval = intervals[i];
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};