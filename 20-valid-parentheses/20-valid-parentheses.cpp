class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char c = st.top();
                st.pop();
                if(s[i] == ')' && c == '(' or s[i] == '}' && c == '{' or s[i] == ']' && c == '[') continue;
                else return false;
            }
        }
        return st.empty();       
    }
};