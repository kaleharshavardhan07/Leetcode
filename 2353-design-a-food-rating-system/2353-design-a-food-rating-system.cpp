class FoodRatings {
    unordered_map<string, pair<string,int>> food; 
    unordered_map<string, set<pair<int,string>>> cuis;

public:
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        for (int i = 0; i < f.size(); i++) {
            food[f[i]] = {c[i], r[i]};
            cuis[c[i]].insert({-r[i], f[i]});
        }
    }

    void changeRating(string f, int nr) {
        auto [c, r] = food[f];
        cuis[c].erase({-r, f});
        food[f] = {c, nr};
        cuis[c].insert({-nr, f});
    }

    string highestRated(string c) {
        return cuis[c].begin()->second;
    }
};
