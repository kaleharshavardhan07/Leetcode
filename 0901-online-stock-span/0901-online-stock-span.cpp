class StockSpanner {
private:
    stack<pair<int, int>> st;

public:
    StockSpanner() {}

    int next(int price) {
        if (st.empty()) {
            st.push({price, 1});
            return 1;

        } else {

            int k = 1;

            while (!st.empty() && st.top().first <= price) {

                k += st.top().second;
                st.pop();
            }
            st.push({price, k});

            return k;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */