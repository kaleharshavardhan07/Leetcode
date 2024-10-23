#include <vector>
#include <stack>

class Solution {
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        int k = rooms.size();
        std::vector<int> visited(k, 0);
        std::stack<int> st;
        
        visited[0] = 1;  
        st.push(0); 
        
        while (!st.empty()) {
            int room = st.top();
            st.pop();

            for (int key : rooms[room]) {
                if (!visited[key]) {
                    visited[key] = 1;
                    st.push(key);
                }
            }
        }

        
        for (int visit : visited) {
            if (visit == 0) {
                return false; 
            }
        }

        return true;  
    }
};
