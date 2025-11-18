#include <stack>
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr = "";

        for (int i = 0; i <= path.length() ; i++) {
            if(i == path.size() || path[i] == '/'){
                if (curr == "..") {
                    if (!st.empty())
                        st.pop();
                }
                else if(!(curr == "" || curr == ".")){
                    st.push(curr);
                }
                curr = "";
            }else{
                curr+= path[i];
            }
        }
        if (st.empty()) return "/";

         string res = "";
        while (!st.empty()) {
            res ="/" + st.top() + res;
            st.pop();
        }
        
        return res;
    }
};