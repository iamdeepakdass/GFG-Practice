//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution{
	
	
	public:
	vector<long long> findMissing(long long A[], long long B[], int N, int M) 
	{ 
	    // Your code goes here
	    unordered_map<ll, bool> mpp;
	    vector<ll>ans;
	    for(int i=0; i<M; i++){
	        if(mpp[B[i]] == true){
	            continue;
	        }
	        mpp[B[i]] = true;
	    }
	    
	    for(int i=0; i<N; i++){
	        if(mpp.find(A[i]) == mpp.end()){
	            ans.push_back(A[i]);
	        }
	    }
	    return ans;
	} 
};
	

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        int m;
        cin>>m;
        long long a[n];
        long long b[m];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<m;i++)
        cin >> b[i];
        vector<long long> ans;
        

        Solution ob;
        ans=ob.findMissing(a,b,n,m);
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends