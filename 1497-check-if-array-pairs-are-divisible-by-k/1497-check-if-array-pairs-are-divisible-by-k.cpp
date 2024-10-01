class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        vector<int> rem(k, 0);

        for (int n : arr) {
            int remi = ((n % k) + k) % k; 
            rem[remi]++;
        }

        for (int i = 1; i < (k + 1) / 2; i++) {
            if (rem[i] != rem[k - i]) {
                return false;
            }
        }

        if (k % 2 == 0 && rem[k / 2] % 2 != 0) {
            return false;
        }

        return rem[0] % 2 == 0;
    }
};

// class Solution {
// public:
//     bool canArrange(vector<int>& arr, int k) {
//         sort(arr.begin(), arr.end());
//         vector<int> chk(arr.size(), 0);
//         for (int i = 0; i < arr.size(); i++) {
//             if (chk[i] != 1) {
//                 int temp = arr[i];
//                 for (int j = arr.size() - 1; j > i; j--) {
//                     if ((arr[j] + temp) % k == 0 && chk[j] != 1) {

//                         chk[i] = 1;
//                         chk[j] = 1;
//                         break;
//                     }
//                 }
//             }
//         }
//         for( int n: chk){
//             if(n==0)return false;
//         }
//         return true;
//     }
// };