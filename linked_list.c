#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

void insertion(struct node* target_pointer){
  bool flag;
  struct node* pre;
  struct node* cur;
  printf("\nEnter value: ");
  scanf("%d",&(target_pointer -> data));
  if (START == NULL){
    START = target_pointer;
    target_pointer -> link = NULL;
  }
  else{
    flag = false;
    pre = NULL;
    cur = START;
    while(cur != NULL){
      if(target_pointer -> data == cur -> data){
        flag = true;
        break;
      }
      else if(target_pointer -> data > cur -> data){
      pre = cur;
      cur = cur -> link;
      }
      else
      break;
    }
    if (flag == true){
      printf("%d is already present in the list\n",target_pointer -> data);
    }
    else{
      if(pre == NULL){
      START = target_pointer;
      target_pointer -> link = cur;
      }
      else{
      pre -> link = target_pointer;
      target_pointer -> link = cur;
      }
    }
  }
}

void main(){
  struct node n1,n2,n3,n4,n5;
  START = NULL;
  insertion(&n1);
  display();
  insertion(&n2);
  display();
  insertion(&n3);
  display();
  insertion(&n4);
  display();
  insertion(&n5);
  display();
}
