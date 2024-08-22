class Solution {
public:
    vector<int> constructRectangle(int area) {
       int min = INT_MAX ;
int h=0;
int w=0;
            for (int i = 1; i < area; i++) {
            if (area % i == 0 && area / i >= i) {
                if (min > area / i - i) {
                    min = area / i - i;
                    w = i;
                    h = area / i;
                }
            }
        }
        return {h, w};
    }
};