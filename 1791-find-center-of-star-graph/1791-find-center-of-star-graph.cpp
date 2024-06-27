class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a=edges[0][0];
        int b=edges[0][1];
        int c=edges[1][1];
        int d=edges[1][0];
        return(a==c ||b==c)? c:d;
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