// class Solution {
// public:
//     int minNumberOfHours(int initialEnergy, int initialExperience,
//                          vector<int>& energy, vector<int>& experience) {
//         int sum = 0;
//         for (auto i : energy)
//             sum += i;
//         int reti=sum-initialEnergy;
//         if( reti<0){
//             reti=0;
//         }
//         else reti++;
//         int in = initialExperience;
//         int count = 0;
//         for (int i = 0; i < experience.size(); i++) {
//             if (in > experience[i]) {
//                 in += experience[i];
//             } else {
//                 count = experience[i] - in + 1;
//                 in = in + count + 1;
//             }
//         }
//         return count+ reti;
//     }
// };

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience,
                         vector<int>& energy, vector<int>& experience) {
        // Calculate total energy required
        int totalEnergy = 0;
        for (int e : energy) totalEnergy += e;

        // Calculate extra energy needed
        int energyTraining = max(0, totalEnergy - initialEnergy + 1);

        // Calculate extra experience needed
        int experienceTraining = 0;
        int currentExperience = initialExperience;
        for (int i = 0; i < experience.size(); ++i) {
            if (currentExperience > experience[i]) {
                currentExperience += experience[i];
            } else {
                int required = experience[i] - currentExperience + 1;
                experienceTraining += required;
                currentExperience += required + experience[i];
            }
        }

        return energyTraining + experienceTraining;
    }
};
