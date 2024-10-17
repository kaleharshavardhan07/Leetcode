class Solution {
public:
    int maximumSwap(int num) {
    string s = to_string(num); 
    int n = s.length();

    vector<int> last(10, -1);

  
    for (int i = 0; i < n; i++) {
        last[s[i] - '0'] = i;
    }

  
    for (int i = 0; i < n; i++) {
       
        for (int d = 9; d > s[i] - '0'; d--) {
            if (last[d] > i) {
                swap(s[i], s[last[d]]);
                return stoi(s); 
            }
        }
    }

    return num;
}

};

// class Solution {
// public:
//     int maximumSwap(int num) {

//         string s = to_string(num);
//         for (int i = 0; i < s.length(); i++) {
//             char t1 = s[i];
//             int maxi = int(t1 - '0');
//             int ind = i;
//             for (int j = i + 1; j < s.length(); j++) {
//                 int temp = int(s[j] - '0');
//                 if (maxi < temp) {
//                     maxi=temp;
//                     ind = j;
//                 }
//             }
//             if (maxi != int(t1 - '0')) {
//                 swap(s[i], s[ind]);
//                 break;
//             }
//         }

//         return stoi(s);
//     }
// };