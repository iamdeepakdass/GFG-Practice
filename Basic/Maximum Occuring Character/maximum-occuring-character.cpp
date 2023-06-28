//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int arr[26] = {0};
        int n = str.size();
        
        for(int i=0; i<n; i++){
            arr[str[i] - 'a']++;
        }
        int cnt = 0;
        int j = 0;
        
        for(int i=0; i<26; i++){
            if(arr[i] > cnt){
                cnt = arr[i];
                j = i;
            }
        }
        
        return 'a' + j;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends