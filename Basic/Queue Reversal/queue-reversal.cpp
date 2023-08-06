//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    
    void solve(queue<int> &q, queue<int> &ans){
        if(q.empty()){
            return;
        }
        else{
            int tp = q.front();
            q.pop();
            solve(q, ans);
            ans.push(tp);
            //return;
            //q.push(tp);
        }
    }
    queue<int> rev(queue<int> q)
    {
        if(q.empty()) return q;
        
        queue<int> ans;
        
        solve(q, ans);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends