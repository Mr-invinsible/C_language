#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *prev;
    char data[50];
    struct node *next;
} *head;

void create(int n);
void print(/*struct node *head*/);
void adding_at_start(/*struct node *head*/);
void adding_at_middle(/*struct node *head,*/ char key[]);
void adding_at_end(/*struct node *head*/);
void del_at_start(/*struct node *head*/);
void del_at_middle(/*struct node *head,*/ char key[]);
void del_at_end(/*struct node *head*/);

int main(int argc, char const *argv[])
{
    int noe, choice, sub_choice;
    char key[50];
    printf("enter the number of nodes you want to create : ");
    scanf("%d", &noe);
    fflush(stdin);
    create(noe);
    do
    {
        printf("\n1 for printing\n2 for adding\n3 for deleting");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            print(/*head*/);
            break;
        case 2:
            printf("\n1 for adding at start\n2 for adding in between\n3 for adding at end");
            printf("\nEnter your choice : ");
            scanf("%d", &sub_choice);
            fflush(stdin);
            switch (sub_choice)
            {
            case 1:
                adding_at_start(/*head*/);
                break;
            case 2:
                printf("\nenter the string before which you want to add : ");
                fgets(key, 50, stdin);
                adding_at_middle(/*head,*/ key);
                break;
            case 3:
                adding_at_end(/*head*/);
                break;
            default:
                printf("\nwrong choice!!");
                break;
            }
            break;
        case 3:
            printf("\n1 for deleting at start\n2 for deleting at middle\n3 for deleting at end");
            printf("\nenter your choice : ");
            scanf("%d", &sub_choice);
            fflush(stdin);
            switch (sub_choice)
            {
            case 1:
                del_at_start(/*head*/);
                break;
            case 2:
                printf("\nenter the string you want to delete : ");
                fgets(key, 50, stdin);
                del_at_middle(/*head,*/key);
                break;
            case 3:
                del_at_end(/*head*/);
                break;
            default:
                printf("\nwrong choice!!");
                break;
            }
            break;
        default:
            printf("wrong choice!!");
            break;
        }
    } while (1);
    return 0;
}

void create(int n)
{
    struct node *temp, *newnode;
    if (n != 0)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter a string for node 1 : ");
        fgets(newnode->data, 50, stdin);
        head = newnode;
        temp = head;
    }
    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter a string for node %d : ", i);
        fgets(newnode->data, 50, stdin);
        temp->next = newnode;
        newnode->prev = temp;
        temp = temp->next;
    }
    temp->next = head;
    head->prev = temp;
}

void print(/*struct node *head*/)
{
    struct node *temp;
    temp = head;
    do
    {
        printf("\nprev = %d  data = %s next = %d", temp->prev, temp->data, temp->next);
        temp = temp->next;
    }while (temp != head);
}

void adding_at_start(/*struct node *head*/)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("enter the data of the new node : ");
    fgets(new_node->data, 50, stdin);
    new_node->prev = head->prev;
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    new_node->prev->next=new_node;
}

void adding_at_middle(/*struct node *head,*/ char key[])
{
    struct node *temp, *new_node;
    temp=head;
    printf("enter the data of the new node : ");
    fgets(new_node->data, 50, stdin);
    new_node = (struct node *)malloc(sizeof(struct node));
    while (temp->data != key)
        temp = temp->next;
    new_node->next = temp;
    new_node->prev = temp->prev;
    temp->prev->next = new_node;
    temp->prev=new_node;
}

void adding_at_end(/*struct node *head*/)
{
    struct node *temp, *new_node;
    temp = head;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("enter the string of newnode : ");
    fgets(new_node->data, 50, stdin);
    while (temp->next != head)
        temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = head;
}

void del_at_start(/*struct node *head*/)
{
    struct node *temp;
    temp = head;
    head = head->next;
    head->prev = head->prev->prev;
    free(temp);
}

void del_at_middle(/*struct node *head,*/ char key[])
{
    struct node *temp, *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("enter the string of new node : ");
    fgets(new_node->data, 50, stdin);
    while (temp->data != key)
        temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void del_at_end(/*struct node *head*/)
{
    struct node *temp;
    while (temp->next != head)
        temp = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}