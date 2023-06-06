//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    void reverse(Node * &head){
        
        Node *prev = NULL, *curr = head, *forward;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
    }
    
    Node* addOne(Node *head) 
    {
        
        reverse(head);
        Node *temp = head;
        int carry = 1;
        int sum = 0;
    
        while(temp != NULL){
            sum = temp->data;
            sum += carry;
            carry = sum/10;
            sum = sum%10;
            temp->data = sum;
            temp = temp->next;
            
        }
        
        reverse(head);
        if(carry != 0){
            temp = new Node(carry);
            temp->next = head;
            head = temp;
        }
        
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends