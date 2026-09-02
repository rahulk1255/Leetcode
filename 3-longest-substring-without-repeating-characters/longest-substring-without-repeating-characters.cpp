class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int i=0,j=0;
        int n=s.size();
        int ans = 0;
        int len=0;
        while(i<n && j<n){
            if(mp[s[j]]<1){
                mp[s[j]]++;
                len++;
                j++;
            }else{
                ans=max(ans,len);
                while(s[i]!=s[j]){
                    mp[s[i]]--;
                    i++;
                    len--;
                    
                }
                mp[s[i]]--;
                i++;
                len--;
            }
        }
        ans=max(ans,len);
        return ans;
    }
};