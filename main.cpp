#include<stdio.h>
#include<stdlib.h>
struct listNode
{
    int data;
    struct listNode *next;
}*head;

typedef struct listNode node;

void createList(){
    node *newNode;int x;
    newNode = (node*)malloc(sizeof(node));
    if(!newNode)
    {
        printf("Memory Full!!");
        return;
    }
    printf("Enter the data::");
    scanf("%d",&newNode->data);
    head = newNode;
    newNode->next = NULL;
}

void insertEnd(int data){
    node *p,*q,*newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    p = head;
    while(p!=NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = newNode;
    newNode->next = NULL;
}

void insertRandom(int data, int position){
    int k = 1;
    node *q,*p,*newNode;
    newNode = (node*)malloc(sizeof(node));
    if(!newNode)
    {
        printf("Memory Full!!");
        return;
    }
    newNode->data = data;
    p = head;
    if(position==1)
    {
        head = newNode;
        newNode->next = p;
        return;
    }
    while(p!=NULL && k<position)
    {
        k++;
        q = p;
        p = p->next;
    }
    q->next = newNode;
    newNode->next = p;
}

void deleteBeg(){
    
    if(head == NULL)
    {
        printf("LIST EMPTY!!!");
        return;
    }

    node *temp;
    temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd(){
        
    if(head == NULL)
    {
        printf("LIST EMPTY!!!");
        return;
    }

    node *p,*q;
    p = head;
    while(p->next!=NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
}

void deleteRandom(int position){
    
    if(head == NULL)
    {
        printf("LIST EMPTY!!!");
        return;
    }

    int k=1;
    node *temp,*q,*p;
    p = head;
    while(p!=NULL && k<position)
    {
        k++;
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
}

void insertBeg(int data)
{
   node *newNode,*p;
    newNode = (node*)malloc(sizeof(node));
    if(!newNode)
    {
        printf("Memory Full!!");
        return;
    }
    newNode->data = data;
    p = newNode;
    newNode->next = head;
    head = p;
}

void displayList(){
    if(head == NULL)
    {
        printf("LIST EMPTY!!!");
        return;
    }
    int k=1;
    node *p;
    p = head;
    while(p!=NULL)
    {
        printf("Element %d: %d ",k,p->data);
        p = p->next;
        k++;
    }
}
void Reverse(){

    if(head == NULL)
    {
        printf("LIST EMPTY!!!");
        return;
    }
    node *temp = NULL,*nextNode = NULL;
    while(head)
    {
        nextNode = head->next;
        head->next = temp;
        temp = head;
        head = nextNode;
    }
    head = temp;
    printf("===The List has been reversed===");
}


void main()
{
    char ch1;int ch2;
    int choice,data,position; 
    printf("Do You want to create a Link List?(Y/N)::");
    scanf("%c",&ch1);
    (ch1=='y'||ch1=='Y') ? createList() : exit(0);
    do
    {
        printf("\nchoose from the following options::");
        printf("\n1.Insert at the end::");
        printf("\n2.Insert at the Beginning::");
        printf("\n3.Insert at a random position::");
        printf("\n4.delete at the end::");
        printf("\n5.delete at the beginning::");
        printf("\n6.delete at any random position::");
        printf("\n7.Display the list::");
        printf("\n8.reverse the list::");
        printf("\nEnter::");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter the Data::");
            scanf("%d",&data);
            insertEnd(data);
            break;
            
            case 2:
            printf("\nEnter the Data::");
            scanf("%d",&data);
            insertBeg(data);
            break;

            case 3:
            
            printf("\nEnter the Data and position::");
            scanf("%d%d",&data,&position);
            insertRandom(data,position);
            break;

            case 4:
            
            printf("Data has been deleted==>");
            deleteEnd();
            break;
            
            case 5:

            deleteBeg();
            printf("\nData has been deleted==>");
            break;

            case 6:

            printf("\nEnter the position::");
            scanf("%d",&position);
            deleteRandom(position);
            printf("\nData has been deleted==>");
            break;

            case 7:
            
            displayList();
            
            break;

            case 8:

            Reverse();
            
            break;
        }
        printf("\nDo You want to continue?(for yes->(1)::");
        scanf("%d",&ch2);
    }while(ch2==1);
}