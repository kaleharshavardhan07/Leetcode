class Solution {
public:
    int passThePillow(int n, int time) {
        int current_position = 1;  
    int direction = 1;        
    for (int i = 0; i < time; ++i) {
        current_position += direction;
        

        if (current_position == n) {
            direction = -1;
        } else if (current_position == 1) {
            direction = 1;
        }
    }
    
    return current_position;
    }
};