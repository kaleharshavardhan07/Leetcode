#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<int> min_moves_to_square;
    int total_squares;

    void dfs(int current_square, int current_moves, const std::vector<int>& board_1d) {
        if (current_moves >= min_moves_to_square[current_square]) {
            return;
        }

        min_moves_to_square[current_square] = current_moves;

        if (current_square == total_squares - 1) {
            return;
        }

        for (int dice_roll = 1; dice_roll <= 6; ++dice_roll) {
            int next_pos_after_roll = current_square + dice_roll;

            if (next_pos_after_roll >= total_squares) {
                continue;
            }

            int final_destination_square;
            if (board_1d[next_pos_after_roll] != -1) {
                final_destination_square = board_1d[next_pos_after_roll];
            } else {
                final_destination_square = next_pos_after_roll;
            }
            
            dfs(final_destination_square, current_moves + 1, board_1d);
        }
    }

    int snakesAndLadders(std::vector<std::vector<int>>& board) {
        int n_dim = board.size();
        total_squares = n_dim * n_dim;

        std::vector<int> board_1d;
        bool leftToRight = true;
        for (int r = n_dim - 1; r >= 0; --r) {
            if (leftToRight) {
                for (int c = 0; c < n_dim; ++c) {
                    board_1d.push_back(board[r][c]);
                }
            } else {
                for (int c = n_dim - 1; c >= 0; --c) {
                    board_1d.push_back(board[r][c]);
                }
            }
            leftToRight = !leftToRight;
        }
        
        min_moves_to_square.assign(total_squares, INT_MAX);

        dfs(0, 0, board_1d);

        if (min_moves_to_square[total_squares - 1] == INT_MAX) {
            return -1;
        } else {
            return min_moves_to_square[total_squares - 1];
        }
    }
};