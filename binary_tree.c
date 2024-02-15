#include <stdio.h>
#include <math.h>
char in_order[7];
char pre_order[7];
int i = 0;
char result[7];
in_order=['d','b','e','a','f','c','g'];//"dbeafcg";
pre_order=['a','b','d','e','c','f','g'];//"abdecfg";
int find(char root)
{
    for (int j = 0; j < 7; j++)
        if (in_order[j] == root)
            return j;
}
void make_tree(int i, int start_index, int end_index)
{
    char root;
    int root_index;
    if (i < 7)
    {
        root = pre_order[i];
        root_index = find(root);
        printf("%c", root);
        make_tree(++i, 0, root_index - 1); // left child
        make_tree(++i, root_index + 1, 6); // right child
    }
}
int main()
{
    // int j;
    printf("enter seven elements for inorder\n");
    // for (j = 0; j < 7; j++)
    // {
    //     print("j = %d",j);
    //     scanf("%c", &in_order[j]);
    // }
    // printf("enter seven elements for preorder\n");
    // for (j = 0; j < 7; j++)
    // {
    //     scanf("%c", &pre_order[j]);
    // }
    make_tree(i, 0, 6);
    return 0;
}