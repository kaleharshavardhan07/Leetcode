class Solution {
public:
 std::vector<std::string> printAllBinaryNumbers(int k) {
    int totalNumbers = 1 << k;
    
    std::vector<std::string> ret;
    for (int i = 0; i < totalNumbers; ++i) {
        std::bitset<64> binary(i); 
        std::string binaryString = binary.to_string().substr(64 - k); 
        ret.push_back(binaryString);
    }
    return ret;
}
    bool hasAllCodes(string s, int k) {
        vector<string> ret=  printAllBinaryNumbers( k);
        map<string,int>mapi;
        for(int i=0;i<s.size()-k;i++){
            mapi[s.substr(i,k)]++;

        }
        for(string c : ret){
            if(mapi[c]==0){
                return false;
            }
        }
        return true;
        
    }
};