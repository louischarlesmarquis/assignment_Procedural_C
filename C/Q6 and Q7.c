#include <stdio.hs>
#include <stdlib.hs>

//Q6 and Q7 together

//Making a Node structure
struct Node{
    char data;
    struct Node *next; 
    struct Node *subList; 
};
//printList function
void printList(struct Node *root, int isCDR){
    struct Node *temp=root; 
    printf("("); 
    while(temp!=NULL){ //Goes until the end is reached
    
        if(temp->subList!=NULL){ //if a subList is there we do the following: 
            struct Node *temp2 = temp->subList; 
            printf("("); 
            while(temp2!=NULL){ 
                printf("%c", temp2->data); 
                temp2 = temp2->next; 
            }
            printf(")"); 
        }
        else{  //if subList is not there we do the following
            if(temp==root && isCDR) {} 
            else printf("%c", temp->data); 
        }
        temp = temp->next; 
    }
    printf(")");
}

//function to print CAR of the linked list
void car(struct Node *root){
    printf("\n%c\n",root->data);
}
//function to print CDR of the linked list
void cdr(struct Node *root){
    printList(root, 1); 
}

//function to free up the space of the Linked List
void freeList(struct Node *root){
    struct Node *temp=root; 
    while(temp!=NULL){ //Goes until till the end is reached
        if(temp->subList!=NULL){ //if subList is there we do the following
            struct Node *temp2 = temp->subList; 
            while(temp2!=NULL){ //Goes until the end is reached
                struct Node *t1=temp2; 
                temp2 = temp2->next; 
                free(t1); 
            }
        }
        struct Node *t2 = temp; 
        temp = temp->next; 
        free(t2); 
    }
}

//main function
int main(){
    //Making a LinkedList as per the question using malloc.
    struct Node *root = (struct Node*) malloc(sizeof(struct Node));
    root->data = 'a';
    struct Node *link = (struct Node*) malloc(sizeof(struct Node));
    root->next = link;
    link->subList = (struct Node*) malloc(sizeof(struct Node));
    link->subList->data = 'b';
    link->subList->next = (struct Node*) malloc(sizeof(struct Node));
    link->subList->next->data = 'c';
    link->next = (struct Node*) malloc(sizeof(struct Node));
    link->next->data = 'd';
    link->next->next = (struct Node*) malloc(sizeof(struct Node));
    link->next->next->data = 'e';
    
    //Print List
    printList(root, 0);
    //Print CAR
    car(root);
    //Print CDR
    cdr(root);
    //Free up the space
    freeList(root);
}