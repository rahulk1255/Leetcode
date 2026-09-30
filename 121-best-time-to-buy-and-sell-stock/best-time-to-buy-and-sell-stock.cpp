class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n= prices.size();
        vector<int>minarr(n),maxarr(n);
        minarr[0]=prices[0];
        maxarr[n-1]=prices[n-1];
        for(int i=1;i<n;i++){
            minarr[i]=min(minarr[i-1],prices[i]);
        }
        for(int i=n-2;i>=0;i--){
            maxarr[i]=max(maxarr[i+1],prices[i]);
        }

        for(int i=0;i<n;i++){
            ans=max(ans,maxarr[i]-minarr[i]);
        }
        return ans;
    }
};

