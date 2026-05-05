class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9], cols[9], box[9];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val == '.')
                    continue;
                int idx = (r / 3) * 3 + (c / 3);

                if (rows[r].count(val) || cols[c].count(val) || box[idx].count(val))
                    return false;
                
                rows[r].insert(val);
                cols[c].insert(val);
                box[idx].insert(val);
            }
        }
        return true;
    }
};
