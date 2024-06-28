class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> v;
        int hash_min[26] = {0};
        
        // initialize thr hashmap which stores the minimum number of common char among the considered strings
        for(char c:words[0]){
            hash_min[c-'a']++;
        }
        //compare the min_hashmap to the hashmap of each strings
        for(int i = 1;i < words.size();i++){
            int hash_other[26] = {0};
            for(char c: words[i]){
                hash_other[c-'a']++;
            }
            for(int i = 0;i<26;i++){
                hash_min[i] = min(hash_min[i], hash_other[i]);
            }
        }
        for(int i = 0;i<26;i++){
            string sing = string(1,i+'a');
            while(hash_min[i]){
                v.push_back(sing);
                hash_min[i] --;
            }
        }
        return v;
    }
};