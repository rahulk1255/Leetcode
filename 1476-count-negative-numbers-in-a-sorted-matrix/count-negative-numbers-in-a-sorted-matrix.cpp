class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(auto i:grid){
            for(int j:i){
                if(j<0){
                    count++;
                }
            }
        }
        return count;
    }
};