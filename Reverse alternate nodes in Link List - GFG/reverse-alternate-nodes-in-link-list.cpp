//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
Node*reversell(Node*head)
{
    Node*prev=NULL,*curr=head;
    Node*nex;
    while (curr!=NULL)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;
}
// void print(Node *head)
// {
//     Node*temp=head;
//     while(temp!=NULL)
//     {
//         cout<<temp->data<<"->";
//         temp=temp->next;
//     }
//     cout<<endl;
// }
class Solution
{
    public:
    void rearrange(struct Node *head)
    {
        Node*temp=head;
        Node*even=new Node (-1);
        Node*b=even;
        int i=1;
        while (temp!=NULL)
        {
            if (i%2==0)
            {
                b->next=new Node(temp->data);
                b=b->next;
            }
            i++;
            temp=temp->next;
        }
        even=reversell(even->next); 
        temp=head;
        while (temp->next!=NULL && temp->next->next!=NULL)
        {
            temp->next=temp->next->next;
            temp=temp->next;
        }
        temp->next=even;
        
        //add code here
    }
};




//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends