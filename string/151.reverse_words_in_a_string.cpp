class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        stack<string> strs;
        string s1 ="";
        bool flag;
        for(int i = 0;i<s.size();i++){
            if(s[i]!= ' '){
                s1+=s[i];
                flag = 1;
            }
            else {
                if(flag==1){
                    strs.push(s1);
                }
                s1 = "";
                flag = 0;
            }
            
        }
        if(flag == 1)strs.push(s1);//the last word won't be included without this line

        while(!strs.empty()){
            string str = strs.top();
            strs.pop();
            ans+=str;
            if(!strs.empty()) ans+=" ";
        }
        return ans;
        

    }
};