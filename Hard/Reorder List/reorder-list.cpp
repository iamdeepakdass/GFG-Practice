//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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



// } Driver Code Ends
/* Following is the Linked list node structure */

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
    Node *reverse(Node *head){
        if(head == NULL || head->next == NULL) return head;
        
        Node *p = NULL, *c = head, *n = head->next;
        
        while(c != NULL){
            c->next = p;
            p = c;
            c = n;
            if(n != NULL) n = n->next;
        }
        
        return p;
    }
    
    void reorderList(Node* head) {
        // In case only one node is given
        if(head == NULL || head->next == NULL) return;
        
        Node *curr = head;
        int n = 0;
        // Find length of the linked list
        while(curr){
            n++;
            curr = curr->next;
        }
        
        // Find the middle of the linked list
        Node *walker = head;
        Node *runner = head;
        
        while(runner->next != NULL && runner->next->next != NULL){
            walker = walker->next;
            runner = runner->next->next;   
        }
        
        Node *curr1 = head, *curr2 = reverse(walker->next);
        walker->next = NULL;
        
        while(curr1 != NULL && curr2 != NULL){
            Node *temp2 = curr2;
            curr2 = curr2->next;
            Node *temp1 = curr1;
            curr1 = curr1->next;
            
            temp1->next = temp2;
            temp2->next = curr1;
        }
        
        //head = curr1;
        //return;
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends