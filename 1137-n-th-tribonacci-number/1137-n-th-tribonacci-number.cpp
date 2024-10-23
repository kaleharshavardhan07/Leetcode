class Solution {
public:
    int tribonacci(int n) {
        int p=1;
        int pp=1;
        int ppp=0;
        if (n==0){
            return 0;
        }
        else if(n==1)return 1;
        else if (n==2)return 1;
       else{
        for(int i=3;i<=n;i++){
            int sum=p+pp+ppp;
            ppp=pp;
            pp=p;
            p=sum;

        }}
        return p;
    }
};
// class Solution {
// public:
//     int tribonacci(int n) {
//         if(n==0)return 0;
//        else if(n==1)return 1;
//        else if(n==2)return 1;
//        else{
//         return tribonacci(n-1)+ tribonacci(n-2)+ tribonacci(n-3);
//        }

//     }
// };