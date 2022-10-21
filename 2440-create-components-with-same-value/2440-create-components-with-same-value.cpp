class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int sum = 0, n = nums.size();
        for (auto &e : nums)
            sum += e;
        int ans = 0;
        vector<vector<int>> adj(n);
        for (auto &e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        auto dfs = [&](int x, int par, int target, auto &&dfs)->int{
            // check if the tree can be splitted into connected components of sum = x
            int res = nums[x];
            for (auto &e : adj[x]){
                if (e == par) continue;
                res += dfs(e, x, target, dfs);
            }
            if (res == target)
                return 0;
            return res;
        };
        for (int i = 1; i * i <= sum; i++){
            if (sum % i == 0){
                int x = i, y = sum / i;
                if (!dfs(0, -1, x, dfs))
                    ans = max(ans, y - 1);
                
                if (!dfs(0, -1, y, dfs))
                    ans = max(ans, x - 1);
            }
        }
        return ans;
    }
};