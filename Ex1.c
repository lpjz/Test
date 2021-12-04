#include <stdio.h>
#include <stdlib.h>

struct headnode{
    int count;
    struct datanode *head;
};
struct datanode{
    int data;
    struct datanode *link;
};
void add(struct headnode *list, int datao){
    struct datanode link;
    if(list -> head == NULL){
        struct datanode *newdata = malloc(sizeof(struct datanode));
        newdata->data = datao;
        newdata->link = NULL;
        list->count++ ;
        list->head = newdata;
    }
    else if(list->count == 1){
        struct datanode *newdata = malloc(sizeof(struct datanode));
        list->head->link = newdata;
        newdata->data = datao;
        newdata->link = NULL;
        list->count++ ;
    }
    else{
        struct datanode *current = list->head;
        struct datanode *previous ;
        for(int i = 0; i <= (list->count)-1; i++){
            previous = current;
            current = current->link;
        }
        struct datanode *newdata = malloc(sizeof(struct datanode));
        previous -> link = newdata;
        newdata->data = datao;
        newdata->link = NULL;
        list->count++ ;
    };
};
void printList(struct headnode *list){
    struct datanode *current = list->head;
    for(int i = 0; i <= (list->count)-1; i++){
        printf("%d\n", current->data);
        current = current->link;
    };
}
int main() {
    struct headnode *pList;
    pList = malloc(sizeof(struct headnode));
    pList -> count=0;
    pList -> head=NULL;
    add(pList, 1);
    add(pList, 2);
    add(pList, 3);
    add(pList, 4);
    add(pList, 5);
    printList(pList);
    return 0;
}
