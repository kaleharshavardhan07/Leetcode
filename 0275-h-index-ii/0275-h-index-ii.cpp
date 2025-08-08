class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0;
        int ind = 0;
        int n = citations.size();
        int r = citations.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            int temp = n - mid;
            if (citations[mid] >= temp) {
                ind = temp;
                r = mid - 1;

            } else {
                l = mid + 1;
            }
        }
        return ind;
    }
};
