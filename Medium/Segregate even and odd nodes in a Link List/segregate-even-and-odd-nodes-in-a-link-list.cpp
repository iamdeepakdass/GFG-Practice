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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(N == 1 || head == NULL || head->next == NULL) return head;
        vector<int> v;
        
        Node *temp = head;
        while(temp != NULL){
            int n = temp->data;
            if(!(n&1))v.push_back(n);
            temp = temp->next;
        }
        temp = head;
        
        while(temp != NULL){
            int n = temp->data;
            if((n&1))v.push_back(n);
            temp = temp->next;
        }
        
        temp = head;
        int i = 0;
        
        while(temp != NULL){
            temp->data = v[i++];
            temp = temp->next;
        }
        
        // Node *j = head, *i = head;
        
        // while(i != NULL && j != NULL){
        //     int inum = i->data;
        //     if(!(inum&1)){
        //         swap(i->data, j->data);
        //         j = j->next;
        //     }
        //     i = i->next;
        // }
        
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends