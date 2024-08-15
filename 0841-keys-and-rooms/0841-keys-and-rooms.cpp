class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
         int k = rooms.size();
        vector<int> v(k, 0);

        stack<int> st;
         v[0]=1;
        for (int n : rooms[0]) {
            st.push(n);
        }
        if (st.empty())
            return false;
        while (!st.empty()) {
            int temp = st.top();
            st.pop();

            if (v[temp] == 0) {
                v[temp] = 1;

                for (int n : rooms[temp]) {
                    if (v[n] == 0) {
                        st.push(n);
                    }
                }
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0) {
                return false;
            }
        }
        return true;
    }
};