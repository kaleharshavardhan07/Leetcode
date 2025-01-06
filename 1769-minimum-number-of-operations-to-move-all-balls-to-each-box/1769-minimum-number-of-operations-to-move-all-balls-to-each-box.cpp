class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ret;

        for( int i=0;i<boxes.size();i++){
            int sume=0;
            for( int j=0;j<boxes.size();j++){
                if( boxes[j]=='1'){
                    sume+=abs(j-i);


                }
            }
            ret.push_back(sume);
        }
        return  ret;
    }
};