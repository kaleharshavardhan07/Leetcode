class Solution {
public:
   bool c(int i) {
    int temp = i;
    while (temp > 0) {
        int k = temp % 10;
        temp = temp / 10;
        if (k == 0) return false;
        if (i % k != 0) return false; 
    }
    return true;
}

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ret;
        for(int i=left;i<right+1;i++){
            if(c(i)){
                ret.push_back(i);
            }

        }
        return ret;
    }
};