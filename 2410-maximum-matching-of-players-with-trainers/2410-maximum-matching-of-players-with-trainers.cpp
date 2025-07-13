class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int lt = 0;
        int lp = 0;
        int c = 0;

        while (lt < trainers.size() && lp < players.size()) {
            if (trainers[lt] >= players[lp]) {
                c++;
                lp++;
                lt++;
            } else {
                lt++;
            }
        }

        return c;
    }
};