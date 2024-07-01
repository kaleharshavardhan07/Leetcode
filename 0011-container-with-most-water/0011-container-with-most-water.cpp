class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int i = 0;
        int j = height.size() - 1;
        while (j > i) {
            int temp = (j - i) * min(height[i], height[j]);
            if (max < temp) {
                max = temp;
            }
            if (height[j] > height[i]) {
                i++;
            } else {
                j--;
            }
        }
        return max;
    }
};