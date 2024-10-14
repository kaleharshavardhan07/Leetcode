class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());

    int radius = 0;

    for (int house : houses) {
        auto it = lower_bound(heaters.begin(), heaters.end(), house);

        int right_heater_distance = (it == heaters.end()) ? INT_MAX : (*it - house);

        int left_heater_distance = (it == heaters.begin()) ? INT_MAX : (house - *(it - 1));

        int closest_distance = min(left_heater_distance, right_heater_distance);

        radius = max(radius, closest_distance);
    }

    return radius;
}

};