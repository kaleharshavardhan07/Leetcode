class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int tot = 0;
        int emp = 0;
        while (numBottles > 0) {
            tot += numBottles;
            emp += numBottles;
            numBottles = 0;

            numBottles = emp / numExchange;
            emp = emp % numExchange;
        }
        return tot;
    }
};