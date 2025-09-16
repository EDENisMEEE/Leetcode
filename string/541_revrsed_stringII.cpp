class Solution {
void swap(char &a, char &b){
    char tmp;
    tmp = a;
    a = b;
    b = tmp;
}
void reverse(string & str, int begin, int end){
    int size = end-begin+1;
    for(int i = begin, j = end; i<((2*begin+size)/2); i++, j--){
        swap(str[i], str[j]);
    }
}
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        int twok = 2*k;
        int full = (size/twok)*twok;
        for(int i = 0; i<size; i+=twok){
            if((size - i )< k){
                reverse(s, i, size-1);
                break;
            }
            reverse(s, i, i+k-1);
            
        }
        return s;
    }
};