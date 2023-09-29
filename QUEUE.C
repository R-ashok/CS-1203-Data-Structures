#include <stdio.h>
#include <stdlib.h>

#define BADVAL -9999999

struct node{
int info;
struct node *next;
};
typedef struct node * NODEPTR;

typedef struct queue {
 struct node *start;
 struct node *end;
};

void init(struct queue *q){
    q->end=NULL;
    q->start=NULL;
}

int isempty(struct queue *q) {
    if (q->start==NULL) {
        return 1;
    }
    else {
        return 0;
}
}

int delet(struct queue *q){
    int val;
    
    if (isempty(q)){
         return BADVAL;
    }
    else {
        val=q->start->info;
        
        struct node *p = q->end;
        while (p->next != q->start){
            p=p->next;
        }
        p->next=NULL;
        q->start=p;
        
        return val;
    }
}

void insert (struct queue *q,int i){
    int val;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->info=i;
    if (isempty(q)) {
        q->start=p;
        q->end=p;
    }
    else {
        p->next=(q->end);
        q->end=p;
}}

void printQ(struct queue *q){
    struct node *p = q->end;
    if (isempty(q)) {
        printf("The Queue is empty!\n");
    } 
    else 
    printf("E->");
    
    for (p=q->end; p != NULL; p=p->next){
    printf("%d ", p->info);
   } printf("<-F \n");
}



int main() {
    struct queue q;
    init(&q);

    while (1) {
        int menu;
        printf("Choose your option: \n 0. Initialize, \n 1. Insert, \n 2. Delete, \n 3. Print, \n 4. Exit\n");

        scanf("%d", &menu);

        switch (menu) {
            case 0:
                init(&q);
                break;

            case 1:
                printf("Give element: ");
                int i;
                scanf("%d", &i);
                insert(&q, i); 
                break;

            case 2:
                printf("Popped Value %d\n", delet(&q));
                break;

            case 3:
                printQ(&q); 
                break;

            case 4:
                exit(0); 
                break;

            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}

