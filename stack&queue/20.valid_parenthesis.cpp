class Solution {
public:
    bool isValid(string s) {
        map<char, char>parenthesis = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char>stk;
        for(char c: s){
            if(c == '(' || c == '[' || c == '{' ) stk.push(c);
            else{
                if(stk.empty()) return false;
                else{
                    cout<<parenthesis[c]<<endl;
                    if(stk.top() == parenthesis[c]) {
                        stk.pop();
                    }
                    else{
                        cout<<"bad"<<endl;
                        return false;
                    } 
                }
            }
        }
        if(!stk.empty())return false;
        return true;
    }
};