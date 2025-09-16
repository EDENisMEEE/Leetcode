class Solution {
public:
    void swap(char &a, char &b){
        char tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    void reverseString(vector<char>& s) {
        int size = s.size();
        if(size == 0) return;
        for(int i = 0, j = size-1; i<(size/2); i++, j--){
            swap(s[i], s[j]);
        }
    }
};