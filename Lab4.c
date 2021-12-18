//กิจติพงษ์  วงษ์โสภา 64243206025-8 วศ.บ.คอมพิวเตอร์(เทียบโอน)
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
        temp2 = plist->head;

        if (temp1->link == NULL)
        {
            plist->head = NULL;
            free(temp1);
            plist->count = plist->count - 1;
        }
        else
        {
            for (int i = 1; i < plist -> count; i++)
            {
                temp1 = temp1->link;
                if (i != 1)
                {
                    temp2 = temp2->link;
                }
            }
            free(temp1);
            temp2->link = NULL;
            plist->count = plist->count - 1;
        }
    }
}
void printList(struct headnode *list)
{
    struct datanode *current = list->head;
    for (int i = 0; i <= (list->count) - 1; i++)
    {
        printf("%d\n", current->data);
        current = current->link;
    };
};
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
    InsertEnd(99, pList);
    InsertEnd(1, pList);
    InsertEnd(2, pList);
    InsertEnd(3, pList);

    Deletelastnode(pList);

    printf("count=%d \n", pList->count);
    printf("%d\n", pList->head->data);
    printf("%d\n", pList->head->link->data);
    printf("%d\n", pList->head->link->link->data);
    printf("%d\n", pList->head->link->link->link->data);
    printf("%d\n", pList->head->link->link->link->link->data);
    printf("%d\n", pList->head->link->link->link->link->link->data);
    /* 0xC0000005 is a code for Access Violation error. 
    It means that your program just tried to read, or write, 
    in a section of memory that it has no access to. Most likely, 
    this happened due to poor usage of pointers.*/

    

    return 0;
}
