
#include <stdio.h>
#include <stdlib.h>

#define t 3

struct node {
    int data[2 * t - 1];
    struct node *links[2 * t];
};

struct node *populatenode(){
    struct node *K = (struct node *)malloc(sizeof(struct node));
    
    K->data[0]=20;
    K->data[1]=30;
    K->data[2]=48;
    K->data[3]=70;

    for (int i=0; i<2*t;i++) {
        K->links[i] = NULL;
        if (i>3){
            K->data[i] =0;}
    }

    K->links[2 * t] = NULL;
    return K;
}

struct node *getNode(){
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    for (int i = 0; i < 2 * t; i++) {
        temp->data[i] = 0;
        temp->links[i] = NULL;
    }
    temp->links[2 * t] = NULL;
    return temp;
}

void printNode(struct node *H) {
    printf("Data:\n");
    for (int i = 0;i<2*t-1 && H->data[i]!=NULL; i++) {
        printf("%d ",H->data[i]);
    }

    printf("\n\nLinks:\n");
    for (int i=0;i<2*t && H->links[i]!=NULL;i++) {
        printf("%p ",H->links[i]);
    }
    printf("\n");
}

void insertVal2Node(int d, struct node *C) {
    int i;
    if (C->data[2*t-1]!=NULL) {
        printf("Node already full.\n");
        return;
    }
    for (i=2*t-1; i>=0 &&(C->data[i]==0 || d<=C->data[i]);i--) {
        C->data[i+1]= C->data[i];
    }
    C->data[i+1]=d;
}



struct node* insertVal2NodeBreak(int d, struct node *C) {
    int i, j, k, m, n, o;


    if (C->data[2*t-1]!=0) {
        struct node *Pi = (struct node *)malloc(sizeof(struct node));
        struct node *Le = (struct node *)malloc(sizeof(struct node));
        struct node *Ri = (struct node *)malloc(sizeof(struct node));

        Pi->links[0] = Le;
        Pi->links[2*t-1] = Ri;

        if (d < C->data[t - 1]) {
            Pi->data[0] = C->data[t - 1];
            for (j = 0; j < t - 1; j++) {
                Ri->data[j] = C->data[t+j];
            }
            for (k = 0; k < t - 1; k++) {
                Le->data[k] = C->data[k];
            }
            insertVal2Node(d, Le);
        } else if (d > C->data[t]) {
            Pi->data[0] = C->data[t];
            for (m = 0; m < t; m++) {
                Le->data[m] = C->data[m];
            }
            for (j = 0; j < t - 1; j++) {
                Ri->data[j] = C->data[t + 1 + j];
            }
            insertVal2Node(d, Ri);
        } else {
            Pi->data[0]=d;
            for (n=0;n<t; n++) {
                Le->data[n]=C->data[n];
            }
            for (o=0;o<t-1;o++) {
                Ri->data[o]=C->data[t + o];
            }
        }
        return Pi;
    }
    for(i= 2*t-1; i>= 0 && (C->data[i]==0 || d<=C->data[i]); i--) {
        C->data[i+1] =C->data[i];
    }
    C->data[i+1]=d;

    return C;
}



void search(int g,struct node *root){
    for (int i=0;i<2*t;i++){
        if (g==root->data[i]){
            return 1;}
            else if(g<root->data[i]){
                search(g,root->links[i]);
            }
    }
    else if (g>root->data[2*t-2] && root->data[2*t-2]!=NULL){
        search(g,links[2*t-1])}
 return 0;
}








int main() {
    printf("Name: Riday Chatterjee\nCourse Name: Data Structures (CS-1203)\nYear: 2nd year (UG25)\nRoll number: 1020221098\nEmail: riday.chatterjee_ug25@ashoka\nPhone Number: 9108296187\n\n\n");

struct node *L=populatenode();
printNode(L);

int p= 52,g=64;
insertVal2Node(p, L);
printf("\nAfter Inserting %d:\n", p);
printNode(L);
insertVal2NodeBreak(g,L);



return 0;
}
