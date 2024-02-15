#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[100];
    int number;
    struct node *next;
} *head;

struct node2
{
    char pass[100];
    struct node2 *next;
} *head2;

char makepass(struct node *temp)
{
    double scientificnotation;
    scientificnotation=(double)temp->number;
    
}
int main()
{
    int input;
    struct node *newnode, *temp, *temp2;

    printf("Enter the no. of inputs : ");
    scanf("%d", &input);

    if (input != 0)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        while (1)
        {
            printf("Enter the no. you want to use : ");
            scanf("%d", &newnode->number);
            if (sizeof(newnode->number) < 1e100)
            {
                printf("Your no. should not exceed 10 digits : ");
                continue;
            }
            else
            {
                break;
            }
        }
        printf("Enter your name : ");
        fgets(newnode->name, sizeof(newnode->name), stdin);
        head = newnode;
        temp = head;
    }

    for (int i = 2; i <= input; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        while (1)
        {
            printf("Enter the no. you want to use : ");
            scanf("%d", &newnode->number);
            if (sizeof(newnode->number) < 1e100)
            {
                printf("Your no. should not exceed 10 digits : ");
                continue;
            }
            else
            {
                break;
            }
        }
        printf("Enter your name : ");
        fgets(newnode->name, sizeof(newnode->name), stdin);
        temp->next = newnode;
        temp = temp->next;
    }
    newnode->next = NULL;

    printf("enter the password by implying these rules:\n1.You will receive a numerical value. Transform the provided decimal number into scientific notation. Simplify all the digits after the decimal point to a single digit by adding all the digits until it becomes single digit, and apply the same rule to the exponent.\n2.Next, create a string by concatenating the first three letters of each digit when expressed as words, while keeping the symbols and letter 'e' unchanged. This resultant string will be denoted as S1.\n3.If the digit resulting from reducing the value of exponent to a single digit is odd, concatenate all the letters at odd positions in the given name (using 1-based indexing). This string is referred to as S2.\n4.Your desired password will be the combination of S1 and S2, separated by an @ symbol, forming the format S1@S2.");
    temp = head;
    do
    {
        newnode = (struct node2 *)malloc(sizeof(struct node2));
        newnode->pass = makepass(temp);
        head2 = newnode;
        temp2=head2;

        for()
        temp = temp->next;
    } while (temp != NULL);
    return 0;
}