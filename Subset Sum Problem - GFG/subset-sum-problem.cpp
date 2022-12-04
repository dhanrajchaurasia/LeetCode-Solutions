//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int dp[101][10001];
    int recur(int i, int sum, vector<int> &arr){
        if (i == arr.size()){
            return sum == 0;
        }
        if (sum < 0){
            return 0;
        }
        if (dp[i][sum] != -1){
            return dp[i][sum];
        }
        int &ans = dp[i][sum] = recur(i + 1, sum, arr);
        ans = max(ans, recur(i + 1, sum - arr[i], arr));
        return ans;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        memset(dp, -1, sizeof(dp));
        return recur(0, sum, arr);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends