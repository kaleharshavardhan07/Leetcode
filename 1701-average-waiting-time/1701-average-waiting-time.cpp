class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        vector<double> map;
        double ttime = customers[0][0];

        for (int i = 0; i < customers.size(); i++) {
            double wtime = 0;
            // ttime=customers[i][1];
            if (ttime >= customers[i][0]) {
                ttime = ttime + customers[i][1];
                wtime = ttime - customers[i][0];
                map.push_back(wtime);

            } else {
                ttime = customers[i][0]+customers[i][1];
                wtime = ttime - customers[i][0];
                map.push_back(wtime);
            }
        }
        double sum = 0.0;
        for (double value : map) {
            sum += value;
        }

        double average = sum / map.size();

        return average;
    }
};