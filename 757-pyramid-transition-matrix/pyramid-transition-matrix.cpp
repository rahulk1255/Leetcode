class Solution {
public:
    unordered_map<string,vector<char>>mp;
    bool dfs(string cur,string next,int idx)
    {
        if(cur.size()==1)return true;

        if(idx==cur.size()-1)return dfs(next,"",0);
        string key = cur.substr(idx,2);
        for(char ch:mp[key]){
            if(dfs(cur,next+ch,idx+1)){
                return true;
            }
        }

        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(string s:allowed){
            mp[s.substr(0,2)].push_back(s[2]);
        }

        return dfs(bottom,"",0);
    }
};

