class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
       int lastidx=col;
       int negidx=-1;
       int count=0;
       for(int i=0;i<row;i++){
            if(grid[i][col-1]>=0){
                continue;
            }else{
                for(int j=0;j<lastidx;j++){
                    if(grid[i][j]<0){
                        negidx=j;
                        break;
                    }
                }
            }
            count+=(row-i)*(lastidx-negidx);
            lastidx=negidx;

       }
        return count;
    }
};

