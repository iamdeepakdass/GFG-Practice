//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
    void reverseLL(Node *s, Node *e){
        Node *prev = NULL, *n = s->next, *curr = s;
        
        while(prev != e){
            curr->next = prev;
            prev = curr;
            curr = n;
            if(n != NULL) n = n->next;
        }
        
    }
   
    Node *reverse(Node *head, int k)
    {
        // code here
        if(head == NULL || head->next == NULL) return head;
        
        Node *dummy = new Node(-1);
        dummy->next = head;
        Node *beforeStart = dummy;
        Node *beforeEnd = NULL;
        
        Node *end = head;
        
        int cnt = 0;
        
        while(end != NULL){
            cnt++;
            if(cnt == k){
                Node *s = beforeStart->next;
                Node *temp = end->next;
                reverseLL(s,end);
                beforeStart->next = end;
                s->next = temp;
                beforeStart = s;
                end = end->next;
                break;
            }
            
            else{
                beforeEnd = end;
                end = end->next;
            }
        }
        
        while(end->next != NULL){
            end = end->next;
        }
        
        Node *s = beforeStart->next;
        reverseLL(s,end);
        beforeStart->next = end;
        s->next = NULL;
        
        return dummy->next;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends