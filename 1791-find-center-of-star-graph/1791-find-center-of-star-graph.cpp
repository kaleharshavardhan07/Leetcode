class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
         return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};

// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         map<int , int >mapi;
//         for(int i=0;i<edges.size();i++){
//             mapi[edges[i][0]]++;
//             mapi[edges[i][1]]++;
//         }
//         int max=INT_MIN;
//         int ret;
//         for(auto i=mapi.begin();i!=mapi.end();i++){
//             if(max<i->second){
//                 max=i->second;
//                 ret=i->first;
//             }
//         }
//         return ret;
        
//     }
// };