// class Solution {
// public:
//     int findMaximizedCapital(int k, int w, vector<int>& profits,
//                              vector<int>& capital) {

//         long s=w;
//         int start = 0;
//         while (start < k) {
//             int flag = 0;
//             int i = 0;
//             int point = 0;
//             int max = INT_MIN;
//             while (  i < profits.size()) {

//                 if (s >= capital[i] && profits[i]  > max) {
//                     max = profits[i];
//                     point = i;
//                     flag=1;

//                 }

//                 i++;
//             }

//             // w=w-capital[point];
//             if(flag==1){
//             s = s + profits[point];
//             profits.erase(profits.begin() + point);
//             capital.erase(capital.begin() + point);}
//             else{
//                 return s;
//             }

//             start++;
//         }
//         return s;
//     }
// };
// my code top ; time exceed but this one not down

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> ret;
        for (int i = 0; i < profits.size(); i++) {
            ret.push_back({capital[i], profits[i]});
        }
        sort(ret.begin(), ret.end());
        priority_queue<int> maxPro;
        int i=0;
        while (k--) {
            while (i < n and w >= ret[i].first) {
                maxPro.push(ret[i].second);
                i++;
            }
            if (maxPro.empty()) {
                break;
            }
            w += maxPro.top();
            maxPro.pop();
        }
        return w;
    }
};
