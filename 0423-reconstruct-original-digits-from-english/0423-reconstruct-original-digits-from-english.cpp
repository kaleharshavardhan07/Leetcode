class Solution {
public:
    string originalDigits(string s) {
         unordered_map<char, int> count;
    for (char ch : s) {
        count[ch]++;
    }
    
    // To store the count of each digit (0-9)
    vector<int> digits(10, 0);
    
    // Identify digits with unique characters
    digits[0] = count['z'];  // 'z' is unique to "zero"
    digits[2] = count['w'];  // 'w' is unique to "two"
    digits[4] = count['u'];  // 'u' is unique to "four"
    digits[6] = count['x'];  // 'x' is unique to "six"
    digits[8] = count['g'];  // 'g' is unique to "eight"
    
    // Now for digits with characters shared by others
    digits[1] = count['o'] - digits[0] - digits[2] - digits[4]; // "one" shares 'o' with "zero", "two", and "four"
    digits[3] = count['h'] - digits[8]; // "three" shares 'h' with "eight"
    digits[5] = count['f'] - digits[4]; // "five" shares 'f' with "four"
    digits[7] = count['s'] - digits[6]; // "seven" shares 's' with "six"
    digits[9] = count['i'] - digits[5] - digits[6] - digits[8]; // "nine" shares 'i' with "five", "six", and "eight"
    
    // Construct the output based on the digit counts
    string result;
    for (int i = 0; i <= 9; ++i) {
        result += string(digits[i], '0' + i); // Append digit 'i', digits[i] times
    }
    
    return result;
    }

};