class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int c = 0;
        for (int i = 0; i < colors.size() - 2; i++) {
            if (colors[i] != colors[i + 1] && colors[i + 1] != colors[i + 2]) {
                c++;
            }
        }
        int k = colors.size() - 1;
        if (k >= 2) {
            if (colors[k - 1] != colors[k] && colors[k] != colors[0])
                c++;
            if (colors[k] != colors[0] && colors[0] != colors[1])
                c++;
        }
        return c;
    }
};