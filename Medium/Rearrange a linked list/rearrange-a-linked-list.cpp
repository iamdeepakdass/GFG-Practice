//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Node structure

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
    void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
       int n = 0;
       Node *curr = head;
       
       Node *dummy = new Node(-1);
       Node *dummy2 = new Node(-1);
       
       Node *oddTail = dummy;
       Node *evenTail = dummy2;
       
       while(curr){
           n++;
           if(n&1){
               Node *temp = curr;
               curr = curr->next;
               oddTail->next = temp;
               temp->next = NULL;
               oddTail = temp;
           }
           else{
               Node *temp = curr;
               curr = curr->next;
               evenTail->next = temp;
               temp->next = NULL;
               evenTail = temp;
           }
       }
       
       oddTail->next = dummy2->next;
       dummy2->next = NULL;
       
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends