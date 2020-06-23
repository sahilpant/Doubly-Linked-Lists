#include<bits/stdc++.h>

using namespace std;

struct DLLNode
{
    int data;
    struct DLLNode *left = NULL;
    struct DLLNode *right = NULL;
}*head = NULL;

typedef struct DLLNode node;

void create(){
    int data;
    node *NewNode;
    NewNode = new node;
    cout<<"Enter the data for the first node::";
    cin>>data;
    NewNode->data = data;
    head = NewNode;
}

void insertbeg(int data){
    node *NewNode;
    NewNode = new node;
    NewNode->data = data;
    NewNode->right = head;
    head = NewNode;
}

void show(){
    node *p;
    p = head;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->right;
    }
}

void RandomInsert(int data,int pos){
    node *temp, *p, *q, *NewNode;
    NewNode = new node;
    NewNode->data = data;
    int ctr = 1;
    p = head;
    if(pos==1){    
        NewNode->right = head;
        head = NewNode;
    }
    else{
        while(p->right!=NULL&& ctr < pos){
            q = p;
            p = p->right;
            ctr++;
        }
        if(p->right==NULL){
            p->right = NewNode;
            NewNode->left = p;
            NewNode->right = NULL;
        }
        else{
            p->left = NewNode;
            NewNode->right = p;
            q->right = NewNode;
            NewNode->left = q;
        }
    }
}

void InsertEnd(int data){
    node *NewNode, *p,*q;
    NewNode = new node;
    NewNode->data = data;
    p = head;
    while(p){
        q = p;
        p = p->right;
    }
    q->right = NewNode;
    NewNode->left = q;
    NewNode->right = NULL;
}


int main(){
    create();
    insertbeg(-1);
    insertbeg(-2);
    insertbeg(-3);
    show();
    cout<<"\n";
    RandomInsert(2,5);
    InsertEnd(3);
    show();
}