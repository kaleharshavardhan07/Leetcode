class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int> pq;
        for (int n : nums)
            pq.push(n);

        long long tot = 0;
        for (int i = 0; i < k; i++) {
            int temp = pq.top();
            tot += temp;
            temp = temp / 3;
            if (temp * 3 == pq.top()) {
                pq.pop();
                pq.push(temp);
            } else {
                pq.pop();
                pq.push(temp + 1);
            }
        }
        return tot;
    }
};