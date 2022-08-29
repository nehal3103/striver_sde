/*
brute force
-compare all the strings character by character, increase count value as you move ahead 
-stop when the characters are diff
-if one string ends, stop
-tc -> o(no. of strings * length of shortest string)
-sc -> o(1)
*/

class Solution {
public:
    int findMinLength(vector<string>& strs, int n){
        int min = strs[0].length();
        for(int i = 1; i < n; i++){
            if(strs[i].length() < min){
                min = strs[i].length();
            }
        }
        return min;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int minlen = findMinLength(strs, n);
        string result;
        char current;
        for(int i = 0; i < minlen; i++){
            current = strs[0][i];
            for(int j = 1; j < n; j++){
                if(strs[j][i] != current){
                    return result;
                }
            }
            result.push_back(current);
        }
        return result;
    }
};