// class Solution {
// public:
//     string inv( string k){
//         string s;
//            for( char c: k){
//             if( c=='1'){
//                 s=s+'0';
//             }
//             else{
//                  s=s+'1';
//             }
//            }
//            reverse(s.begin(),s.end());
//            return s;
//     }
//     char findKthBit(int n, int k) {
//         string s1="0";

//         for( int i=0;i<n;i++){
//             s1=s1+'1'+inv(s1);
//         }

//         return s1[k-1];
        

//     }
// };
class Solution {
public:
    char solve(int n, int k) {
        if(n == 1) return '0';

        int len = (1 << n) - 1;
        int mid = (len / 2) + 1;

        if(k == mid) return '1';

        if(k < mid) 
            return solve(n - 1, k);
        
        // mirror + invert
        return solve(n - 1, len - k + 1) == '0' ? '1' : '0';
    }

    char findKthBit(int n, int k) {
        return solve(n, k);
    }
};