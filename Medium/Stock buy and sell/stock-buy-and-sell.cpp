//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here
    vector<vector<int>> ans;
    int minIndex = 0;
    int maxIndex = 0;
    
    for(int i=1; i<n; i++){
        if(price[maxIndex] <= price[i]){
            maxIndex++;
        }
        else{
            if(maxIndex > minIndex){
                ans.push_back({minIndex, maxIndex});
            }
            maxIndex++;
            minIndex = maxIndex;
        }
    }
    
    if(maxIndex > minIndex){
        ans.push_back({minIndex, maxIndex});
    }
    
    int len = ans.size();
    if(len == 0){
        cout<<"No Profit";
    }
    
    for(int i=0; i<len; i++){
        cout<<"("<<ans[i][0]<<" "<<ans[i][1]<<") ";
    }
    cout<<"\n";
}