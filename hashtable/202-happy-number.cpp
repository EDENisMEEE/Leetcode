#include <cstring>
class Solution {
public:
    bool isHappy(int n) {
        string s = to_string(n);
        int max_size = (81*33);
        vector<bool> counted(max_size, 0);
        n = 0;
        while(1){
            for(char c: s){
                int digit = int(c-'0');
                n+= pow(digit, 2);
            }
            if(n == 1) return true;
            if(counted[n] == true) return false;
            else counted[n] = true;
            s = to_string(n);
            n = 0;
        
        }
    }
};