#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* link;
};

struct node* START;

void display(){
  struct node* WALKER;
  WALKER = START;
  while(WALKER != NULL){
    printf("%d\t",WALKER -> data);
    WALKER = WALKER -> link;
  }
  printf("\n");
}

void insertion(struct node* cur,struct node* pre){
  printf("\nEnter value: ");
  scanf("%d",&(cur -> data));
  if (START == NULL){
    START = cur;
  }else{
  pre ->link = cur;
  }
  cur -> link = NULL;
}

void main(){
  struct node n1,n2,n3,n4,n5;
  START = NULL;
  insertion(&n1,NULL);
  // printf("%p",START);
  display();
  insertion(&n2,&n1);
  display();
  insertion(&n3,&n2);
  display();
  insertion(&n4,&n3);
  display();
  insertion(&n5,&n4);
  display();
}
