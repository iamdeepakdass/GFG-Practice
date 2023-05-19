//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long

class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        
        ll idx1 = -1;
        ll idx2 = -1;
        
        ll start = 0;
        ll end = v.size() - 1;
        
        // searching for the first index
        while(start <= end){
            ll mid = start + (end - start)/2;
            
            if(v[mid] == x){
                idx1 = mid;
                end = mid - 1;
            }
            
            else if(v[mid] > x){
                end = mid - 1;
            }
            
            else{
                start = mid + 1;
            }
        }
        
        // searching for the second index
        start = 0;
        end = v.size() - 1;
        
        while(start <= end){
            ll mid = start + (end - start)/2;
            
            if(v[mid] == x){
                idx2 = mid;
                start = mid + 1;
            }
            
            else if(v[mid] > x){
                end = mid - 1;
            }
            
            else{
                start = mid + 1;
            }
        }
        
        pair<long,long> p;
        p.first = idx1;
        p.second = idx2;
        
        return p;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends