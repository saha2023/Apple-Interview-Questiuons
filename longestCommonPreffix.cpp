// trie solution  T-> O(n*m)
class Trie{
public:
    unordered_map<char,Trie*> child;
    bool isword=false;
};
class Solution {
private:
    void insert(Trie* node, string &w){
        for(char c: w){
            if(node->child[c] == NULL){
                node->child[c] = new Trie();
            }
            node = node->child[c];
        }
        node->isword = 1;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *root = new Trie();
        for(string &s: strs){
            insert(root, s);
        }

        string res = "";
        while(root and root->child.size() == 1 and root->isword == false){
            auto [c, ptr] = *root->child.begin();
            res += c;
            root = ptr;
        }
        return res;
    }
};



//2ND Approach
//sorting T-> max_len*nlog(n)
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string res = "";
        int n = str.size();
        
        sort(str.begin(),str.end());
        
        string a = str[0], b = str[n-1];
        
        for(int i=0;i<a.size();i++){
            if(a[i] == b[i]){
                res += a[i];
            }
            else{
                break;
            }
        }
        return res;
    }
};