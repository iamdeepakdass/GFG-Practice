//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int cnt = 0, total = m*n;
 	
 		int upperRow = 0, lowerRow = n-1;
 		int leftCol = 0, rightCol = m-1;
 		
 		while(cnt < total){
 		    // Traversing upper row 
 		for(int index = leftCol; index <= rightCol && cnt < total; index++){
 		    cnt++;
 		    if(cnt == k){
 		        return a[upperRow][index];
 		    }
 		}
 		upperRow++;
 		
 		// Traversing right column
 		for(int index = upperRow; index <= lowerRow && cnt < total; index++){
 		    cnt++;
 		    if(cnt == k){
 		        return a[index][rightCol];
 		    }
 		}
 		rightCol--;
 		
 		// Traversing lower row
 		for(int index = rightCol; index >= leftCol && cnt < total; index--){
 		    cnt++;
 		    if(cnt == k){
 		        return a[lowerRow][index];
 		    }
 		}
 		lowerRow--;
 		
 		// Traversing left column
 		for(int index = lowerRow; index >= upperRow && cnt < total; index--){
 		    cnt++;
 		    if(cnt == k){
 		        return a[index][leftCol];
 		    }
 		}
 		leftCol++;
 		}
 		
 		return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends