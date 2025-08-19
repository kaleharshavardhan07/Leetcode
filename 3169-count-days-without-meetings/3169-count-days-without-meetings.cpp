// class Solution {
// public:
// static bool cmp(vector<int>& a, vector<int>& b) {
//     if (a[0] == b[0]) {
//         return a[1] < b[1];  
//     }
//     return a[0] < b[0];  
// }

//     int countDays(int days, vector<vector<int>>& meetings) {

//         sort( meetings.begin(),meetings.end(),cmp);
//         // vector<vector<int>>ret;
//         int s=meetings[0][0];
//         int e=meetings[0][1];
//         int sume=meetings[0][0]-1;
//         for( auto it : meetings){
//             if( e>=it[1])continue;
//             if( e>=it[0]){
//                 e=it[1];
//             }
//             else{
//                 sume+=it[0]-e-1;
//                 // ret.push_back({s,e});
//                 s=it[0];
//                 e=it[1];
//             }
        

//         }
//         sume=sume+days-meetings[meetings.size()-1][1];
//         //   ret.push_back({s,e});


//         // int sum=ret[0][0]-1;
//         // for( int i=0;i<ret.size()-1;i++){
//         //     sum=sum+ (ret[i+1][0]-ret[i][1]-1);
//         // }
//         // sum=sum+days-ret[ret.size()-1][1];

//         return sume;
        
//     }
// };

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];  
        }
        return a[0] < b[0];  
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;  

        sort(meetings.begin(), meetings.end(), cmp);

        int e = 0, freeDays = 0;

        for (auto& it : meetings) {
            if (it[0] > e + 1) {
                freeDays += (it[0] - e - 1);  
            }
            e = max(e, it[1]);  
        }

        freeDays += (days - e); 

        return freeDays;
    }
};
