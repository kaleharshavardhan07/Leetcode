class Solution {
public:
    int hammingWeight(int n) {
        int k=0;
         std::string binary = std::bitset<32>(n).to_string(); 
         for(char c: binary){
            if(c=='1')k++;
         }
         return k;
    }
};