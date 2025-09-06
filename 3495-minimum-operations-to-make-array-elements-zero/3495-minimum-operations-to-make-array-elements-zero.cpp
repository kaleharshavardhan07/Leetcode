class Solution {
public:
    vector<pair<long long,long long>> solve(long long a, long long b) {
    vector<pair<long long,long long>> cp;
    long long start = a;

    while (start <= b) {
        long long p = 1;
        long long k = 0;
        while (p <= start) {
            p *= 4;
            k++;
        }

        long long end = min(b, (long long)(p - 1));
        long long len = end - start + 1;
        cp.push_back({len, k});

        start = end + 1;
    }

    return cp;
}


    long long minOperations(vector<vector<int>>& queries) {
        long long total = 0;

        for (auto& q : queries) {
            long long a = q[0], b = q[1];
             vector<pair<long long,long long>> groups = solve(a, b);

            long long c = 0;
            vector<long long> leftovers;

            for (long long l = (long long)groups.size() - 1; l >= 0; l--) {
                c += (groups[l].first / 2) * (groups[l].second);

                if (groups[l].first % 2 != 0) {
                    
                        leftovers.push_back(groups[l].second);
                    
                }
            }

            long long sum = accumulate(leftovers.begin(), leftovers.end(), 0LL);
            c += sum / 2;
            if (sum % 2 != 0) c++;

            total += c;
        }

        return total;
    }
};
