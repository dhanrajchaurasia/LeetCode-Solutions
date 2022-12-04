//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int mx;
    int recur(int i, vector<int> &A, int target, int mx, vector<vector<int>> &dp){
        if (i == A.size()){
            return target == 0;
        }
        if (dp[i][target + mx] != -1){
            return dp[i][target + mx];
        }
        int &ans = dp[i][target + mx] = recur(i + 1, A, target + A[i], mx, dp);
        ans += recur(i + 1, A, target - A[i], mx, dp);
        return ans;
    }
    int findTargetSumWays(vector<int>&A ,int target) {
        mx = 0;
        for (auto &e : A){
            mx += e;
        }
        if (abs(target) > mx){
            return 0;
        }
        mx += abs(target) + 1;
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(2 * mx, -1));
        return recur(0, A, target, mx, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends