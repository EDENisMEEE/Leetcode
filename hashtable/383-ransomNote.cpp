class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int>r;
        map<char, int>m;
        for(char c: ransomNote){
            r[c] += 1;
        }
        for(char c: magazine){
            m[c] += 1;
        }
        for(const auto & p: r){
            if(m.find(p.first) == m.end()) return false;
            else if(m[p.first] < p.second) return false;
        }
        return true;

    }
};