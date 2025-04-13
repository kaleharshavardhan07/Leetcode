class Solution {
public:
    bool check(int k, vector<int>& piles, int h) {

        int count = 0;
        for (int i = 0; i < piles.size(); i++) {
            int temp = piles[i] % k;

            int c = piles[i] / k;
            if (temp > 0)
                c++;
            count += c;
            if( count>h)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = INT_MIN;
        int low = 1;
        for (int i : piles) {
            high = max(high, i);
        }
        int l = INT_MAX;
        if( h==piles.size())return high;
        while (low < high) {
            int mid = (low + high) / 2;

            if (check(mid, piles ,h)) {
                l = min(l, mid);
                high = mid;

            } else
                low = mid+1;
        }

        return l;
    }
};