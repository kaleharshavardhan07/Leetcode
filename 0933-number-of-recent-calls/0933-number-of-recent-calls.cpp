class RecentCounter {
public:
int count = 0;
        vector<int> request;
        
    RecentCounter() {
        
    }

    int ping(int t) {
        request.push_back(t);
        int count = 0;
        int m = t - 3000;

        if (request.empty())
            return 0;

        for (int i = request.size() - 1; i >= 0; i--) {
            if (request[i] >= m) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */