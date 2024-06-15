class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {

        int current1 = min(ay1, ay2);
        int current2 = min(by1, by2);
        int enday = max(ay1, ay2);
        int endby = max(by1, by2);
        int county = -1;

        while (current1 <= enday && current2 <= endby) {
            if (current1 == current2) {
                county++;
                ++current1;
                ++current2;
            } else if (current1 < current2) {
                ++current1;
            } else {
                ++current2;
            }
        }
         current1 = min(ax1, ax2);
         current2 = min(bx1, bx2);
         enday = max(ax1, ax2);
         endby = max(bx1, bx2);
        int countx = -1;
        while (current1 <= enday && current2 <= endby) {
            if (current1 == current2) {
                countx++;
                ++current1;
                ++current2;
            } else if (current1 < current2) {
                ++current1;
            } else {
                ++current2;
            }
        }
        int commonarea = 0;
        if (countx > 0 && county > 0) {
            commonarea = countx * county;
        }
        int area1 = abs(ay1 - ay2) * abs(ax1 - ax2);
        int area2 = abs(by1 - by2) * abs(bx1 - bx2);
        int total = area1 + area2 - commonarea;

        return total;
    }
};