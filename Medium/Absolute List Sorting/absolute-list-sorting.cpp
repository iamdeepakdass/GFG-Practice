//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


// } Driver Code Ends
/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    
public:

    Node *findMid(Node *head){
        
        if(head == NULL || head->next == NULL){
            return head;
        }        
        
        Node *slow = head;
        Node *fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node *merge(Node *l, Node *r){
    
    if(l == NULL){
        return r;
    }
    if(r == NULL){
        return l;
    }
    
    Node *dummy = new Node;
    dummy->data = -1;
    Node *temp = dummy;
    
    while(l && r){
        if(l->data <= r->data){
            temp->next = l;
            temp = l;
            l = l->next;
        }
        else{
            temp->next = r;
            temp = r;
            r = r->next;
        }
    }
    
    while(l != NULL){
        temp->next = l;
        temp = l;
        l = l->next;
    }
    
    while(r != NULL){
        temp->next = r;
        temp = r;
        r = r->next;
    }
    
    return dummy->next;
    
    }
    
    Node* sortList(Node* head)
    {
        // Your Code Here
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node *left = head;
        Node *mid = findMid(head);
        Node *right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        Node *ans = merge(left, right);
        
        return ans;
        
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}

// } Driver Code Ends