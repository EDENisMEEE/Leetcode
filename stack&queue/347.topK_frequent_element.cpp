class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>freq;
        vector<int>ans;
        vector<pair<int, int>> p;
        for(int num: nums){
            freq[num] += 1;
        }
        for(const auto & f: freq){
            pair<int, int>pp;
            pp.first = f.first;
            pp.second = f.second;
            p.push_back(pp);
        }
        sort(p.begin(), p.end(), [=](pair<int, int>&a, pair<int, int> &b){
            return a.second>b.second;
        });
        for(int i = 0; i<k; i++){
            ans.push_back(p[i].first);
        }
        return ans;
    }
};