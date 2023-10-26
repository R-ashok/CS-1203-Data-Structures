#include <stdio.h>  
#include <stdlib.h>  
   
struct Node  
{  
    int key;  
    struct Node *left;  
    struct Node *right;  
    int height;  
};  
   

struct Node *createNode(int key){  
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));  
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;  
    return node;  
}  

void displayTree(struct Node* root, int space)
{
    int i;

    if (root == NULL) return;

    space += 10;

    // Process right child first
    displayTree(root->right, space);

    // Print current node after space count
    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    displayTree(root->left, space);
}
   
int max (int a, int b){  
    return (a>b)?a:b;  
}  

int makeheight(struct Node *n){  
    if(n==NULL)  
        return 0;  
    else{n->height=1+max(makeheight(n->left),makeheight(n->right));}
    return n->height;
}  

int getHeight(struct Node *n){  
    if(n==NULL)  
        return 0;  
    return n->height;  
}  
   

   
int getBalanceFactor(struct Node * n){  
    if(n==NULL){  
        return 0;  
    }  
    return getHeight(n->left) - getHeight(n->right);  
}  

struct Node* Search(struct Node* G,int k){
    if(G=NULL)
    return NULL;
    if(k=G->key)
    return G;
    if(k<G->key)
        Search(G->left,k);
        if(k>G->key)
        Search(G->right,k);
}

   
struct Node* rightRotate(struct Node* y){  
    struct Node* x = y->left;  
    struct Node* T2 = x->right;  
   
    x->right = y;  
    y->left = T2;  
   
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
   
    return x;  
}  
   
struct Node* leftRotate(struct Node* x){  
    struct Node* y = x->right;  
    struct Node* T2 = y->left;  
   
    y->left = x;  
    x->right = T2;  
   
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
   
    return y;  
}  
   
struct Node *insert(struct Node* node, int key){  
    if (node == NULL)  
        return  createNode(key);  
   
    if (key < node->key)  
        node->left  = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
   
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));  
    int bf = getBalanceFactor(node);  
   
    // Left Left Case  
        if(bf>1 && key < node->left->key){  
            return rightRotate(node);  
        }  
    // Right Right Case  
        if(bf<-1 && key > node->right->key){  
            return leftRotate(node);  
        }  
    // Left Right Case  
    if(bf>1 && key > node->left->key){  
            node->left = leftRotate(node->left);  
            return rightRotate(node);  
        }  
    // Right Left Case  
    if(bf<-1 && key < node->right->key){  
            node->right = rightRotate(node->right);  
            return leftRotate(node);  
        }  
    return node;  
}  
   
void preOrder(struct Node *root)  
{  
    if(root != NULL)  
    {  
        printf("(%d,%d) ", root->key,getBalanceFactor(root));  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  

void inOrder(struct Node *root)  
{  
    if(root != NULL)  
    {  
        preOrder(root->left);  
        printf("(%d,%d) ", root->key,getBalanceFactor(root));  
        preOrder(root->right);  
    }  
}  



struct Node * delete (struct Node * anode, int k){
struct Node *temp, *parent, *intemp, *inparent;
int direction, flag = 0, val;
if (anode == NULL){
printf("Tree empty\n");
return NULL;
}
parent = NULL;
temp = anode;
while (temp != NULL){
if (temp->key == k){ flag = 1; break; }
if (k < temp->key){
parent = temp; temp = temp->left;
direction = 0;
}
else{
parent = temp; temp = temp->right;
direction = 1;
}
}
if (flag == 0){
printf("Node not found\n");
return NULL;
}


if ((temp->left == NULL) && (temp->right == NULL)){
if (direction == 0) parent->left = NULL;
else parent->right = NULL;
return temp;
}

if ((temp->left != NULL) && (temp->right == NULL)){
if (parent == NULL){
anode = temp->left;
return temp;
}
if (direction == 0) parent->left = temp->left;
else parent->right = temp->left;
return temp;
}

if ((temp->left == NULL) && (temp->right != NULL)){
if (parent == NULL){
anode = temp->right;
return temp;
}
if (direction == 0) parent->left = temp->right;
else parent->right = temp->right;
return temp;
}

if ((temp->left != NULL) && (temp->right != NULL)){
inparent = temp;
intemp = temp->right;
direction=1;

while(intemp->left != NULL){
inparent = intemp;
intemp = intemp->left;
direction=0;
}

temp->key = intemp->key;

   
   
    if(direction==0){
        if(intemp->right){
            inparent->left=intemp->right;
    }
    else
    inparent->left=NULL;}
    
    if(direction==1){
         if(intemp->right){
            inparent->right=intemp->right;
    }
     else
        inparent->right=NULL;}

}

return intemp;
temp=NULL;
parent=NULL;
intemp=NULL;
inparent=NULL;
return NULL;
}





struct Node *Balance(struct Node *anode){
    makeheight(anode);
    struct Node *P;
    if (anode == NULL) {
        return anode; // Base case: return NULL if the node is NULL
    }
    
    
    
    int bf = getBalanceFactor(anode);  
   
    // Left Left Case  
        if(bf>1){
        if(anode->left->left != NULL){
        P=rightRotate(anode);
        return P;
        } 
        // Left Right Case  
             anode->left = leftRotate(anode->left);  
             
            return rightRotate(anode);
            
            
        }
        
     
    // Right Right Case  
        else if(bf<-1){
            if(anode->right->right !=NULL){
                 P=leftRotate(anode);
                return P;
                }
                //Right Left Case }
         else{anode->right = rightRotate(anode->right);  
          
            return leftRotate(anode);}
            }
            if(anode->left){
    anode->left=Balance(anode->left);}
    if(anode->right){
    anode->right=Balance(anode->right);}
    bf=NULL;
    return anode;
    
}

int check(struct Node *G){
    if(G==NULL)
    return 0;
    if(getBalanceFactor(G)>1 || getBalanceFactor(G)<-1)
    return 1;
    if(check(G->left) || check(G->right))
    return 1;
}


struct Node *Delete(struct Node *anode, int k){
    delete(anode,k);
    while(check(anode))
    anode=Balance(anode);
    return anode;
}


int main(){
struct Node * root = NULL;
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 30);
root = insert(root, 40);
root = insert(root, 50);
root = insert(root, 60);
root = insert(root, 70);
root = insert(root, 80);
root = insert(root, 90);
root = insert(root, 100);

Delete(root,80);
Delete(root,90);
Delete(root,100);

//works in all cases where the rotation is not made on the root node of the programme.

//notations are given with the balance factor for each element.

makeheight(root);
preOrder(root);
printf("\n");
inOrder(root);
printf("\n");
displayTree(root, 10);
return 0;
}