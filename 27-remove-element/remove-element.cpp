class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int n= nums.size();
        int j=n-1;
        int ans=0;
        if(n==1){
            if(nums[0]==val){
                return 0;
            }else{
                return 1;
            }
        }
        for(int i=0;i<n;i++){
            
            if(nums[i]==val ){
                while(j>=0 && nums[j]==val){
                    j--;
                }
                if(i>=j) break;
                swap(nums[i],nums[j]);
                
            }
            ans++;
        }

        return ans;
    }
};