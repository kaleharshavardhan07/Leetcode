class Solution {
public:
    string toBinary(unsigned int num) {
        std::string binary = "";
        for (int i = 31; i >= 0; --i) {
            binary += (num & (1 << i)) ? '1' : '0';
        }
        return binary;
    }

    int countSetBits(unsigned int num) {
        int count = 0;
        while (num) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    int minimizeXor(int num1, int num2) {
        int k = countSetBits(num2); 
        string m = toBinary(num1); 
        string n = m;

        int i = 0;
        while (i < 32 && k > 0) {
            if (m[i] == '1') {
                n[i] = '1';
                k--;
            } else {
                n[i] = '0';
            }
            i++;
        }
        if( i<32 && k==0){
            while(i<32){
                n[i]=0;
                i++;
            }
        }

        i = 31;
        while (i >= 0 && k > 0) {
            if (n[i] == '0') {
                n[i] = '1';
                k--;
            }
            i--;
        }

        int num = 0;
        for (int j = 0; j < 32; ++j) {
            if (n[j] == '1') {
                num |= (1 << (31 - j));
            }
        }

        return num;
    }
};
