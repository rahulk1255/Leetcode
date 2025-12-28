class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int lastidx = col;   
        int count = 0;

        for (int i = 0; i < row; i++) {
            int negidx = lastidx;   
            for (int j = 0; j < lastidx; j++) {
                if (grid[i][j] < 0) {
                    negidx = j;
                    break;
                }
            }

            count += col - negidx;
            lastidx = negidx;
        }

        return count;
    }
};
