class Solution {
public:
    string discountPrices(string sentence, int discount) {
        istringstream ss(sentence);
        vector<string> div;
        string word;
        while (ss >> word) {
            div.push_back(word);
        }
        for (int i = 0; i < div.size(); i++) {
            if (div[i][0] == '$' && div[i].size() > 1) {

                int flag = 0;
                for (int j = 1; j < div[i].size(); j++) {
                    if (!isdigit(div[i][j]) && div[i][j] != '.') {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    double price = stod(div[i].substr(1));
                    // Apply discount
                    double discountedPrice = price * (1 - discount / 100.0);
                    // Convert back to string with two decimal places
                    stringstream stream;
                    stream << fixed << setprecision(2) << discountedPrice;
                    div[i] = "$" + stream.str();
                }
            }
        }
        string ret;
        for (string c : div) {
            ret = ret + c + " ";
        } 
        ret.pop_back();
        return ret;
    }
};