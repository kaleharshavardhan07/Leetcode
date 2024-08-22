class Solution {
public:
    int findComplement(int num) {
        // Step 1: Calculate the bit length of 'num'
        int bit_length = floor(log2(num)) + 1;

        // Step 2: Generate a mask with all bits set to 1 for the given bit length
        unsigned int mask = (1U << bit_length) - 1;

        // Step 3: XOR num with the mask to get the complement
        return num ^ mask;
    }
};
