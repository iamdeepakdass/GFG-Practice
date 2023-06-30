//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stock's price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       // Your code here
       vector<int> ans;
       stack<int> st;
       
       for(int i=0; i<n; i++){
            
            // we try to find the previous greater element in the stack
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            // if the stack is empty, simply push i+1, else i-st.top()
            ans.push_back(st.empty() ? (i == 0 ? 1 : i+1) : i-st.top());
            
            //we push the current element in order to use it for further elements
            st.push(i);
       }
       
       return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends