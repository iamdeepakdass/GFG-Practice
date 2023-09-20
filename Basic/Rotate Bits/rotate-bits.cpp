//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        int rightRotate(int n, int d){
            int keep = n>>d;
            int lost = n<<(16-d);
            return (lost | keep) & 0xFFFF;
        }
        
        int leftRotate(int n, int d){
            int keep = n<<d;
            int lost = n>>(16-d);
            return (lost | keep) & 0xFFFF;
        }
        
        vector<int> rotate (int n, int d)
        {
            //code here.
            d %= 16;
            int left = leftRotate(n,d);
            int right = rightRotate(n,d);
            
            vector<int> ans{left, right};
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends