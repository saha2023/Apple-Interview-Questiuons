//1st Approach TLE
class Solution {
private:
    bool dfs(string s, unordered_set<string>&st){
        for(int i=0;i<s.size();i++){
            string preffix = s.substr(0,i+1);
            string suffix = s.substr(i+1);
            if((st.count(preffix) and dfs(suffix, st)) or (st.count(preffix) and st.count(suffix)))
                return true;
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        st.insert("");
        for(string &s: wordDict){
            st.insert(s);
        }
        return dfs(s, st);
    }
};

//2nd Approach No TLE  most optimised sol
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> st;
        int maxi = 0;
        int n = s.size();
        for(string it:wordDict){
            st.insert(it);
            maxi = max(maxi, (int)it.size());
        }
        vector<int>dp(n+1,0);
        dp[0] = 1;
        for(int i=0;i<=n;i++){
            if(dp[i]==0) continue;  //if preffis is false continue;
            for(int len = 1; len<=maxi and i+len<=n;len++){
                if(st.count(s.substr(i,len))){
                    dp[i+len] = 1; // markin all the vallid suffixed as true
                }
            }
        }
        return dp[n];
    }
};