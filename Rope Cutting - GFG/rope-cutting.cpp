//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
        vector<int> RopeCutting(int a[], int n)
    {
        // Complete the function
        sort(a, a + n);
        vector<int> ans;
        long long cur = 0;
        for (int i = 0; i < n;){
            a[i] -= cur;
            cur += a[i];
            while (i < n and a[i] <= cur){
                a[i] -= cur;
                i++;
            }
            if (i != n){
                ans.push_back(n - i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{   
    int T;
    cin>> T;
    while(T--)
    {
       	int n;
       	cin>>n;
       	int arr[n+1];
       	for(int i=0;i<n;i++)
       	   cin>>arr[i];
        
        vector<int> v;
        Solution ob;
        v = ob.RopeCutting(arr, n);
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
        
        
    }
  return 0;
}
// } Driver Code Ends