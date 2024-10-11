// class Solution {
// public:
//     static bool cmp(const vector<int>& a, vector<int>& b) {
//         if (a[0] == b[0])
//             return a[1] < b[1];
//         return a[0] < b[0];
//     }
//     int smallestChair(vector<vector<int>>& times, int targetFriend) {
//         vector<vector<int>> ret = times;
//         sort(ret.begin(), ret.end(), cmp);
//         map<vector<int>, int> mapi;
//         int c = 0;
//         auto comp = [&mapi](vector<int>& a, vector<int>& b) {
//             if (a[1] == b[1]) {
//                 return mapi[a] > mapi[b];
//             }
//             return a[1] > b[1];
//         };

//         priority_queue<vector<int>, vector<vector<int>>,
//                        function<bool(vector<int>&, vector<int>&)>>
//             pq(comp);

//         for (auto it : ret) {
//             if (pq.empty()) {
//                 pq.push(it);
//                 mapi[it] = c;
//                 c++;
//             } else {
//                 vector<int> temp = pq.top();
//                 if (temp[1] <= it[0]) {
//                     mapi[it] = mapi[temp];
//                     pq.pop();
//                 } else {
//                     mapi[it] = c;
//                     c++;
//                 }
//             }
//             pq.push(it);
//         }
//         return mapi[times[targetFriend]];
//     }
// };


class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // Store the original indices
        vector<pair<vector<int>, int>> indexedTimes;
        for (int i = 0; i < times.size(); ++i) {
            indexedTimes.emplace_back(times[i], i);
        }
        
        // Sort by arrival time
        sort(indexedTimes.begin(), indexedTimes.end());
        
        set<int> availableChairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> occupied;
        int maxChair = 0;
        
        for (const auto& [time, index] : indexedTimes) {
            int arrival = time[0], departure = time[1];
            
            // Free up chairs of friends who have left
            while (!occupied.empty() && occupied.top().first <= arrival) {
                availableChairs.insert(occupied.top().second);
                occupied.pop();
            }
            
            int assignedChair;
            if (!availableChairs.empty()) {
                assignedChair = *availableChairs.begin();
                availableChairs.erase(availableChairs.begin());
            } else {
                assignedChair = maxChair++;
            }
            
            occupied.emplace(departure, assignedChair);
            
            if (index == targetFriend) {
                return assignedChair;
            }
        }
        
        return -1; // This line should never be reached if the input is valid
    }
};