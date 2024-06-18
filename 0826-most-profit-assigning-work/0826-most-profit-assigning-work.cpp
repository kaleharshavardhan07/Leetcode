class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(),worker.end());
         vector<pair<int,int>>lookup;
        int k=profit.size();
         for (int i = 0; i < k; ++i) {
           lookup.push_back({ profit[i],difficulty[i]});
        }
        sort(lookup.begin(),lookup.end());
        int j=lookup.size()-1;
        int max=0;
        while(j>=0 && !worker.empty()){
            int diff=lookup[j].second;
            int wo=worker.back();
            int po=lookup[j].first;

            if(wo>=diff){
               max=max+po;
               worker.pop_back();
            }
            else{
               j--;
            }

        }
        
return max;


    }
};