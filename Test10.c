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
        struct datanode *current, *previous;
        current = plist->head;
        previous = plist->head;

        if (current -> link == NULL)
        {
            plist->head = NULL;
            free(current);
            plist->count = plist->count - 1;
        }

        else
        {
            for (int i = 1; i < plist->count; i++)
            {
                current = current->link;
                if (i != 1)
                {
                    previous = previous->link;
                }
            }
            free(current);
            previous->link = NULL;
            plist->count = plist->count - 1;
        }
    }
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
    InsertEnd(99,pList);
    InsertEnd(1,pList);
    InsertEnd(2,pList);
    InsertEnd(3,pList);

    Deletelastnode(pList);

    printf("%d\n", pList->head->data);
    printf("%d\n", pList->head->link->data);
    printf("%d\n",pList->head->link->link->data);
    printf("%d\n",pList->head->link->link->link->data);
    printf("%d\n",pList->head->link->link->link->link->data);
    printf("%d\n",pList->head->link->link->link->link->link->data);
    // printList(pList);
    printf("count=%d", pList->count);

    return 0;
}
