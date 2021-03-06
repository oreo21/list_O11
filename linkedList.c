#include <stdio.h>
#include <stdlib.h>

struct node { int val; struct node *next; };

void print_list(struct node *start){
  printf("%d -> ", start->val);
  if (start -> next != 0) print_list(start -> next);
  else printf("(nil)\n");
}

struct node* insert_front(struct node *list, int front){
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode -> val = front;
  newNode -> next = list;
  return newNode;
}

struct node* free_list(struct node *list){
  struct node *current;
  while (list){
    current = list;
    list = list -> next;
    free (current);
  }
  free (list);
  return list;
}

int main(){
  struct node *node1 = (struct node *)malloc(sizeof(struct node));
  struct node *node2 = (struct node *)malloc(sizeof(struct node));
  struct node *node3 = (struct node *)malloc(sizeof(struct node));
  struct node *node4 = (struct node *)malloc(sizeof(struct node));

  node1 -> val = 1;
  node1 -> next = node2;
  node2 -> val = 2;
  node2 -> next = node3;
  node3 -> val = 3;
  node3 -> next = node4;
  node4 -> val = 4;
  node4 -> next = NULL;

  struct node *list = node1;
  printf("world's shortest linked list function test\n\n");
  printf("print_list(list): ");
  print_list(list);
  printf("insert_front(list, 5): ");
  print_list(insert_front(list, 5)); // list = insert_front(list, i);
  printf("free_list(list): ");
  free_list(list);
  print_list(list);

  return 0;
}
