/*
-brute force
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int currDiff = 0;
        int maxDiff = INT_MIN;
      
        for(int i = 0; i < n-1; i++){
            for(int j = i + 1; j < n; j++){
                currDiff = prices[j] - prices[i];
                if(currDiff > maxDiff){
                    maxDiff = currDiff;
                }                
            }        
        }
        if(maxDiff<0){
            return 0;
        }
        return maxDiff;
    }
};
-optimal solution
-keep track of min
-profit = 0
+
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i = 0; i < size; i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minPrice);
        }
        return maxProfit;
    }
};


