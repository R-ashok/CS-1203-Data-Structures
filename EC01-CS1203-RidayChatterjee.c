#include <stdio.h>

//implementation of Jhonson and Trotter algorithm which i found online.

int fact(int n){
    if(n==0){
        return 1;
    }
    else{
        int i;
        int j=1;
        for(i=1;i<=n;i++){
            j=j*i;
        }
        return j;
    }
}

void swap(int a[], int o, int p) {
    int temp = a[o];
    a[o] = a[p];
    a[p] = temp;
}


int findB(int a[], int n, int biggest){
    int i;
    for (i =0; i< n; i++){
     if (a[i] == biggest){
	  return i; 
     }
    }
    return 0;
}


//largest integer that can move
int larmov(int a[],int move[],int n){
    int i;
    int biggest=0;
    int track=0;
    for(i=0;i<n;i++){
        if(move[a[i]-1]==1 && i != n-1 && a[i]>a[i+1] && a[i]>biggest){
            biggest=a[i];
            track=1;
        }
        if(move[a[i]-1]==-1 && i != 0 && a[i]>a[i-1] && a[i]>biggest){
            biggest=a[i];
            track=1;
        }
    }
    if(track && biggest != 0){
        return biggest;
    }
    return 0;//nothing left to move
}

//direction change
void DC(int a[], int move[], int biggest, int n){
    int i;
    for(i=0;i<n;i++){
        if(a[i]<biggest){
            if(move[a[i]-1]==1){
                move[a[i]-1]=-1;}
                else{
                   move[a[i]-1]=1; 
                }
        }
    }}

//swap that needs to be performed
void Swap(int a[], int move[], int biggest, int n){
    int i=findB(a,n,biggest);
    if (move[i]== 1){
		swap(a,i,i+1);
    }
    if (move[i]== -1){
		swap(a,i,i-1);
    }
}

void Update(int a[],int move[],int biggest,int n){
DC(a,move,biggest,n);
    Swap(a,move,biggest,n);
    
    return a;}
    


void result(int n) {
    int a[n];
    int move[n];
    int j=0;
    int k,i;

    for (k = 0; k < n; k++) {
        move[k] = -1;//every element is pointing back
        a[k] = k+1;
    }//initialisation 
    
while(j<fact(n)){
        for (i = 0; i < n; i++) {
            printf("%d", a[i]);
            if(i+1!=n){
             printf(",");
        }
        }
        printf("\n");
        int biggest = larmov(a, move, n);
            Update(a,move,biggest,n);
        j++;
    }
}



int main() {
    int n=3;
    if(n==0){
        printf("1") ;
    }
    result(n);
    
}