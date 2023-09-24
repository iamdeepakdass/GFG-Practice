//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define  pii pair<int,pair<int,int>>
#define  pi pair<int,int>

class Solution {
  public:
    vector<int> maxCombinations(int N, int k, vector<int> &A, vector<int> &B) {
        // code here
        // int n = A.size(), m = B.size();
        
        // sort(begin(A), end(A));
        // sort(begin(A), end(A));
        
        // set<pair<int,int>> s;
        
        // vector<int> ans;
        // int i = n - 1, j = m - 1;
        
        // while(ans.size() < K && i >= 0 && j >= 0){
        //     int sum = A[i] + B[j];
        //     if(s.find({A[i], B[j]}) == s.end()){
        //         s.insert({A[i], B[j]});
        //         ans.push_back(sum);
        //         if(A[i] > B[j])j--;
        //         else i--;
        //     }
        //     else{
        //         if(A[i] > B[j])j--;
        //         else i--;
        //     }
        // }
        
        
        // return ans;
        
        priority_queue<pii>pq;
       
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        vector<int>ans;
        int idx1=A.size()-1,idx2=B.size()-1;
        
        pq.push({A[idx1]+B[idx2],{idx1,idx2}});
        set<pair<int,int>>s;
        while(k--)
        {   
            idx1=pq.top().second.first;
            idx2=pq.top().second.second;
            if(s.find({idx1,idx2})!=s.end())
            {
                k++;
                pq.pop();
                continue;
            }
            else
            s.insert({idx1,idx2});
            
            ans.push_back(pq.top().first);
           
            pq.pop();
            
            if(idx1-1>=0)
              {
                pq.push({A[idx1-1]+B[idx2],{idx1-1,idx2}});
              }
            if(idx2-1>=0)
              {
                pq.push({A[idx1]+B[idx2-1],{idx1,idx2-1}});
             }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends