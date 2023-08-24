//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string num1, string num2) {
       //Your code here
       if (num1 == "0" || num2 == "0") {
        return "0";
    }

    int sign = 1;
    if (num1[0] == '-') {
        sign *= -1;
        num1 = num1.substr(1);
    }
    if (num2[0] == '-') {
        sign *= -1;
        num2 = num2.substr(1);
    }

    int len1 = num1.length();
    int len2 = num2.length();
    vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0');
            int sum = product + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string finalResult = "";
    for (int num : result) {
        finalResult += (num + '0'); // Convert int to char
    }

    // Remove leading zeros
    int nonZeroIndex = 0;
    while (nonZeroIndex < finalResult.length() && finalResult[nonZeroIndex] == '0') {
        nonZeroIndex++;
    }

    finalResult = finalResult.substr(nonZeroIndex);

    if (sign == -1 && finalResult != "0") {
        finalResult = "-" + finalResult;
    }

    return finalResult.empty() ? "0" : finalResult;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends