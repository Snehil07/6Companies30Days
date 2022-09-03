#include<bits/stdc++.h>
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

void printList(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node *oddhead=NULL,*oddtail=NULL,*evenhead=NULL,*eventail=NULL,*curr=head;
        while(curr!=NULL){
            if(curr->data%2!=0){
                if(oddhead==NULL){
                    oddhead=curr;
                    oddtail=curr;
                }
                else{
                    oddtail->next=curr;
                    oddtail=curr;
                }
            }
            else{
                if(evenhead==NULL){
                    evenhead=curr;
                    eventail=curr;
                }
                else{
                    eventail->next=curr;
                    eventail=curr;
                }
            }
            curr=curr->next;
        }
        if(evenhead==NULL || oddhead==NULL){
            return head;
        }
        eventail->next=oddhead;
        oddtail->next=NULL;
        return evenhead;
    }
};

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int data;
        cin>>data;
        Node *head = new Node(data);
        Node *tail=head;
        for(int i=0;i<n-1;i++){
            cin>>data;
            tail->next=new Node(data);
            tail=tail->next;
        }
        tail->next=NULL; 
        Solution ob;
        Node *ans=ob.divide(n,head);
        printList(ans);
    }
    return 0;
}