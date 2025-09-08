class Solution {
public:
    bool z(int k ){
        string numStr = to_string(k);
    return numStr.find('0') != string::npos;
    }
    vector<int> getNoZeroIntegers(int n) {
        int top=n-1;
        int bot=1;
        while( z(top)==true || z(bot)==true){
            top--;
            bot++;
            

        }
        vector<int>ret={bot,top};
        return ret;
    }
};