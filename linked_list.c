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

void insert(struct node* target_pointer){
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

void delete(struct node* target_pointer){
  struct node* pre;
  struct node* cur;
  bool flag;
  flag = false;
  pre = NULL;
  cur = START;
  while(cur != NULL){
    if(target_pointer -> data == cur -> data){
      if(pre == NULL)
        START = cur -> link;
      else
        pre -> link = cur -> link;
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
  if (flag == false)
    printf("Required Target not found");
  else
    printf("\nNumber deleted\nList becomes\n");
}

void main(){
  struct node n1,n2,n3,n4,n5;
  START = NULL;
  insert(&n1);
  display();
  insert(&n2);
  display();
  insert(&n3);
  display();
  delete(&n2);
  display();
  insert(&n4);
  display();
  insert(&n5);
  display();
}
