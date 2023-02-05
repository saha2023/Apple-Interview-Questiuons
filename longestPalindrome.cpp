//simple traversal O(n*n) time O(1)->extra space
class Solution {
private:
    string method01(string &s){
        int n = s.size();
        int len = 0;
        string res;
        for(int i=0;i<n;i++){
            int l,r;
            
            //odd length
            l=i, r=i;
            while(l>=0 and r<n and s[l] == s[r]){
                if(r-l+1>len){
                    len = r-l+1;
                    res = s.substr(l,len);
                }
                l--; r++;
            }
            
            
            //even length
            l=i, r=i+1;
            while(l>=0 and r<n and s[l] == s[r]){
                if(r-l+1>len){
                    len = r-l+1;
                    res = s.substr(l,len);
                }
                l--; r++;
            }
        }
        return res;
    }
};

//T-O(n*n) Space -O(n*n)  DP Solution
string method02(string &s){
    int n = s.size();
    int dp[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n;j++) dp[i][j] = 0;
    string res = "";
    int maxi = 0;
    for(int gap = 1; gap<=n; gap++){
        for(int i=0 ; i<n; i++) {
            int j = i+gap-1;
            if(j>=n) continue;
            if(s[i]==s[j]){
                if(gap == 1){
                    dp[i][j] = 1;
                    res = s.substr(i,gap);
                    maxi = 1;
                    continue;
                }
                if(gap == 2){
                    dp[i][j] = 2;
                    res = s.substr(i,gap);
                    maxi = 2;
                    continue;
                }
                if(dp[i+1][j-1]){
                    dp[i][j] = gap;
                    if(gap>maxi){
                        res = s.substr(i,gap);
                        maxi = gap;
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return res;
}



//   T-O(n) manachers algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string t = "#";
        for (int i = 0; i < n; i++) {
            t += s[i];
            t += "#";
        }
        n = t.size();

        vector<int> p(n, 0);
        int c = 0, r = 0;
        int maxLen = 0, center = 0;
        for (int i = 0; i < n; i++) {
            int i_mirror = 2 * c - i;
            if (i < r) {
                p[i] = min(r - i, p[i_mirror]);
            }

            int a = i + (1 + p[i]), b = i - (1 + p[i]);
            while (a < n && b >= 0 && t[a] == t[b]) {
                p[i]++;
                a++;
                b--;
            }

            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }
            if (p[i] > maxLen) {
                maxLen = p[i];
                center = i;
            }
        }

        return s.substr((center - maxLen) / 2, maxLen);
    }
};