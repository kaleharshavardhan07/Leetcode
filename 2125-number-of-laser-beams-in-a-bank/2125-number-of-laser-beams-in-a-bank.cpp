class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> freq;
        for (string c : bank) {
            char k = '1';
            int counti = count(c.begin(), c.end(), k);
            freq.push_back(counti);
        }

        int sum=0;
        int j=0;
        if(freq.size()<=1){
            return 0;
        }
        while( j<freq.size() && freq[j]==0){
            j++;
        }
        if(j==freq.size() || j==freq.size()-1){
            return 0;
        }
        int prev=freq[j];
        for(int i=j+1;i<freq.size();i++){
            if(freq[i]!=0){
                 sum=sum+(freq[i]*prev);
                 prev=freq[i];
            }
            
        }
        return sum;
    }
};