class Solution {
public:
    int longestMountain(vector<int>& arr) {
         int n = arr.size();
        if (n < 3) return 0;
        vector<int>g(n,0);
        vector<int>s(n,0);
        int count=0;

        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                count++;
                
            }
            else {
                count=0;
            }
            s[i]=count;
        }
          count=0;
        
        for(int i=arr.size()-2;i>=0;--i){
            if(arr[i]>arr[i+1]){
                count++;
                
            }
            else {
                count=0;
            }
            g[i]=count;
        }
        int maxi=0;
        for(int i=1;i<arr.size()-1;i++){
            if(s[i]>0 && g[i]>0){
             int temp=s[i]+g[i]+1;
             maxi=max(temp,maxi);}
        }
        return maxi;
    }
};