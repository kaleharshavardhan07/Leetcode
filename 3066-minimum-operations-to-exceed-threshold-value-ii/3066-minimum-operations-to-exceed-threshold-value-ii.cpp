class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> mh;

        for (int n : nums)
            mh.push(n);
        
        int c = 0;
        while (mh.size() >= 2) {
            long long f = mh.top();
            mh.pop();
            long long s = mh.top();
            mh.pop();

            if (f >= k && s >= k) {
                return c;
            } else {
                long long t1 = f * 2 + s;
                mh.push(t1);
                c++;
            }
        }

        return c;
    }
};
