class Solution {
public:
    int maxDistance(string s, int k) {

        int maxi = 0;
        int e = 0;
        int n = 0;
        int so = 0;
        int w = 0;
        for (char c : s) {
            if (c == 'N') {
                n++;

            } else if (c == 'S') {
                so++;
                
            } else if (c == 'E') {
                e++;
            } else {
                w++;
            }
int l=k;
            vector<int>a={e,w,so,n};
            sort(a.begin(),a.end());
            int temp= a[3]+a[2];
            int co= a[0]+a[1];
            if( co>l){
                co=co-l;
            }else{

                l=co;
                co=0;}

            temp=temp-co+l;

            maxi=max(maxi,temp);


            
            
        }
        return maxi;
    }
};