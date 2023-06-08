//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* reverse(Node *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node *prev = NULL, *curr = head, *n = NULL;
        
        while(curr != NULL){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        if(first == NULL){
            return second;
        }
        else if(second == NULL){
            return first;
        }
        
        Node *h1 = reverse(first);
        Node *h2 = reverse(second);
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        
        //cout<<h1->data<<" "<<h2->data<<"\n";
        int carry = 0;
        while(h1 || h2 || carry){
            int sum = 0;
            if(h1){
                sum += h1->data;
                h1 = h1->next;
            }
            
            if(h2){
                sum += h2->data;
                h2 = h2->next;
            }
            sum += carry;
            
            Node *newNode = new Node(sum%10);
            temp->next = newNode;
            temp = newNode;
            carry = sum/10;
            
        }
        dummy->next = reverse(dummy->next);
        return dummy->next;
        
        //return dummy;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends