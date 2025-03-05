class Solution {
public:
    // long long coloredCells(int n) {

    //     if( n==1){
    //         return 1;

    //     }
        
    //     return 4+4*(n-2)+coloredCells(n-1);
        
    // }

     long long coloredCells(int n){
unsigned long long n = _n;
        return 1 + 2 * (n-1) * (n);     }


};