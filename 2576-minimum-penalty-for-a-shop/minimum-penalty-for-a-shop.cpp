class Solution {
public:
    int bestClosingTime(string customers) {
        int count_0=0;
        int count_1=0;
        int total_1=0;
        int n=customers.size();
        for(char c: customers){
            if(c=='Y'){
                total_1++;
            }
        }
        int idx=0;
        int ans=total_1;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                count_1++;
            }else{
                count_0++;
            }
            int val=total_1-count_1+count_0;
            if(ans>val){
                ans=val;
                idx=i+1;
            }
            
        }
        return idx;
    }
};

