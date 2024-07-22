class RecentCounter {
public:
// int count = 0;
        queue<int>q;
        
    RecentCounter() {
        
    }

   int ping(int t) {
        int left = t - 3000;
        while( !q.empty() && left > q.front()){
            q.pop();
        }
        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */