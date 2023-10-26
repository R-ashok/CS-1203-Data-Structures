#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define BADVAL -9999

struct stack {
    int sp;
    int arr[SIZE];
};
typedef struct stack STACK;

void init(STACK *s) {
    s->sp = -1;
}

int isEmpty(STACK *s) {
    if (s->sp == -1)
        return 1;
    else
        return 0;
}

int isFull(STACK *s) {
    if (s->sp == SIZE - 1)
        return 1;
    else
        return 0;
}

int top(STACK *s) {
    if (isEmpty(s))
        return BADVAL;
    else
        return (s->arr[s->sp]);
}

int pop(STACK *s) {
    if (isEmpty(s))
        return BADVAL;
    else
        return (s->arr[(s->sp)--]);
}

int push(STACK *s, int elm) {
    if (isFull(s))
        return 0;
    else {
        s->arr[++(s->sp)] = elm;
        return 1;
    }
}

void printStack(STACK *s) {
    int i;
    if (isEmpty(s)) {
        printf("Stack empty\n");
        return;
    }
    for (i = s->sp; i >= 0; i--)
        printf("%d\n", s->arr[i]);
}

//recursive method

void fun(int n, STACK *a, STACK *b, STACK *c) {
      //We can think of moving a tower from a to c, by first moving the top n-1 elements of a to our supporting tower b. After which we can move our base to c and then reconstruct our n-1 element tower from b to c using a. If we follow this rule we will never violate the tower of Hanoi property of putting a base element above one smaller than it.
    
    if (n == 1) { //terminating condition of the recursion or the base case where we transfer our maximal element to our answer as we keep siphoning through our (n-1),(n-2)...1 stacks.
         int ele = pop(a);
         push(c, ele);
        return;
    }
    else {fun(n-1, a,c,b);//n-1 elements shifted to b using c

    int base = pop(a);
    push(c, base);
    //nth element shifted from a to c.
  
    fun(n-1,b,a,c);}
   //the n-1 elements that we had stored in b then get transfered back to c using a. 
    
}

void Hanoi(int n){
    STACK a,b,c;
    init(&a);
    init(&b);
    init(&c);
    
    for (int i = n; i > 0; i--) {
        push(&a, i);
    }
    //making initial stack
    fun(n,&a,&b,&c);
    
    printf("Final stack output:\n");
    printStack(&c);
    //printing final version of the output stack.
}

int main() {

    Hanoi(20);
//final tower displayed.
    return 0;
}
