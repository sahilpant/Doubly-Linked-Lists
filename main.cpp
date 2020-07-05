#include<bits/stdc++.h>

using namespace std;

struct DLLNode
{
    int data;
    struct DLLNode *left = NULL;
    struct DLLNode *right = NULL;
}*head = NULL;

int n = 0;
typedef struct DLLNode node;

void CreateList(){
    int data;
    node *NewNode;
    NewNode = new node;
    cout<<"Enter the data for the first node::";
    cin>>data;
    NewNode->data = data;
    head = NewNode;
    n++;
}

void InsertBeg(int data){
    node *NewNode;
    NewNode = new node;
    NewNode->data = data;
    NewNode->right = head;
    head = NewNode;
    n++;
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
        while( p && ctr < pos ){
            q = p;
            p = p->right;
            ctr++;
        }
        if(q->right==NULL){
            q->right = NewNode;
            NewNode->left = q;
            NewNode->right = NULL;
        }
        else{
            p->left = NewNode;
            NewNode->right = p;
            q->right = NewNode;
            NewNode->left = q;
        }
    }
    n++;
}

void InsertEnd(){
    if(n==0)
    {
        CreateList();
        return;
    }
    int data;
    cout<<"Enter the data::";
    cin>>data;
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
    n++;
}

void DeleteBeg(){
    if(head == NULL)
    {
        cout<<"LIST IS EMPTY";
        return;
    }
    node *temp;
    temp = head;
    head = head->right;
    delete(temp);
    n--;
}

void DeleteEnd()
{
    if(n==1)
    {
        DeleteBeg();
        return;
    }
    if(head == NULL)
    {
        cout<<"LIST IS EMPTY";
        return;
    }
    node *p, *q, *temp;
    p = head;
    while(p)
    {
        q = p;
        p = p->right;
    }
    temp = q->left;
    temp->right = NULL;
    delete(q);
    n--;
}

void DeleteRandom(int pos){
    if(head == NULL)
    {
        cout<<"LIST IS EMPTY";
        return;
    }
    if(pos==1){
        DeleteBeg();
        return;
    }
    node *p, *q, *temp;
    int ctr = 1;
    p = head;
    while(p && ctr < pos){
        q = p;
        p = p->right;
        ctr++;
    }
    if(p->right==NULL){
        DeleteEnd();
        return;
    }
    else{
        temp = p->right;
        q->right = temp;
        temp->left = q;
    }
    n--;
}

void Reverse() {
    if(head == NULL)
    {
        cout<<"LIST IS EMPTY";
        return;
    }
    node *temp,*p;
    while(head->right)
    {
        p = head;
        head = head->right;
        temp = p->left;
        p->left = p->right;
        p->right = temp;
    }
        temp = head->left;
        head->left = head->right;
        head->right = temp;
}


void show(){
    int line = n;
    if(head == NULL)
    {
        cout<<"LIST IS EMPTY";
        return;
    }
    node *p;
    p = head;
    while(p)
    {
        --line;
        cout<<p->data;
        if(line) cout<<"--";
        p = p->right;
    }
}

int main(){
    char ch1,ch2;
    int choice,data,position;
    cout<<"Do you want to create a Doubly Linked List::";
    cin>>ch1;
    (ch1=='y'||ch1=='Y') ? CreateList() : exit(0);
    do{
        cout<<"\nchoose from the following options::";
        cout<<"\n1.Insert at the end::";
        cout<<"\n2.Insert at the Beginning::";
        cout<<"\n3.Insert at a random position::";
        cout<<"\n4.delete at the end::";
        cout<<"\n5.delete at the beginning::";
        cout<<"\n6.delete at any random position::";
        cout<<"\n7.Display the list::";
        cout<<"\n8.reverse the list::";
        cout<<"\n9.Display the number of nodes::";
        cout<<"\nEnter::";
        cin>>choice;
        switch(choice)
        {
            case 1:
            InsertEnd();
            break;
            
            case 2:
            cout<<"\nEnter the Data::";
            cin>>data;
            InsertBeg(data);
            break;

            case 3:
            
            cout<<"\nEnter the Data and position::";
            cin>>data>>position;
            RandomInsert(data,position);
            break;

            case 4:

            if(head!=NULL) cout<<"Data has been deleted";
            DeleteEnd();
            break;
            
            case 5:

            if(head!=NULL) cout<<"Data has been deleted";
            DeleteBeg();

            
            break;

            case 6:

            cout<<"\nEnter the position::";
            cin>>position;
            if(n>=1) cout<<"Data has been deleted";
            DeleteRandom(position);

            
            break;

            case 7:
            
            show();
            
            break;

            case 8:

            Reverse();
            
            break;

            case 9:
            cout<<"\nNo. of nodes are::"<<n;
        }
        cout<<"\nDo You want to continue?(y/n)::";
        cin>>ch2;
    }while(ch2=='y'||ch2=='Y');
}