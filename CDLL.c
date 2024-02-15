#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    struct node *prev;
    char data[50];
    struct node *next;
}*head;

int create(int n);
void print(struct node *head);
void adding_at_start(struct node *head);
void adding_at_middle(struct node *head,char data[]);
void adding_at_end(struct node *head);
void del_at_start(struct node *head);
void del_at_middle(struct node *head,char data[]);
void del_at_end(struct node *head);

int main(int argc, char const *argv[])
{
    int noe,choice,sub_choice;
    printf("enter the number of nodes you want to create : ");
    scanf("%d",&n);
    head = create(n);
    do{
        printf("\n1 for printing\n2 for adding\n3 for deleting")
        printf("\nEnter your choice : ")
        scanf("%d",&choice)
        switch (choice)
        {
        case 1:
            print(head);
            break;
        case 2:
        printf("\n1 for adding at start\n2 for adding in between\n3 for adding at end");
        printf("\nEnter your choice : ")
        scanf("%d",sub_choice);
        switch (sub_choice)
        {
        case 1:
            adding_at_start(head);
            break;
        case 2:
        adding_at_mid
        default:
            break;
        }
        default:
            break;
        }
    }while(1);
    return 0;
}

int create(int n)
{
    struct node *temp,*newnode;
    if(n!=0)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter a string for node 1");
        gets(newnode->data);
        head=newnode;
        temp=head;
    }
    for (int i = 2; i <= n; i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter a string for node %d",i);
        gets(newnode->data);
        temp->next=newnode;
        newnode->prev=temp;
        temp=temp->next;
    }
    temp->next=head;
    head->prev=temp;
}

void print(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        print("prev = %d  data = %s next = %d",temp->prev,temp->data,temp->next);
        temp=temp->next;
    }
}

void adding_at_start(struct node *head)
{
    struct node *new_node;   
    char data[50];
    printf("enter the data of the new node : ");
    fgets(data,50,stdin);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->prev=NULL;
    new_node->data=data;
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

viod adding_at_middle(struct node *head,char data[])
{
    struct node *temp,*new_node;
    char data1[50];
    printf("enter the data of the new node");
    fgets(data1,50,stdin);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->prev=NULL;
    new_node->data=data1;
    new_node->next=NULL;
}
 void adding_at_end(struct node *head)
 {
    struct node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=tmep->next;
    }
    
 }