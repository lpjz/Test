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
void datalist(struct headnode *pList,int x){
    if(x==1){
    struct datanode *data1;
	data1=(struct datanode*)malloc(sizeof(struct datanode));
	data1->data=5;
	data1->link=pList->head;
	pList->head=data1;
    }
    if(x==2){
	struct datanode *data2;
	data2=(struct datanode*)malloc(sizeof(struct datanode));
	data2->data=7;
	data2->link=pList->head;
	pList->head=data2;
    }
    if(x==3){ 
	struct datanode *data3;
	data3=(struct datanode*)malloc(sizeof(struct datanode));
	data3->data=6;
	data3->link=pList->head;
	pList->head=data3;
}
}
int main() {
	struct headnode *pList;
	pList=(struct headnode*)malloc(sizeof(struct headnode));
	pList->count=0;
	pList->head=NULL;

	datalist(pList,2);
	pList->count=pList->count+1;
	datalist(pList,3);
    pList->count=pList->count+1;
    datalist(pList,1);
    pList->count=pList->count+1;

	printf("%d\n",pList->head->data);
	printf("%d\n",pList->head->link->data);
	printf("%d\n",pList->head->link->link->data);
	printf("count=%d",pList->count);
	return 0;
}
