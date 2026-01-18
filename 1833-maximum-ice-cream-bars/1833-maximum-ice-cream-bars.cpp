class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int c = 0;
        while (coins > 0) {

            if ( c< costs.size() && 
            coins >= costs[c] ) {
                coins =coins- costs[c];
                c++;
            } else {
                break;
            }
        }
        return c;
    }
};