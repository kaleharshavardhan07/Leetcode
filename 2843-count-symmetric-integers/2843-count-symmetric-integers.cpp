class Solution {
public:
bool solve( int i){
    string c=to_string(i);
    int l=0;
    int r=c.size();
    if(r%2!=0)return false;
    r--;
    int sume=0;int sumo=0;
    while( l<r){

        sume+=c[l];
        sumo+=c[r];
        l++;
        r--;


    }

    return sume==sumo;
}
    int countSymmetricIntegers(int low, int high) {
        int c=0;
        for(int i=low;i<=high;i++ ){
            if(solve(i))c++;
        }
        return c;
    }
};