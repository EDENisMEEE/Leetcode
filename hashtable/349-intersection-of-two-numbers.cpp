// the main spirit of this problem is to use "unordered-list"
// which is implemented in red-black tree  
class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            vector<int> inter_record (1005, 0);
            unordered_set<int> inter_result;
            for(int n : nums1){
                inter_record[n] = 1;
            }
            for(int n: nums2){
               if(inter_record[n] == 1){
                    inter_result.insert(n);
               }
            }
            
            return vector<int>(inter_result.begin(), inter_result.end());
        }
    };