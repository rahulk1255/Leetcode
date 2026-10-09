class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int first = 0;
        int last = n-1;
        int ans=0;
        while( first<last ){
            int a= min(height[first],height[last]);
            ans=max(ans,(a)*(last-first));
            if(height[first]>height[last]){
                last--;
            }else{
                first++;
            }
        }
        return ans;
    }
};