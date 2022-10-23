class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (auto &e : nums)
            mp[e]++;
        vector<int> ans;
        for (int i = 0; i < n; i++){
            if (mp[i + 1] > 1)
                ans.push_back(i + 1);
        }
        
        for (int i = 0; i < n; i++){
            if (mp[i + 1] == 0)
                ans.push_back(i + 1);
        }
        return ans;
    }
};