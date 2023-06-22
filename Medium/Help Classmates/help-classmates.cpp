//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int> st;
        st.push(-1);
        
        for(int i=n-1; i>=0; i--){
            
            int curr = arr[i];
            if(st.top() < arr[i]){
                int elem = st.top();
                //st.pop();
                st.push(curr);
                arr[i] = elem;
            }
            else{
                while(st.top() >= arr[i] && !st.empty()){
                    st.pop();
                }
                int elem = st.top();
                //st.pop();
                st.push(curr);
                arr[i] = elem;
            }
        }
        
        return arr;
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
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends