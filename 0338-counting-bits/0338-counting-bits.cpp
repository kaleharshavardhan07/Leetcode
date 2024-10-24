class Solution {
public:
int count(int k){
        int c=0;
        while(k!=0){
            if(k%2!=0){
                c++;
            }
            k=k/2;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int> arr;
        for(int i=0;i<=n;i++){
              int j=count(i);
              arr.push_back(j);
        }
        return arr;
    }
    
};