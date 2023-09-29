//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        // Step 1: Sort the array
    sort(arr, arr+n);

    // Step 2: Traverse the array
    for(int i=0; i<n-2; i++) {
        // Fix the current element
        int x = arr[i];

        // Initialize two pointers for the sub-array on the right
        int l = i+1, r = n-1;
        
        while(l < r) {
            // Check if the triplet sum is zero
            if(x + arr[l] + arr[r] == 0) return true;

            // If the sum is less than zero, move the left pointer to the right
            else if(x + arr[l] + arr[r] < 0) l++;

            // If the sum is greater than zero, move the right pointer to the left
            else r--;
        }
    }

    // If we reach here, then no triplet was found
    return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends