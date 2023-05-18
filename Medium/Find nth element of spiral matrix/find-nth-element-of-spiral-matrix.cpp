//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(int [MAX][MAX],int ,int ,int );
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
        cout<<findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int findK(int a[MAX][MAX], int n, int m, int k)
{
//Your code here

        int startRow = 0;
        int lastRow = n-1;
        int startCol = 0;
        int lastCol = m-1;
        vector<int> mat_element;
        int count = 0;
        int total = n*m;
        
        while(count < total){
            // Printing upper row
            for(int index = startCol; count<total &&  index<=lastCol; index++){
                mat_element.push_back(a[startRow][index]);
                count++;
                if(count == k){
                    return a[startRow][index];
                }
            }
            startRow++;
            
            // Printing Right Column
            for(int index =startRow; count<total &&  index <= lastRow; index++){
                mat_element.push_back(a[index][lastCol]);
                count++;
                if(count == k){
                    return a[index][lastCol];
                }
            }
            lastCol--;
            
            // Printing lower row
            
            for(int index = lastCol; count<total &&  index >= startCol; index--){
                mat_element.push_back(a[lastRow][index]);
                count++;
                if(count == k){
                    return a[lastRow][index];
                }
            }
            lastRow--;
            
            // Printing left column
            
            for(int index = lastRow; count<total &&  index>=startRow; index--){
                mat_element.push_back(a[index][startCol]);
                count++;
                if(count == k){
                    return a[index][startCol];
                }
            }
            startCol++;
        }
        
        return -1;
}

