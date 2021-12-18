//กิจติพงษ์  วงษ์โสภา 64243206025-8
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
                temp1->link = NULL;
                free(temp2);
            }
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
void printList(struct headnode *list)
            {
                struct datanode *current = list->head;
                for (int i = 0; i <= (list->count) - 1; i++)
                {
                    printf("%d\n", current->data);
                    current = current->link;
                };
            };
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
                printList(pList);
                printf("count=%d", pList->count);

                return 0;
            }
