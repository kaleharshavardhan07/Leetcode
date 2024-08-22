class Solution {
public:
    vector<int> constructRectangle(int area) {
        // int min = INT_MAX;
        int h = 0;
        int w = 0;
        for (int i = 1; i <= area/2+1; i++) {
            if (area % i == 0 && area / i >= i) {
              
                    w = i;
                    h = area / i;
                
            }
        }
        return {h, w};
    }
};