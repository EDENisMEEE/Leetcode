class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        stack<char>st_rv;
        stack<char>st;
        for(char c:s){
            if(st_rv.empty())st_rv.push(c);
            else{
                if(st_rv.top() == c)st_rv.pop();
                else st_rv.push(c);
            }
        }
        while(!st_rv.empty()){
            st.push(st_rv.top());
            st_rv.pop();
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};