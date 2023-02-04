class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s){
            if(c == '(' or c == '{' or c == '['){
                st.push(c);
            }
            else{
                if(st.size() == 0) return false;
                char ch = st.top(); st.pop();
                if((ch == '(' and c == ')') or (ch == '{' and c == '}') or(ch == '[' and c == ']'))
                    continue;
                else return false;
            }
        }
        return (st.size() == 0 ? true: false);
    }
};