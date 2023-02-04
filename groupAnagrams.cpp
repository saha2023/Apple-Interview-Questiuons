class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mp;
        for(auto s:strs){
            vector<int>tmp(26,0);
            for(char c:s){
                tmp[c-'a']++;
            }
            mp[tmp].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto &[key, val]:mp){
            vector<string>sAns;
            for(auto s:val){
                sAns.push_back(s);
            }
            ans.push_back(sAns);
        }
        return ans;
    }
};