//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      // Step 1: Convert the array to an unordered_set for O(1) look-up time.
    unordered_set<int> s;
    for(int i = 0; i < N; i++) {
        s.insert(arr[i]);
    }
    
    int longest_sequence = 0;
    
    // Step 2: Iterate through each element in the array.
    for(int i = 0; i < N; i++) {
        if(s.find(arr[i] - 1) == s.end()) {
            int current_num = arr[i];
            int current_sequence = 1;

            // Keep checking for the next elements in the sequence.
            while(s.find(current_num + 1) != s.end()) {
                current_num++;
                current_sequence++;
            }

            // Update the length of the longest sequence if necessary.
            longest_sequence = max(longest_sequence, current_sequence);
        }
    }

    // Step 3: Return the length of the longest sequence.
    return longest_sequence;
}


    
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends