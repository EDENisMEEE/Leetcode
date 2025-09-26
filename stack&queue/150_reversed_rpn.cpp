class Solution {
    bool issymbol(string token){
        if(token == "+" || token == "-" || token =="*" || token == "/")
            return true;
        return false;
    }
    int calculate(string token, int a, int b){
        int val;
        if(token == "+")val = a + b;
        else if(token == "-")val = a - b;
        else if(token == "*")val = a * b;
        else if(token == "/")val = a / b;
        return val;
    }
public:
    int evalRPN(vector<string>& tokens) {
       int ans;
       stack<int>st;
       for(string token:tokens){
        if(!issymbol(token))st.push(stoi(token));
        else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int result = calculate(token, b, a);
            st.push(result);
        }
       }
        ans = st.top();
        return ans;

    }
    
};