#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define cbSize 16

typedef struct node {
 struct node *next;
  int value;
} cb;

cb *append() { 
  cb *node = malloc(sizeof(cb));
  node->next = NULL;
  return node;
}

int main() {
  cb *head;
  cb *prev;
  cb *node;
  
  for (int i=0; i < cbSize; i++) {
    node = append();
    node->value = i;
    if (i == 0) {
      prev = node;
      head = node;
      continue;
    }
    prev->next = node;
    prev = node;
    if (i == cbSize - 1) {
      node->next = head;
    }
  }

  node = head;
  while (head->next != NULL) {
    printf("%p\n", node);
    sleep(1);
    node = node->next;
  }

  //while ( node->next != NULL ) {
  //  printf("node: %d\ni'm address: %p\nmy next is %p\n\n", node->value, node, node->next);
  //  node = node->next;
  //  sleep(5);
  //}
}
