class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int flag = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            int k = flowerbed[i];
            if (k == 1) {
                flag = 1;
            } else if (k == 0) {
                if (i < flowerbed.size() - 1 && flag == 0 &&
                    flowerbed[i + 1] != 1) {
                    n--;
                    flag = 1;
                } else if (i == flowerbed.size() - 1 && flag == 0) {
                    n--;
                } else {
                    flag = 0;
                }
            }
        }
        if (n > 0)
            return false;
        return true;
    }
};