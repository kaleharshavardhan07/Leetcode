class Solution {
public:
    double average(vector<int>& salary) {
        
        double min=INT_MAX;
        double maxi=INT_MIN;
        double sum=0;
        for(double n:salary){
            if(min>n){
              min=n;
            }
            if(maxi<n){
                maxi=n;
            }
            sum=sum+n;
           
        }
        return (sum-min-maxi)/(salary.size()-2);

    }
};