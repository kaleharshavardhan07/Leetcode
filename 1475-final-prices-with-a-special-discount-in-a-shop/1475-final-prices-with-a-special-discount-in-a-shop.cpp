class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for (int i = 0; i < prices.size(); i++) {
            int mini = prices[i];
            int ind = -1;
            for (int j = i + 1; j < prices.size(); j++) {
                if (mini >= prices[j]) {
                    mini = prices[j];
                    ind = j;
                    break;
                }
            }
            if( ind!=-1){
                prices[i]-=mini;


            }
        }
        return prices;
    }
};