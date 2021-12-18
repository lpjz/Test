#include <stdio.h>
#include <stdlib.h>

struct headnode
{
    int count;
    struct datanode *head;
};
struct datanode
{
    int data;
    struct datanode *link;
};
void Deletenode(struct headnode *plist)
{
    if (plist->head == NULL)
        printf("List is Empty\n");
    else
    {
        struct datanode *temp;
        temp = plist->head;
        plist->head = temp->link;
        free(temp);
        plist->count = plist->count - 1;
    }
}
void Deletelastnode(struct headnode *plist)
{
    if (plist->head == NULL)
        printf("List is Empty\n");
    else
    {
        struct datanode *temp1, *temp2;
        temp1 = plist->head;
        if (temp1->link == NULL)
        {
            plist->head = NULL;
            free(temp1);
            plist->count = plist->count - 1;
        }
        else
        {
            for (int i = 1; i > plist->count - 1; i++)
            {
                temp1 = temp1->link;
                temp2 = temp1->link;
                temp1->link = NULL; // temp1->link=temp2->link;
                free(temp2);

                // plist->count = plist->count-1;
            }
            plist->count = plist->count - 1;
        }
    }
}
void Deleteatlast(struct headnode *plist)
{
        struct headnode *temp1 = plist->head;
        struct headnode *temp2 = plist->head->link;
        while (temp2->link == NULL)
        {
            temp1 = temp1->link;
            temp2 = temp2->link;
        }

        temp1->link = NULL;
        free(temp2);
}
void InsertEnd(int b, struct headnode *ilist)
{
    struct datanode *newNode;
    newNode = (struct datanode *)malloc(sizeof(struct datanode));
    newNode->link = NULL;
    newNode->data = b;
    if (ilist->head == NULL)
    {
        ilist->head = newNode;
        ilist->count++;
    }

    else
    {
        struct datanode *temp;
        temp = ilist->head;

        /*while(temp->link!=NULL){
            temp=temp->link;
        }*/
        for (int i = 1; i < ilist->count; i++)
        {
            temp = temp->link;
        }

        temp->link = newNode;
        ilist->count++;
    }
}

int main()
{
    struct headnode *pList;
    pList = (struct headnode *)malloc(sizeof(struct headnode));
    pList->count = 0;
    pList->head = NULL;

    InsertEnd(39, pList);
    InsertEnd(52, pList);
    // InsertEnd(99,pList);
    // InsertEnd(1,pList);
    // InsertEnd(2,pList);
    // InsertEnd(3,pList);

    Deletelastnode(pList);

    printf("%d\n", pList->head->data);
    printf("%d\n", pList->head->link->data);
    // printf("%d\n",pList->head->link->link->data);
    //  printf("%d\n",pList->head->link->link->link->data);
    //  printf("%d\n",pList->head->link->link->link->link->data);
    // printf("%d\n",pList->head->link->link->link->link->link->data);
    printf("count=%d", pList->count);

    return 0;
}
