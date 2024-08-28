class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
           vector<double>ret;
           int min=0;
           for(int i=0;i<dist.size();i++){
            ret.push_back(static_cast<double>(dist[i])/speed[i]);

           }
           sort(ret.begin(),ret.end());
           for( int i=0;i<ret.size();i++){
            if(i>=ret[i])return i;
           }
           return ret.size();
    }
};
// GOOD BUT NOT SOLVE EDGES LIKE SPEND AND DIST OPTI IZATION TO TRACK DOWN IT 
// class Solution {
// public:
//     static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
//         if (a.first == b.first)
//             return a.second > b.second;
//         return a.first < b.first;
//     }
//     int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
//         vector<pair<int, int>> ret;
//         for (int i = 0; i < dist.size(); i++) {
//             ret.push_back({dist[i], speed[i]});
//         }
//         sort(ret.begin(), ret.end(), cmp);

//         int count = 0;
//         for (int i = 0; i < ret.size(); i++) {
//             if (i * ret[i].second < ret[i].first) {

//                 count++;
//             }
//         }
//         return count;
//     }
// };