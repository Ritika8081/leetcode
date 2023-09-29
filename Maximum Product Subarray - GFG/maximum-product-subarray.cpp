//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	  
    
    if(n == 0) return 0;

    long long maxEndingHere = arr[0];
    long long minEndingHere = arr[0];
    long long maxSoFar = arr[0];

    for(int i = 1; i < n; i++) {
        long long temp = maxEndingHere;
        maxEndingHere = max((long long)arr[i], max(maxEndingHere * arr[i], minEndingHere * arr[i]));
        minEndingHere = min((long long)arr[i], min(temp * arr[i], minEndingHere * arr[i]));

        maxSoFar = max(maxSoFar, maxEndingHere);
    }

    return maxSoFar;


	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends