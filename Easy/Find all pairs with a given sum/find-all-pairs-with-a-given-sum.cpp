//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int,int>> ans;
        
        map<int,int> mpp;
        pair<int, int> p;
        
        sort(A, A + N);
        sort(B, B + M);
        
        int i = 0; 
        int j = M - 1;
        
        while(i < N && j >= 0){
            
            int sum = A[i] + B[j];
            
            if(sum == X){
                p.first = A[i];
                p.second = B[j];
                ans.push_back(p);
                i++;
                j--;
            }
            
            else if(sum < X){
                i++;
            }
            else{
                j--;
            }
        }
        
        // for(int i=0; i<M; i++){
        //     mpp[B[i]]++;
        // }
        
        // int reqd = 0;
        
        // for(int i=0; i<N; i++){
        //     reqd = X-A[i];
            
        //     if(mpp.find(reqd) != mpp.end()){
        //         p.first = A[i];
        //         p.second = reqd;
        //         ans.push_back(p);
        //     }
            
        // }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends