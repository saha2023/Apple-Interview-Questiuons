// generatised solutoin for find length of the longest substring with k repeating characters
class Solution {
private:
    int lengthOfLongestSubstringWithkRepeating(string &s, int k){
        vector<int>mp(128,0);
        int n = size(s);
        int len = 0;
        int l = 0, r = 0;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>k){
                mp[s[l]]--;
                l++;
                if(mp[s[l]]<0) mp[s[l]] = 0;
            }
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
public:
    int lengthOfLongestSubstring(string s) {
        return lengthOfLongestSubstringWithkRepeating(s,1);
    }
};