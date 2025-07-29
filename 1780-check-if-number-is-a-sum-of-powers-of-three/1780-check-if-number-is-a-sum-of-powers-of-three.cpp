class Solution {
public:
 bool solve( int power, int n){
    if( n==0)return true;
    if( pow(3,power)>n)return false;
    bool add = solve( power+1, n-pow(3,power));
    bool skip= solve( power+1,n);
    return skip|add;
 }
    bool checkPowersOfThree(int n) {
        return solve(0,n);
    }
};