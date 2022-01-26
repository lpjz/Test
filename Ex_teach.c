#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct headnode{
	int count;
	struct datanode *front;
	struct datanode *rear;
};

struct datanode{
	int data;
	struct datanode *link;
};

void EnQ(int x, struct headnode *list){
     struct datanode* newNode;
     newNode = (struct datanode*)malloc(sizeof(struct datanode));
     newNode->link = NULL;
     newNode->data = x;
     if(list->count==0){
         list->front=newNode;
         list->rear=newNode;
         list->count++;
     }
     else{
         list->rear->link=newNode; 
         list->rear=newNode;
         list->count++;
     }    
}
void DeQ(struct headnode *list){
     if(list->front==NULL)
         printf(" Queue is Empty\n");
     else {
         struct datanode* temp;
         temp = list->front;
         list->front = list->front->link;
         free(temp);
         list->count--;
     }
}
int main() {
	struct headnode *pList;
	pList=(struct headnode*)malloc(sizeof(struct headnode));
	pList->count=0;
	pList->front=NULL;
	pList->rear=NULL;
    
    EnQ(39,pList);
    EnQ(52,pList);
	printf("front = %d\n",pList->front->data);
	printf("rear = %d\n",pList->rear->data);
    printf("head->%d->%d\n",pList->front->data,pList->front->link->data);

	printf("count=%d\n",pList->count);
	DeQ(pList);
	//DeQ(pList);
	//DeQ(pList);
	printf("\n\n\ncount=%d\n",pList->count);
	printf("front = %d\n",pList->front->data);
	printf("rear = %d\n",pList->rear->data);
	
	return 0;
}
